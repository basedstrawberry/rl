#ifndef _player_h
#define _player_h

typedef struct {
	int x;
	int y;
	char ch;
} Player;

void drawPlayer(WINDOW *win, Player *p);
void updatePlayer(int i, Player *p);

#endif
