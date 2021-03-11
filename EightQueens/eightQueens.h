#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class eightQueens
{

public:
	eightQueens(); //constructor
	//variables
	char board[8][8];
	int queenCount;
	//functions
	bool solveBoard(int row, int col, char queen),
		canPlaceQueen(int row, int col, char queen),
		inSameRow(int row, char queen),
		inSameCol(int col, char queen),
		inSameDiagonalLeftToRight(int row, int col, char queen),
		inSameDiagonalRightToLeft(int row, int col, char queen);
	void printSolution();
};

