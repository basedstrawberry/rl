#include <ncurses.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include "rl.h"
#include "msg.h"
#include "map.h"
#include "player.h"


int main() {

	int input;
	PLAYING = TRUE;
	int LEVEL = 0;
	Player *player = initPlayer("Michael");
	// initialize curses	
	initscr();
	cbreak();
	noecho();
	refresh();
	curs_set(0);
	// initialize game 
	WINDOW *msgwin = create_newwin(6,80,18,0);
	WINDOW *statwin = create_newwin(18,20,0,60);
	WINDOW *gamewin = create_newwin(18,60,0,0);



	Dungeon *dungeon = generateDungeon();


	msg_array[0] = " ";
	msg_array[1] = " ";
	msg_array[2] = " ";
	msg_array[3] = " ";
	msg_push("Welcome to rl!");
	do {
		// DRAW
		wclear(gamewin);
		box(gamewin, 0, 0);
		drawMap(gamewin, dungeon->floor[LEVEL]);
		drawPlayer(gamewin, player);
		msg_print(msgwin);
		stats_print(statwin, player);




		wrefresh(msgwin);
		wrefresh(statwin);
		wrefresh(gamewin);
		// UPDATE
		input = takeInput();
		updatePlayer(input, player, dungeon->floor[LEVEL]);

		
	} while(PLAYING);


	// destroy game
	destroyDungeon(dungeon);
	destroy_win(gamewin);
	destroy_win(statwin);
	destroy_win(msgwin);
	// destroy curses
	endwin();
	free(player);
	return 0;


}



int takeInput() {
	int i = getch();
	switch(i) {
		
		case 113:
			PLAYING = FALSE;
			break;
	}
	return i;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
	WINDOW *local_win;
	local_win = newwin(height,width,starty,startx);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return local_win;
}

void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
	wrefresh(local_win);
	delwin(local_win);
}





