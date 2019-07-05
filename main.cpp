#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Combinations/combinations.hpp>


int main()
{
	Board board;
	Point userPoint;

	while(true)
	{
		/*
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> userPoint.x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> userPoint.y;
*/
		board.drawMenu();
/*
		try
		{
			board.markField(userPoint);
		}
		catch(std::invalid_argument exception)
		{
			std::cerr << exception.what();
			continue;
		}

		board.drawScreen();

		Combinations combinations = Combinations(board.getBoard());
		Solver solver = Solver(combinations.getCombinationList());
		Point solverPoint = solver.primitiveSolve();

	        std::cout << "Computer's coordinates are x:" << solverPoint.x << " y: " << solverPoint.y << std::endl;
		board.markField(solverPoint);
		board.drawScreen();

		if(combinations.checkIfxWon())
		{
			std::cout << "!!! x won !!!" << std::endl;
		}
		if(combinations.checkIfoWon())
		{
			std::cout << "!!! o won !!!" << std::endl;
		}
		*/
	}
}

