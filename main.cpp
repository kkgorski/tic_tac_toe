#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Combinations/combinations.hpp>


int main()
{
	Board board;

	while(true)
	{
		unsigned int x;
		unsigned int y;
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> y;

		board.markField(x,y);

		Combinations combinations = Combinations(board.getBoard());
		Solver solver = Solver(combinations.getCombinationList());

		board.drawScreen();

		combinations.print();

		if(combinations.checkIfxWon())
		{
			std::cout << "!!! x won !!!" << std::endl;
		}
		if(combinations.checkIfoWon())
		{
			std::cout << "!!! o won !!!" << std::endl;
		}
	}
}

