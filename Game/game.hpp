#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Player/player.hpp>

enum LastTurn
{
	userTurn,
	solverTurn
};

class Game
{
public:
	Game() : board(){}

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
			player = new UserPlayer(userCharacter);
			while(true)
			{
				try
				{
					board.markField(player->getPoint());
					lastTurn = userTurn;
					break;
				}
				catch(std::invalid_argument exception)
				{
					std::cerr << exception.what();
				}
			}
		}
		else
		{
			player = new SolverPlayer(solverCharacter, board);
			try
			{
				board.markField(player->getPoint());
			}
			catch(std::invalid_argument exception)
			{
				std::cerr << exception.what();
			}
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

	Player* player;
	Board board;
	LastTurn lastTurn;
	char userCharacter;
	char solverCharacter;
};
