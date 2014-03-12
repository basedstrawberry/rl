#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

Player *initPlayer(char *name) {
	Player *p = malloc(sizeof(Player));
	p->ch = 64;
	p->x = 3;
	p->y = 3;
	p->name = strdup(name);
	return p;
}

void drawPlayer(WINDOW *win,Player *p) {
	mvwaddch(win,p->y,p->x,p->ch);
}
void updatePlayer(int i, Player *p, Map *m) {
	int X = p->x-1;
	int Y = p->y-1;
	switch(i) {
		case 97:
			if(  (Y*58+(X-1))<=(16*58) && m->grid[Y*58+(X-1)].walk ) {
				p->x -= 1;
			}
			break;
		case 100:
			if(  (Y*58+(X+1))<=(16*58) && m->grid[Y*58+(X+1)].walk ) {
				p->x += 1;
			}
			break;
		case 119:
			if(  ((Y-1)*58+X)<=(16*58) && m->grid[(Y-1)*58+X].walk ) {
				p->y -= 1;
			}
			break;
		case 115:
			if(  ((Y+1)*58+X)<=(16*58) && m->grid[(Y+1)*58+X].walk ) {
				p->y += 1;
			}
			break;
	}
}
