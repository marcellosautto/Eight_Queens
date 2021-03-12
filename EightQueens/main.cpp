#include "eightQueens.h"

int main()
{
	eightQueens Q;
	//eightQueens* Q = new eightQueens(); //create pointer to sudoku class
	//while (Q->mainLoop()) //while mainLoop returns true, create a new instance of the sudoku class
	//	Q = new eightQueens();

	if (Q.solveBoard(0, 0, N))
	{
		Q.printSolution();
		return false;
	}
}
