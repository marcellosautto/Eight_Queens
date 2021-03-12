#pragma once
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;
#define N 8

class eightQueens
{

public:
	eightQueens(); //constructor

	//member variables
	char board[N][N];

	//functions
	void printSolution();
	bool solveBoard(int row, int col, int numQueens);

private:
	bool canPlaceQueen(int row, int col),
		inSameRow(int row),
		inSameCol(int col),
		inSameDiagonalLeftToRight(int row, int col),
		inSameDiagonalRightToLeft(int row, int col);
	
};

