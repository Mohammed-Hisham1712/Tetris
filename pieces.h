#ifndef _PIECES_H
#define _PIECES_H

#define NUM_OF_PIECES 	2
#define ROTATIONS	4
#define PROWS		4
#define PCOLS		8

typedef const char type_piece[PCOLS];

extern const char tetris[NUM_OF_PIECES][ROTATIONS][PROWS][PCOLS];

enum Pieces{
	PIECE_T,
	PIECE_L,
	PIECE_LM,
	PIECE_I,
	PIECE_N,
	PIECE_NM,
	PIECE_O
};

enum Rotation{
	ROTATION_NORMAL,
	ROTATION_CWISE,
	ROTATION_ANTI_CWISE,
	ROTATION_FLIPPED
};

typedef struct __piece{
	enum Pieces piece;
	int y;
	int x;
	char cols;
}Piece;

Piece get_random_piece(void);

#endif
