#ifndef _map_h
#define _map_h

typedef enum {
	GROUND, WALL, DSTAIRS, USTAIRS
} Tile_t;

typedef struct {
	char ch;
	bool walk;
	int warp;
	int x;
	int y;
} Tile;

typedef struct Map {
	Tile grid[16*58+1];
} Map;
/////////////////
Tile newTile(Tile_t type);
Map *generateMap();
void drawMap();
void destroyMap(Map *m);
#endif

