CFLAGS= -Wall -g -o
LIBS= -lSDL2 -lGLEW -lGLU -lGL

all: main

main: main.c
	gcc ${CFLAGS} $@ $? ${LIBS}

clean:
	rm main
