#include <ncurses.h>
#include <stdlib.h>
#include "map.h"

tile *newtile(tile_t type) {
	tile *local_tile;
	switch(type) {
		case GROUND:
			local_tile->ch = 46;
			local_tile->walk = TRUE;
			local_tile->warp = FALSE;
			local_tile->addr = NULL;
			break;
		case WALL:
			local_tile->ch = 35;
			local_tile->walk = FALSE;
			local_tile->warp = FALSE;
			local_tile->addr = NULL;
			break;
		case DSTAIRS:
			local_tile->ch = 66;
			local_tile->walk = TRUE;
			local_tile->warp = TRUE;
			local_tile->addr = TRUE;
			break;
		case USTAIRS:
			local_tile->ch = 67;
			local_tile->walk = TRUE;
			local_tile->warp = TRUE;
			local_tile->addr = FALSE;
			break;
		default:
			local_tile->ch = 46;
			local_tile->walk = TRUE;
			local_tile->warp = FALSE;
			local_tile->addr = NULL;
			break;
	}
	return local_tile;
}



Dungeon *generateDungeon() {
	Dungeon *local_dungeon = malloc(sizeof(Dungeon));
	
	int f;
	int x;
	int y;
	for(f=0;f<=9;f++) {
		//create each floor
		local_dungeon->x[f] = malloc(sizeof(floor));
		for(y=0;y<=16;y++) {
			//create row
			for(x=0;x<=58;x++) {
				//create each tile
				local_dungeon->x[f]->x[y][x] = malloc(sizeof(tile));
				local_dungeon->x[f]->x[y][x] = newtile(GROUND);
			}
		}
	} return local_dungeon;
}
