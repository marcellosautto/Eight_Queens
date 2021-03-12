#include "eightQueens.h"

int main()
{
	eightQueens Q;

	if (Q.solveBoard(0, 0, N))
		Q.printSolution();
}
