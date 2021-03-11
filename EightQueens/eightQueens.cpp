#include "eightQueens.h"

eightQueens::eightQueens()
{
	queenCount = 0;
	//initialize the grid
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			board[row][col] = 177;
}

bool eightQueens::mainLoop() 
{
	solveBoard(0, 0);
	return false;
}

bool eightQueens::solveBoard(int row, int col)
{
	if (queenCount == 8) //if 8 queens are placed, we found a solution
	{
		printSolution();
		return true;
	}
		
	if (col > 8) //go to the next row
	{
		col = 0;
		row++;
	}

	else if (col < 0)
	{
		col = 7;
		row--;
	}
	
	/*
	While (row and col are less than 8)
		{
			if we can place a queen, place it
			if we cant, backtrack to the previous queen, remove it, then try to place another one in the row
		}
	*/
	while (row < 8 && col < 8)
	{
		printSolution();
		cout << "-------------------------------------" << endl;
		Sleep(1000);
		if (canPlaceQueen(row, col)) //if a queen isnt in the same row, col, or diagonal, place a queen
		{
			queenCount++;
			board[row][col] = 'X';
			return solveBoard(row + 1, 0);
		}

		else if (board[row][col] == 'X') { //if we found a previously placed queen, remove it
			queenCount--;
			board[row][col] = 177;
			return solveBoard(row - 1, 7);
		}

		else if(board[row][col] == 177)
			return solveBoard(row, col-1);

		return solveBoard(row, col + 1);
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

