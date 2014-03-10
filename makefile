CFLAGS=-c -Wall

all: rl


rl: rl.o player.o msg.o map.o
	gcc rl.o player.o map.o msg.o -lncurses -o rl

rl.o: rl.c rl.h
	gcc $(CFLAGS) rl.c
player.o: player.c player.h
	gcc $(CFLAGS) player.c
msg.o: msg.c msg.h
	gcc $(CFLAGS) msg.c
map.o: map.c map.h
	gcc $(CFLAGS) map.c
clean:
	rm -rf log* *.o rl
