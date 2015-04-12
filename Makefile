CFLAGS= -Wall -g
DEPS= main.h mesh.h
LIBS= -lSDL2 -lGLEW -lGLU -lGL

all: main

main: main.o mesh.o
	gcc ${CFLAGS} -o $@ $^ ${LIBS}

%.o: %.c ${DEPS}
	gcc ${CFLAGS} -c -o $@ $<

clean:
	rm *.o main
