#ifndef NS800_FOC_IPC_H
#define NS800_FOC_IPC_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>

/* Aligned 32-bit loads/stores only: no exclusive retry loops, RT atomics or
 * SEMA in these channels. Shared SRAM must remain non-cacheable/coherent.
 * There is one control-core consumer and one comm-core producer. Multiple
 * comm threads must serialize submission locally before calling offer/stop. */
enum foc_operation { FOC_START = 1, FOC_STOP = 2, FOC_SPEED = 3, FOC_RESET_FAULT = 4 };

struct foc_request
{
    uint32_t operation;
    float rpm;
    float current;
};

struct foc_mailbox
{
    uint32_t offered;
    uint32_t completed;
    uint32_t stop;
    uint32_t stopped;
    struct foc_request request;
};

static inline int foc_mailbox_offer(struct foc_mailbox *box,
                                    const struct foc_request *request)
{
    uint32_t seq = __atomic_load_n(&box->offered, __ATOMIC_RELAXED);
    if (seq != __atomic_load_n(&box->completed, __ATOMIC_ACQUIRE)) return 0;
    box->request = *request;
    __atomic_store_n(&box->offered, seq + 1U, __ATOMIC_RELEASE);
    return 1;
}

static inline int foc_mailbox_peek(struct foc_mailbox *box,
                                   struct foc_request *request, uint32_t *seq)
{
    *seq = __atomic_load_n(&box->offered, __ATOMIC_ACQUIRE);
    if (*seq == __atomic_load_n(&box->completed, __ATOMIC_RELAXED)) return 0;
    *request = box->request;
    return 1;
}

static inline void foc_mailbox_complete(struct foc_mailbox *box, uint32_t seq)
{
    __atomic_store_n(&box->completed, seq, __ATOMIC_RELEASE);
}

static inline void foc_mailbox_stop(struct foc_mailbox *box)
{
    uint32_t seq = __atomic_load_n(&box->stop, __ATOMIC_RELAXED);
    __atomic_store_n(&box->stop, seq + 1U, __ATOMIC_RELEASE);
}

static inline int foc_mailbox_stop_pending(struct foc_mailbox *box)
{
    return __atomic_load_n(&box->stop, __ATOMIC_ACQUIRE) !=
           __atomic_load_n(&box->stopped, __ATOMIC_RELAXED);
}

/* A bounded, word-atomic seqlock. Payload is atomic too, so a failed read is
 * well-defined even if publication overlaps the copy. Never spin in an ISR. */
#define FOC_SNAPSHOT_WORDS 6U
struct foc_snapshot_channel
{
    uint32_t sequence;
    uint32_t words[FOC_SNAPSHOT_WORDS];
};

static inline void foc_snapshot_publish(struct foc_snapshot_channel *channel,
                                         const void *snapshot, size_t size)
{
    const unsigned char *src = snapshot;
    uint32_t seq = __atomic_load_n(&channel->sequence, __ATOMIC_RELAXED);
    __atomic_store_n(&channel->sequence, seq + 1U, __ATOMIC_RELAXED);
    __atomic_thread_fence(__ATOMIC_SEQ_CST);
    for (size_t i = 0; i < size / sizeof(uint32_t); ++i)
    {
        uint32_t word;
        memcpy(&word, src + i * sizeof(word), sizeof(word));
        __atomic_store_n(&channel->words[i], word, __ATOMIC_RELAXED);
    }
    __atomic_store_n(&channel->sequence, seq + 2U, __ATOMIC_RELEASE);
}

static inline int foc_snapshot_read(const struct foc_snapshot_channel *channel,
                                     void *snapshot, size_t size)
{
    unsigned char *dst = snapshot;
    for (unsigned attempt = 0; attempt < 3U; ++attempt)
    {
        uint32_t seq = __atomic_load_n(&channel->sequence, __ATOMIC_ACQUIRE);
        if (seq & 1U) continue;
        for (size_t i = 0; i < size / sizeof(uint32_t); ++i)
        {
            uint32_t word = __atomic_load_n(&channel->words[i], __ATOMIC_RELAXED);
            memcpy(dst + i * sizeof(word), &word, sizeof(word));
        }
        __atomic_thread_fence(__ATOMIC_SEQ_CST);
        if (seq == __atomic_load_n(&channel->sequence, __ATOMIC_ACQUIRE)) return 1;
    }
    return 0;
}

#endif
