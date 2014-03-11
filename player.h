#ifndef _player_h
#define _player_h
#include "map.h"
typedef struct {
	char *name;
	int x;
	int y;
	char ch;
} Player;

Player *initPlayer(char *name);
void drawPlayer(WINDOW *win, Player *p);
void updatePlayer(int i, Player *p, Map *m);

#endif
