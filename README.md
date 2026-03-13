# FITSEC Easter CTF

A fun little Easter-themed PWN CTF challenging you on ROP-based exploits.

This was my first time making pwn challenges and hosting my own CTF, so it was a great learning experience for me.

## Setup
For any challenge you'd like to try, you can enter the challenge directory then run the Docker Compose to start a "remote instance". Feel free to edit the host port to your needs.

For each challenge directory, the file structure follows:
- `compose.yaml` - Docker Compose file for quick container spinup.
- `Dockerfile` - The challenge Docker image
- `flag.txt` - The challenge flag
- `chall` - The compiled challenge binary
- `*.c` - The challenge source code
- `solve.py` - An example solve script for the challenge

## Challenges
### `./chall0/` - Resupply

### `./chall1/` - Broken Shell

### `./chall2/` - Curveillance Drone

### `./chall3/` - Login Attempt

### `./chall4/` - Secure Complex

### `./chall5/` - Leaking Secrets

