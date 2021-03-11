#include "eightQueens.h"

eightQueens::eightQueens()
{
	//initialize the grid
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			board[row][col] = 177;

	queenCount = 0;
}

bool eightQueens::solveBoard(int row, int col, char queen)
{
	if (queenCount == 8) //if 8 queens are placed, we found a solution
		return true;
		

	if (col > 8) //go to the next row
	{
		col = 0;
		row++;
	}
	
	if (canPlaceQueen(row, col, queen)) //if a queen isnt in the same row, col, or diagonal, place a queen
	{
		queenCount++;
		board[row][col] = queen;
		return solveBoard(row + 1, 0, queen);
	}

	else if (!canPlaceQueen(row, col, queen) && col == 7) //if we reach a dead end, backtrack
	{
		queenCount--;
		board[row][col] = 177;
	}
		

	else
		return solveBoard(row, col+1, queen);

}

bool eightQueens::canPlaceQueen(int row, int col, char queen)
{
	if (!inSameRow(row, queen) && !inSameCol(col, queen) && !inSameDiagonalLeftToRight(0, abs(row-col), queen) && !inSameDiagonalRightToLeft(row+col-7, 7, queen))
		return true;
	else
		return false;
}

bool eightQueens::inSameRow(int row, char queen) //checks if the queen is already in the row
{
	for (int col = 0; col < 8; col++)
		if (board[row][col] == queen)
			return true;
	return false;
}

bool eightQueens::inSameCol(int col, char queen) //checks if a queen is already in the column
{
	for (int row = 0; row < 8; row++)
		if (board[row][col] == queen)
			return true;
	return false;
}

bool eightQueens::inSameDiagonalLeftToRight(int row, int col, char queen)
{
	int r = 0;
	int c = 0;

	while (row + r < 8 && col + c < 8) //check diagonal from left to right until we hit the last row or the last column
	{
		if (board[row + r][col + c] == queen)
			return true;
		r++;
		c++;
	}
		
	return false;
}

bool eightQueens::inSameDiagonalRightToLeft(int row, int col, char queen)
{
	int r = 0;
	int c = 0;

	while (row + r < 8 && col - c >= 0) //check diagonal from right to left until either we're at the bottom of the row or at the first column
	{
		if (board[row + r][col - c] == queen)
			return true;
		r++;
		c++;
	}
		
	return false;
}


void eightQueens::printSolution() //print out the solved chess board
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
			cout << board[row][col] << " ";
		cout << endl << endl;
	}

}

