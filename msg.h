#ifndef _msg_h
#define _msg_h
#include "player.h"
char *msg_array[3];

void msg_push(char *msg);
void msg_print(WINDOW *win);
void stats_print(WINDOW *win,Player *p);

#endif
