#ifndef _map_h
#define _map_h

typedef enum {
	GROUND, WALL, DSTAIRS, USTAIRS
} Tile_t;

typedef struct {
	char ch;
	bool walk;
	bool visible;
	int warp;
} Tile;

typedef struct Map {
	Tile grid[16*58+1];
} Map;

typedef struct {
	Map *floor[10];
	char *name;
} Dungeon;
/////////////////
Tile newTile(Tile_t type);
Map *generateMap();
Dungeon *generateDungeon();
void drawMap();
void destroyMap(Map *m);
void destroyDungeon(Dungeon *d);
#endif

