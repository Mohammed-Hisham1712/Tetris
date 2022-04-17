#include <curses.h>
#include "pieces.h"
#include "screen.h"
#include "game.h"


int main(void){

	initscr();

	noecho();
	curs_set(0);
	keypad(stdscr, 1);
	use_default_colors();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_GREEN);
	refresh();

	Window *title_win = create_title_window();
	Window *board_win = create_board_window();

	Piece cur_piece = get_random_piece();
	show_new_piece(&cur_piece);
	print_title(title_win);
	print_board(board_win);

	int key;
	do{
		key = getch();
		switch(key){
			case KEY_DOWN:
				move_piece_down(&cur_piece);
				break;
			case KEY_RIGHT:
				move_piece_right(&cur_piece);
				break;
			case KEY_LEFT:
				move_piece_left(&cur_piece);
				break;
			case ' ':
				cur_piece = get_random_piece();
				show_new_piece(&cur_piece);
				break;
		}
		print_board(board_win);
	}while(key != 'q');
	endwin();
}
