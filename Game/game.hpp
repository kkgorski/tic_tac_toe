#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Combinations/combinations.hpp>

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
			makeUserMove(userCharacter, board);
			Combinations combinations1 = Combinations(board.getBoard());
			if(checkIfSomeoneWon(combinations1))
			{
				break;
			}
			makeComputersMove(solverCharacter, board);
			Combinations combinations2 = Combinations(board.getBoard());
			if(checkIfSomeoneWon(combinations2))
			{
				break;
			}
		}
	}

private:

	bool checkIfSomeoneWon(Combinations& combinations)
	{
		if(combinations.checkIfxWon())
		{
			std::cout << "!!! x won !!!" << std::endl;
			return true;
		}
		if(combinations.checkIfoWon())
		{
			std::cout << "!!! o won !!!" << std::endl;
			return true;
		}
		return false;
	}

	void makeUserMove(char character, Board &board)
	{
		while(true)
		{
			Point userPoint;
			userPoint.character = character;
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

		board.drawScreen();
	}

	void makeComputersMove(char character, Board& board)
	{
		Combinations combinations = Combinations(board.getBoard());
		Solver solver = Solver(combinations.getCombinationList(), board);
		Point solverPoint = solver.primitiveSolve();
		solverPoint.character = character;

		std::cout << "Computer's coordinates are x:" << solverPoint.x << " y: " << solverPoint.y << std::endl;
		try
		{
		board.markField(solverPoint);
		}
		catch(std::invalid_argument exception)
		{
			std::cerr << exception.what();
		}

		board.drawScreen();
	}

	Board board;
	char userCharacter;
	char solverCharacter;
};
