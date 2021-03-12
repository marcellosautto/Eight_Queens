#include "eightQueens.h"
#define N 8

eightQueens::eightQueens()
{
	//initialize the grid
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			board[row][col] = 'o';
}

bool eightQueens::mainLoop()
{

	
}

bool eightQueens::solveBoard(int row, int col, int numQueens)
{
	if (numQueens == 0) //if 8 queens are placed, we found a solution
		return true;
	else
	{
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				if (canPlaceQueen(r, c))
				{
					board[r][c] = 'X';
					if (solveBoard(r, c, numQueens-1))
						return true;
				}
			}
		board[row][col] = 'o';
	}

	return false;

}


bool eightQueens::canPlaceQueen(int row, int col)
{
	if (!inSameRow(row) && !inSameCol(col) && !inSameDiagonalLeftToRight(row, col) && !inSameDiagonalRightToLeft(row, col))
		return true;
	else
		return false;
}

bool eightQueens::inSameRow(int row) //checks if the queen is already in the row
{
	for (int col = 0; col < N; col++)
		if (board[row][col] == 'X')
			return true;
	return false;
}

bool eightQueens::inSameCol(int col) //checks if a queen is already in the column
{
	for (int row = 0; row < N; row++)
		if (board[row][col] == 'X')
			return true;
	return false;
}

bool eightQueens::inSameDiagonalLeftToRight(int row, int col)
{
	int r = 0;
	int c = 0;

	while (row - r >= 0 && col - c >= 0) //check upper left diagonal
	{
		if (board[row - r][col - c] == 'X')
			return true;
		r++;
		c++;
	}
	r = c = 0;
	while (row + r < N && col + c < N) //check lower right diagonal
	{
		if (board[row + r][col + c] == 'X')
			return true;
		r++;
		c++;
	}

	return false;
}

bool eightQueens::inSameDiagonalRightToLeft(int row, int col)
{
	int r = 0;
	int c = 0;

	while (row - r >= 0 && col + c < N) //check upper right diagonal
	{
		if (board[row - r][col + c] == 'X')
			return true;
		r++;
		c++;
	}
	r = c = 0;
	while (row + r < N && col - c >= 0) //check lower left diagonal
	{
		if (board[row + r][col - c] == 'X')
			return true;
		r++;
		c++;
	}

	return false;
}


void eightQueens::printSolution() //print out the solved chess board
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << board[row][col] << " ";
		cout << endl << endl;
	}

}

