#ifndef _map_h
#define _map_h

typedef enum {
	GROUND, WALL, DSTAIRS, USTAIRS
} Tile_t;

typedef struct {
	char ch;
	bool walk;
	int warp;
} Tile;

typedef struct Map {
	Tile *grid[16][59];
} Map;
/////////////////
Tile *newTile(Tile_t type);
Map *generateMap();
void destroyMap(Map *m);
#endif

