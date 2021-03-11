#include "eightQueens.h"

eightQueens::eightQueens()
{
	queenCount = 0;
	//initialize the grid
	for (int row = 0; row < 8; row++)
		for (int col = 0; col < 8; col++)
			emptyBoard[row][col] = 177;
}

bool eightQueens::mainLoop() 
{
	solveBoard(0, 0, emptyBoard);
	return false;
}

bool eightQueens::solveBoard(int row, int col, char board[8][8])
{
	if (queenCount == 8) //if 8 queens are placed, we found a solution
	{
		printSolution(board);
		return true;
	}
		
	if (col > 8) //go to the next row
	{
		col = 0;
		row++;
	}
	
	if (canPlaceQueen(row, col, board)) //if a queen isnt in the same row, col, or diagonal, place a queen
	{
		queenCount++;
		board[row][col] = 'X';
		return solveBoard(row + 1, 0, board);
	}

	else {
		queenCount--;
		board[row][col] = 177;
	}

	return solveBoard(row, col+1, board);

}

bool eightQueens::canPlaceQueen(int row, int col, char board[8][8])
{
	if (!inSameRow(row, board) && !inSameCol(col, board) && !inSameDiagonalLeftToRight(row, col, board) && !inSameDiagonalRightToLeft(row, col, board))
		return true;
	else
		return false;
}

bool eightQueens::inSameRow(int row, char board[8][8]) //checks if the queen is already in the row
{
	for (int col = 0; col < 8; col++)
		if (board[row][col] == 'X')
			return true;
	return false;
}

bool eightQueens::inSameCol(int col, char board[8][8]) //checks if a queen is already in the column
{
	for (int row = 0; row < 8; row++)
		if (board[row][col] == 'X')
			return true;
	return false;
}

bool eightQueens::inSameDiagonalLeftToRight(int row, int col, char board[8][8])
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

bool eightQueens::inSameDiagonalRightToLeft(int row, int col, char board[8][8])
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


void eightQueens::printSolution(char board[8][8]) //print out the solved chess board
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
			cout << board[row][col] << " ";
		cout << endl << endl;
	}

}

