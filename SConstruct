import os
import sys
import rtconfig

if os.getenv('RTT_ROOT'):
    RTT_ROOT = os.getenv('RTT_ROOT')
else:
    RTT_ROOT = os.path.normpath(os.getcwd() + '/../../../..')

# set RTT_ROOT
if not os.getenv("RTT_ROOT"): 
    RTT_ROOT="rt-thread"

sys.path = sys.path + [os.path.join(RTT_ROOT, 'tools')]
try:
    from building import *
except:
    print('Cannot found RT-Thread root directory, please check RTT_ROOT')
    print(RTT_ROOT)
    exit(-1)

def bsp_pkg_check():
    import subprocess

    check_paths = [
        os.path.join("packages", "CMSIS-Core-latest"),
        os.path.join("packages", "novosns-series-latest"),
    ]

    need_update = not all(os.path.exists(p) for p in check_paths)

    if need_update:
        print("\n===============================================================================")
        print("Dependency packages missing, please running 'pkgs --update'...")
        print("If no packages are fetched, run 'pkgs --upgrade' first, then 'pkgs --update'...")
        print("===============================================================================")
        exit(1)

RegisterPreBuildingAction(bsp_pkg_check)

TARGET = 'rtthread.' + rtconfig.TARGET_EXT

DefaultEnvironment(tools=[])
env = Environment(tools = ['mingw'],
    AS = rtconfig.AS, ASFLAGS = rtconfig.AFLAGS,
    CC = rtconfig.CC, CFLAGS = rtconfig.CFLAGS,
    AR = rtconfig.AR, ARFLAGS = '-rc',
    CXX = rtconfig.CXX, CXXFLAGS = rtconfig.CXXFLAGS,
    LINK = rtconfig.LINK, LINKFLAGS = rtconfig.LFLAGS)
env.PrependENVPath('PATH', rtconfig.EXEC_PATH)

if os.name == 'posix':
    # SCons quotes spaces, but leaves parentheses in source/include paths
    # unquoted. The upstream Sguan version directory contains parentheses.
    posix_spawn = env['SPAWN']

    def spawn_quoted_paths(sh, escape, cmd, args, environ):
        args = [escape(arg) if ('(' in arg or ')' in arg) and
                not (arg.startswith(('"', "'")) and arg[-1:] == arg[:1])
                else arg for arg in args]
        return posix_spawn(sh, escape, cmd, args, environ)

    env.Replace(SPAWN=spawn_quoted_paths)

if rtconfig.PLATFORM in ['iccarm']:
    env.Replace(CCCOM = ['$CC $CFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS -o $TARGET $SOURCES'])
    env.Replace(ARFLAGS = [''])
    env.Replace(LINKCOM = env["LINKCOM"] + ' --map rtthread.map')

Export('env')
Export('RTT_ROOT')
Export('rtconfig')

SDK_ROOT = os.path.abspath('./')

if os.path.exists(SDK_ROOT + '/libraries'):
    libraries_path_prefix = SDK_ROOT + '/libraries'
else:
    libraries_path_prefix = os.path.dirname(SDK_ROOT) + '/libraries'

# prepare building environment
objs = PrepareBuilding(env, RTT_ROOT, has_libcpu=True)

if rtconfig.PLATFORM == 'gcc':
    # Keep the BSP's tested reset/vector code outside the disposable packages/.
    # Replace the package source in place, including IDE export metadata, so
    # it is never compiled or linked alongside our startup.
    package_startup = os.path.join(
        SDK_ROOT, 'packages', 'novosns-series-latest', 'NS800RT7XXX',
        'Device', 'Src', 'gcc', 'startup_NS800RT7xxx.S')
    VariantDir('build/board/startup', 'board/startup', duplicate=0)
    bsp_startup = File('build/board/startup/startup_NS800RT7xxx.S')

    def use_bsp_startup(sources):
        for index, source in enumerate(sources):
            if isinstance(source, list):
                use_bsp_startup(source)
            elif source.srcnode().abspath == package_startup:
                sources[index] = bsp_startup

    use_bsp_startup(objs)
    for group in Projects:
        use_bsp_startup(group['src'])

rtconfig.BSP_LIBRARY_TYPE = None

# include drivers
objs.extend(SConscript(os.path.join(libraries_path_prefix, 'HAL_Drivers', 'SConscript'),variant_dir='build/libraries/HAL_Drivers', duplicate=0))

if rtconfig.PLATFORM == 'gcc':
    cpu2_env = env.Clone()
    cpu2_linkflags = rtconfig.LFLAGS.replace('rtthread.map', 'rtthread_cpu2.map')
    cpu2_linkflags = cpu2_linkflags.replace('link.lds', 'link_cpu2.lds')

    cpu2_device_root = os.path.join(
        SDK_ROOT, 'packages', 'novosns-series-latest', 'NS800RT7XXX', 'Device')
    cpu2_sources = [
        bsp_startup.srcnode(),
        os.path.join(cpu2_device_root, 'Src', 'system_NS800RT7xxx.c'),
        os.path.join(SDK_ROOT, 'board', 'smp', 'secondary_boot.c'),
    ]
    cpu2_objects = [
        cpu2_env.Object('build/cpu2/startup_NS800RT7xxx.o', cpu2_sources[0]),
        cpu2_env.Object('build/cpu2/system_NS800RT7xxx.o', cpu2_sources[1]),
        cpu2_env.Object('build/cpu2/secondary_boot.o', cpu2_sources[2]),
    ]
    cpu2_target = cpu2_env.Program('rtthread_cpu2.elf', cpu2_objects,
                                   LINKFLAGS=cpu2_linkflags)
    cpu2_env.AddPostAction(
        cpu2_target,
        rtconfig.OBJCPY + ' -O binary $TARGET rtthread_cpu2.bin\n' +
        rtconfig.SIZE + ' $TARGET\n')
    Default(cpu2_target)

# make a building
DoBuilding(TARGET, objs)
Default(TARGET)
