-- Real-device regression; stops the motor, then checks 150 native tio commands.
-- Run: tio -b 115200 --script-file tests/console_edit.lua <J-Link CDC device>
local cases = {
  "motor status\r",
  "motor status   \r",
  "motor statux\127s\r",
  "mo\9 status\r",
  "motor statux\23status\r",
  "\27[A\r",
  "motor statux\27[1~\27[4~\127s\r",
  "motor statux\27[H\27[F\127s\r",
  "motor xstatus\27[D\27[D\27[D\27[D\27[D\27[D\27[D\27[3~\r",
  "motor statux\27[1;5D\27[1;5C\127s\r",
  "  motor  status   \r"
}
write("\r")
assert(expect("msh >", 3000) == 1, "initial prompt")
write("motor stop\r")
assert(expect("msh >", 3000) == 1, "stop prompt")
for n=1,10 do
  for i,payload in ipairs(cases) do
    write(payload)
    assert(expect("motor idle fault=none", 3000) == 1, "edit case "..i.." repeat "..n)
    assert(expect("msh >", 3000) == 1, "command prompt")
  end
end
for n=1,10 do
  write("motor status\rmotor status\rmotor status\rmotor status\r")
  for i=1,4 do
    assert(expect("motor idle fault=none", 3000) == 1, "paste command")
    assert(expect("msh >", 3000) == 1, "paste prompt")
  end
end
print("CONSOLE_REGRESSION_PASS 150 native tio commands")
