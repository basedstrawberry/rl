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
	switch(i) {
		case 97:
			if((p->y*58)+p->x<=(16*58)-2 && m->grid[((p->y*58)+p->x)-2].walk) {
				p->x -= 1;
			}
			break;
		case 100:
			if((p->y*58)+p->x<=(16*58) && m->grid[((p->y*58)+p->x)].walk) {
				p->x += 1;
			}
			break;
		case 119:
			if((p->y*58)+p->x<=(16*58) && m->grid[((p->y*58)+p->x)].walk) {
				p->y -= 1;
			}
			break;
		case 115:
			p->y += 1;
			break;
	}
}
