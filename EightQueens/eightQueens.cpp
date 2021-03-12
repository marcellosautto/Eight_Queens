//Name: Marcello Sautto
//Date of Completion: 3/12

#include "eightQueens.h"
#define N 8

eightQueens::eightQueens()
{
	//initialize the grid
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			board[row][col] = 177;
}

bool eightQueens::solveBoard(int row, int col, int numQueens)
{
	if (numQueens == 0) //if N queens are placed, we found a solution
		return true;
	else
	{
		for (int r = 0; r < N; r++)
			for (int c = 0; c < N; c++)
			{
				if (canPlaceQueen(r, c)) //if there isnt a queen in the same row, column or diagonal space, place a queen
				{
					board[r][c] = (char)234;
					if (solveBoard(r, c, numQueens-1)) //recursively backtrack and see if placing a queen in this position leads to the solution
						return true;
				}
			}
		board[row][col] = 177; //when we backtrack to a queen which does not fit the solution, remove the queen
	}

	return false; //begin backtracking

}


bool eightQueens::canPlaceQueen(int row, int col) //checks if there isnt a queen in the same row, column or diagonal space
{
	if (!inSameRow(row) && !inSameCol(col) && !inSameDiagonalLeftToRight(row, col) && !inSameDiagonalRightToLeft(row, col))
		return true;
	else
		return false;
}

bool eightQueens::inSameRow(int row) //checks if the queen is already in the row
{
	for (int col = 0; col < N; col++)
		if (board[row][col] == (char)234)
			return true;
	return false;
}

bool eightQueens::inSameCol(int col) //checks if a queen is already in the column
{
	for (int row = 0; row < N; row++)
		if (board[row][col] == (char)234)
			return true;
	return false;
}

bool eightQueens::inSameDiagonalLeftToRight(int row, int col)
{
	int r = 0;
	int c = 0;

	while (row - r >= 0 && col - c >= 0) //check upper left diagonal
	{
		if (board[row - r][col - c] == (char)234)
			return true;
		r++;
		c++;
	}
	r = c = 0;
	while (row + r < N && col + c < N) //check lower right diagonal
	{
		if (board[row + r][col + c] == (char)234)
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
		if (board[row - r][col + c] == (char)234)
			return true;
		r++;
		c++;
	}
	r = c = 0;
	while (row + r < N && col - c >= 0) //check lower left diagonal
	{
		if (board[row + r][col - c] == (char)234)
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

