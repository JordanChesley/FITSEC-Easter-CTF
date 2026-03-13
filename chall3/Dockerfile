from debian as base

run apt update -y
run apt update -y

run apt install -y socat gcc --fix-missing

# copy ./chall.c /chall
# run gcc -fno-stack-protector -no-pie -o chall chall.c
copy ./chall /chall
run chmod 755 /chall

copy ./flag.txt /flag.txt
run chmod +r /flag.txt

expose 1337

entrypoint ["socat", "-dd", "TCP4-LISTEN:1337,fork,reuseaddr", "EXEC:\"/chall\",pty,echo=0,raw,iexten=0"] 