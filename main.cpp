#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>


int main()
{
	Board board;
	Solver solver = Solver(board);

	while(true)
	{
		unsigned int x;
		unsigned int y;
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> y;
		board.markField(x,y);
		board.drawScreen();
                board.printCombinations();
		if(board.checkIfxWon())
		{
			std::cout << "!!! x won !!!" << std::endl;
		}
		if(board.checkIfoWon())
		{
			std::cout << "!!! o won !!!" << std::endl;
		}
	}
}

