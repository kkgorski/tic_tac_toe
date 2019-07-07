#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Combinations/combinations.hpp>


int main()
{
	Board board;
	Point userPoint;

	std::string userCharacter = " ";
	std::cout << "Please choose you character to be 'x' or 'o'" << std::endl;
	do
	{
	        std::cin >> userCharacter;
		std::cout << std::endl;
	}while(userCharacter != "x" && userCharacter != "o");
	userPoint.character = userCharacter.c_str()[0];

	while(true)
	{
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> userPoint.x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> userPoint.y;

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
		solverPoint.character = (userPoint.character == 'x') ? 'o' : 'x';

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
	}
}

