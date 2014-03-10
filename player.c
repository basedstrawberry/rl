#include <ncurses.h>
#include <stdlib.h>
#include "player.h"

void drawPlayer(WINDOW *win,Player *p) {
	mvwaddch(win,p->y,p->x,p->ch);
}
void updatePlayer(int i, Player *p) {
	switch(i) {
		case 97:
			p->x -= 1;
			break;
		case 100:
			p->x += 1;
			break;
		case 119:
			p->y -= 1;
			break;
		case 115:
			p->y += 1;
			break;
	}
}
