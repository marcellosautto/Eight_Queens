#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

class eightQueens
{

public:
	bool mainLoop();
	eightQueens(); //constructor
private:
	//variables
	int queenCount;
	char emptyBoard[8][8];
	//functions
	bool solveBoard(int row, int col, char board[8][8]),
		canPlaceQueen(int row, int col, char board[8][8]),
		inSameRow(int row, char board[8][8]),
		inSameCol(int col, char board[8][8]),
		inSameDiagonalLeftToRight(int row, int col, char board[8][8]),
		inSameDiagonalRightToLeft(int row, int col, char board[8][8]);
	void printSolution(char board[8][8]);
};

