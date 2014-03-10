#include <ncurses.h>
#include <stdlib.h>
#include <assert.h>
#include "map.h"

Tile *newTile(Tile_t type) {
	Tile *new_tile;
	new_tile = malloc(sizeof(Tile));
	assert(new_tile != NULL);
	new_tile->ch = 46;
	new_tile->walk = TRUE;
	new_tile->warp = -1;
	switch(type) {
		case GROUND:
			new_tile->ch = 46;
			new_tile->walk = TRUE;
			new_tile->warp = -1;
		case WALL:
			new_tile->ch = 35;
			new_tile->walk = FALSE;
			new_tile->warp = -1;
		case USTAIRS:
			new_tile->ch = 55;
			new_tile->walk = TRUE;
			new_tile->warp = 1;
		case DSTAIRS:
			new_tile->ch = 55;
			new_tile->walk = TRUE;
			new_tile->warp = 2;		
	}
	return new_tile;
}

Map *generateMap() {
	Map *local_map = malloc(sizeof(Tile));
	int x;
	int y;
	for(y=0;y<=16;y++) {
		for(x=0;x<=58;x++) {
			local_map->grid[y][x] = malloc(sizeof(Tile));
			local_map->grid[y][x]->ch = 46;
			local_map->grid[y][x]->walk = TRUE;
			local_map->grid[y][x]->warp = -1;
		}
	}
	return local_map;
}

void destroyMap(Map *m) {
	int x;
	int y;
	for(y=0;y<=16;y++) {
		for(x=0;x<=58;x++) {
			free(m->grid[y][x]);
		}
	}
	free(m);
}
