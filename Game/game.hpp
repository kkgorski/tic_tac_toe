#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>

class Game
{
public:
	void init()
	{
		std::string userInput= " ";
		std::cout << "Please choose you character to be 'x' or 'o'" << std::endl;
		do
		{
			std::cin >> userInput;
			std::cout << std::endl;
		}while(userInput != "x" && userInput != "o");
		userCharacter = userInput.c_str()[0];
		solverCharacter = (userCharacter == 'x') ? 'o' : 'x';

	}
	void run()
	{
		while(true)
		{
			makeUserMove();
			board.drawScreen();
			if(board.checkIfCharacterWon(userCharacter))
			{
				break;
			}
			makeSolverMove();
			board.drawScreen();
			if(board.checkIfCharacterWon(solverCharacter))
			{
				break;
			}
		}
	}

private:

	void makeUserMove()
	{
		while(true)
		{
			Point userPoint;
			userPoint.character = userCharacter;
			std::cout << "Give me coordinate x" << std::endl;
			std::cin >> userPoint.x;
			std::cout << "Give me coordinate y" << std::endl;
			std::cin >> userPoint.y;

			try
			{
				board.markField(userPoint);
				break;
			}
			catch(std::invalid_argument exception)
			{
				std::cerr << exception.what();
			}
		}
	}

	void makeSolverMove()
	{
		Solver solver = Solver(board);
		Point solverPoint = solver.primitiveSolve();
		solverPoint.character = solverCharacter;

		std::cout << "Computer's coordinates are x:" << solverPoint.x << " y: " << solverPoint.y << std::endl;
		try
		{
			board.markField(solverPoint);
		}
		catch(std::invalid_argument exception)
		{
			std::cerr << exception.what();
		}
	}

	Board board;
	char userCharacter;
	char solverCharacter;
};
