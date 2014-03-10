#include <ncurses.h>
#include <stdlib.h>
#include <assert.h>
#include "map.h"

Tile newTile(Tile_t type) {
	Tile new_tile;
	new_tile.ch = 46;
	new_tile.walk = TRUE;
	new_tile.warp = -1;
	switch(type) {
		case GROUND:
			new_tile.ch = 46;
			new_tile.walk = TRUE;
			new_tile.warp = -1;
		case WALL:
			new_tile.ch = 35;
			new_tile.walk = FALSE;
			new_tile.warp = -1;
		case USTAIRS:
			new_tile.ch = 46;
			new_tile.walk = TRUE;
			new_tile.warp = 1;
		case DSTAIRS:
			new_tile.ch = 46;
			new_tile.walk = TRUE;
			new_tile.warp = 2;		
	}
	return new_tile;
}

Map *generateMap() {
	int x;
	int y;
	Map *local_map = malloc(sizeof(Map));
	for(y=0;y<=15;y++) {
		for(x=0;x<=57;x++) {
			local_map->grid[(y*58)+x] = newTile(0);
		}
	}
	return local_map;
}

void drawMap(WINDOW *win, Map *m) {
	int x;
	int y;
	for(y=0;y<=15;y++) {
		for(x=0;x<=57;x++) {
			mvwaddch(win,y+1,x+1,m->grid[(y*58)+x].ch);
		}
	}
}

void destroyMap(Map *m) {
	free(m);
}
