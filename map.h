#ifndef _map_h
#define _map_h

typedef enum {
	GROUND, WALL, DSTAIRS, USTAIRS
} tile_t;


typedef struct {
	char ch;
	bool walk;
	bool warp;
	bool addr;
} tile;

typedef struct floor {
	struct tile *x[16][58];
} floor;

typedef struct Dungeon {
	floor *x[9];
} Dungeon;
tile *newtile(tile_t type);
Dungeon *generateDungeon();
#endif
