#include "eightQueens.h"

eightQueens::eightQueens()
{
	queenCount = 0;
	//initialize the grid
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			board[row][col] = 'o';
}

bool eightQueens::mainLoop()
{
	solveBoard(0, 0, false);
	return false;
}

bool eightQueens::solveBoard(int row, int col, bool isDeadEnd)
{
	if (queenCount == 8) //if 8 queens are placed, we found a solution
	{
		printSolution();
		return true;
	}

	if (col > 7) //go to the next row
	{
		col = 0;
		row++;
	}

	else if (col < 0)
	{
		col = 7;
		row--;
	}

	while (row < 8 && col < 8)
	{
		printSolution();
		cout << "-------------------------------------" << "row: " << row << " col: " << col << " deadEnd = " << isDeadEnd << endl;
		//Sleep(500);
		if (canPlaceQueen(row, col)) //if a queen isnt in the same row, col, or diagonal, place a queen
		{
			queenCount++;
			board[row][col] = 'X';
			solveBoard(row + 1, 0, false);
		}

		else //if the board spot is empty and we've gone through the entire row, backtrack
		{
			if (board[row][col] == 'X' && findReplacement(row, col + 1)) //if we find a queen while backtracking, remove it and try to place it somewhere else
			{
				solveBoard(row+1, 0, true);
			}
			else {
				queenCount--;
				solveBoard(row - 1, 7, true);
			}

			if (board[row][col] == 'o' && isDeadEnd == true) //if we can't place a queen, the board is empty, and we're at a dead end
				solveBoard(row, col - 1, isDeadEnd);

			else if(!inSameRow(row) && col == 7 && isDeadEnd == false) //if we've searched an entire row and no placements are possible, we hit a dead end and we need to backtrack
				solveBoard(row - 1, 7, true);

		}
		solveBoard(row, col + 1, false); //if we can't place anything and the board is empty, keep looking
	}
	return false;

}

bool eightQueens::findReplacement(int row, int col)
{
	board[row][col] = 'o';
	for(int c = col; c < 7; c++)
		if (canPlaceQueen(row, c))
		{
			board[row][c] = 'X';
			return true;
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
	for (int col = 0; col < 8; col++)
		if (board[row][col] == 'X')
			return true;
	return false;
}

bool eightQueens::inSameCol(int col) //checks if a queen is already in the column
{
	for (int row = 0; row < 8; row++)
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
	while (row + r < 8 && col + c < 8) //check lower right diagonal
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

	while (row - r >= 0 && col + c < 8) //check upper right diagonal
	{
		if (board[row - r][col + c] == 'X')
			return true;
		r++;
		c++;
	}
	r = c = 0;
	while (row + r < 8 && col - c >= 0) //check lower left diagonal
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
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
			cout << board[row][col] << " ";
		cout << endl << endl;
	}

}

