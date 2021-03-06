#include <stdlib.h>
#include "pieces.h"

const char tetris[NUM_OF_PIECES][ROTATIONS][PROWS][PCOLS] = {
	{//T
		{
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0}, 
			{0,0,1,1,1,1,1,1},
			{0,0,0,0,1,1,0,0}},
		{
			{0,0,0,1,0},
			{0,0,1,1,0},
			{0,0,0,1,0},
			{0,0,0,0,0}},
		{
			{0,0,1,0,0},
			{0,1,1,1,0},
			{0,0,0,0,0},
			{0,0,0,0,0}},
		{
			{0,0,0,1,0},
			{0,0,0,1,1},
			{0,0,0,1,0},
			{0,0,0,0,0}}
	},
	{//L
		{
			{0,0,0,0,0,0,0,0},
			{0,0,0,0,2,2,0,0},
			{0,0,0,0,2,2,0,0},
			{0,0,0,0,2,2,2,2}},
		{
			{0,0,0,2,0},
			{0,2,2,2,0},
			{0,0,0,0,0},
			{0,0,0,0,0}},
		{
			{0,2,2,0,0},
			{0,0,2,0,0},
			{0,0,2,0,0},
			{0,0,0,0,0}},
		{
			{0,0,0,0,0},
			{0,2,2,2,0},
			{0,2,0,0,0},
			{0,0,0,0,0}}
	}
};

Piece get_random_piece(void){

	Piece p = {
		.piece = rand() % NUM_OF_PIECES,
		.y = 3,
		.x = 4,
		.cols = PCOLS
	};

	return p;
}

