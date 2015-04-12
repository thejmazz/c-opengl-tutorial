CFLAGS= -Wall -g -o
LIBS= -lSDL2

all: main

main: main.c
	gcc ${CFLAGS} $@ $? ${LIBS}

clean:
	rm main
