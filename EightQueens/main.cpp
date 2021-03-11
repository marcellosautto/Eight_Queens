#include "eightQueens.h"

int main()
{
	eightQueens Q;
	while(!Q.solveBoard(0, 0, 'X'))
		Q.printSolution();

}
