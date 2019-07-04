#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Combinations/combinations.hpp>


int main()
{
	Board board;
	Point point;

	while(true)
	{
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> point.x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> point.y;

		board.markField(point);

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

