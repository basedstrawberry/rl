#ifndef _rl_h
#define _rl_h

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);
int takeInput();

bool PLAYING;
#endif
