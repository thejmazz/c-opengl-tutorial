CFLAGS= -Wall -g -o

all: main

main: main.c
	gcc ${CFLAGS} $@ $?

clean:
	rm main
