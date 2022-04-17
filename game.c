#include "pieces.h"
#include "screen.h"
#include "game.h"

void show_new_piece(Piece *p){

	type_piece *piece_ptr = tetris[p->piece][ROTATION_NORMAL];

	for(char i = 0; i < PROWS; i++){
		for(char j = 0; j < PCOLS; j++){
			board[p->y + i][p->x + j] = (*(piece_ptr + i))[j];
		}
	}
}

void move_piece_down(Piece *p){

	int py_end = p->y + PROWS;
	for(char i = 0; i < PROWS; i++){

		for(char j = 0; j < PCOLS; j++){

			if(board[py_end - i - 1][p->x + j] > 0){
				board[py_end - i][p->x + j] = board[py_end - i - 1][p->x + j];
				board[py_end - i - 1][p->x + j] = EMPTY;
			}
		}
	}

	p->y = p->y + 1;
}

void move_piece_right(Piece *p){

	int px_end = p->x + PCOLS;

	for(char i = 0; i < PROWS; i++){

		for(char j = 0; j < PCOLS; j++){

			if(board[p->y + i][px_end - j - 1] > 0){
				board[p->y + i][px_end - j] = board[p->y + i][px_end - j - 1];
				board[p->y + i][px_end - j -1] = EMPTY;
			}
		}
	}

	p->x = p->x + 1;
}

void move_piece_left(Piece *p){

	int px_start = p->x - 1;

	char dec = false;

	for(char j = 0; j < p->cols; j++){

		for(char i = 0; i < PROWS; i++){
			
			if(board[p->y + i][px_start + j + 1] > 0){
				board[p->y + i][px_start + j] = board[p->y + i][px_start + j + 1];
				board[p->y + i][px_start + j + 1] = EMPTY;
			}
		}
	}

	p->x = p->x - 1;
}
