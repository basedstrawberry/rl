#include <ncurses.h>
#include <stdlib.h>
#include "player.h"
#include "msg.h"

void msg_push(char *msg) {
	int i;
	for(i=3;i>=0;i--) {
		if(i==0) {
			msg_array[i] = msg;
		} else {
			msg_array[i] = msg_array[i-1];
		}
	}
}

void msg_print(WINDOW *win) {
	int i;
	for(i=0;i<=4;i++) {
		if(msg_array[i]) 
		mvwprintw(win,4-i,1,msg_array[i]);
	}
}

void stats_print(WINDOW *win,Player *p) {
	mvwprintw(win,1,4,"Welcome to rl");
	mvwprintw(win,4,4,"Health: 100");
	mvwprintw(win,5,4,"Gold: 0gp");
	mvwprintw(win,6,4,"Class: Rogue");

}

