#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

class eightQueens
{

public:
	bool mainLoop();
	eightQueens(); //constructor
private:
	//variables
	int queenCount;
	char board[8][8];
	//functions
	bool solveBoard(int row, int col),
		canPlaceQueen(int row, int col),
		inSameRow(int row),
		inSameCol(int col),
		inSameDiagonalLeftToRight(int row, int col),
		inSameDiagonalRightToLeft(int row, int col);
	void printSolution();
};

