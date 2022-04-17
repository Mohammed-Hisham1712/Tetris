#include <curses.h>
#include <stdlib.h>

#include "screen.h"

#define TITLE_ROWS 5
#define TITLE_COLS 44

static const char TITLE[TITLE_ROWS * TITLE_COLS] =
        "111111  222222  333333  4444444  55  666666\n"
        "  11    22        33    44   44  55  66    \n"
        "  11    22222     33    444444   55  666666\n"
        "  11    22        33    44   44  55      66\n"
        "  11    222222    33    44    44 55  666666\n";



char board[Y][X];

Window* create_title_window(void){

	int y_max, x_max;
	getmaxyx(stdscr, y_max, x_max);
	int y_beg = 1;
	int x_beg = 2;

	WINDOW *curses_win = newwin(TITLE_ROWS, TITLE_COLS, y_beg, x_beg);
	refresh();
	wrefresh(curses_win);

	Window *win = malloc(sizeof(Window));
	win->window = curses_win;
	win->y_beg = y_beg;
	win->x_beg = x_beg;

	return win;
}

Window* create_board_window(void){

	int y_max, x_max;
	getmaxyx(stdscr,y_max, x_max);
	int y_beg = y_max - Y - 3;
	int x_beg = TITLE_COLS + 2;
	WINDOW *curses_win = newwin(Y + 2, X + 2, y_beg, x_beg);
	box(curses_win,0,0);
	refresh();
	wrefresh(curses_win);

	Window *board_win = malloc(sizeof(Window));
	board_win->window = curses_win;
	board_win->y_beg = y_beg + 1;
	board_win->x_beg = x_beg + 1;
	
	return board_win;
}

void print_title(Window* win){

	char pixel;
	for(char i = 0; i < TITLE_ROWS; i++){
		wmove(win->window, i, 0);
		for(char j = 0; j < TITLE_COLS; j++){
			pixel = TITLE[i*TITLE_COLS + j];
			if(pixel == ' ' || pixel == '\n'){
				waddch(win->window, ' ');
			}
			else{
				wattron(win->window, COLOR_PAIR(pixel - '0'));
				waddch(win->window, ' ');
				wattroff(win->window, COLOR_PAIR(pixel - '0'));
			}
		}
	}

	wrefresh(win->window);
}

void print_board(Window* win){

	char pixel;
	for(char i = 0; i < Y; i++){
		wmove(win->window, i + 1, 1);
		for(char j = 0; j < X; j++){
			pixel = board[i][j];
			if(pixel > 0){
				wattron(win->window, COLOR_PAIR(pixel));
				waddch(win->window, ' ');
				wattroff(win->window, COLOR_PAIR(pixel));
			}
			else{
				waddch(win->window, ' ');
			}
		}
	}

	wrefresh(win->window);
}
