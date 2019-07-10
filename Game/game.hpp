#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>

enum LastTurn
{
	userTurn,
	solverTurn
};

class Game
{
public:
	Game() : board(), solver(board){}

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
		lastTurn = userTurn;
	}

	void run()
	{
		while(!hasFinished())
		{
			makeMove();
			board.drawScreen();
		}
	}

private:
	void makeMove()
	{
		if(lastTurn == solverTurn)
		{
			makeUserMove();
			lastTurn = userTurn;
		}
		else
		{
			makeSolverMove();
			lastTurn = solverTurn;
		}
	}

	bool hasFinished()
	{
		if(lastTurn == userTurn)
		{
			return board.checkIfCharacterWon(userCharacter);
		}
		else
		{
			return board.checkIfCharacterWon(solverCharacter);
		}
	}

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
	Solver solver;
	LastTurn lastTurn;
	char userCharacter;
	char solverCharacter;
};
