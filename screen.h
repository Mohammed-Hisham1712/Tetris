#ifndef _SCREEN_H
#define _SCREEN_H

#include <curses.h>

#define X 	50
#define Y	30
#define EMPTY 	0

extern char board[Y][X];

typedef struct __window{
	WINDOW* window;
	int y_beg;
	int x_beg;
}Window;

Window* create_title_window(void);
Window* create_board_window(void);

void print_title(Window*);
void print_board(Window*);

#endif
