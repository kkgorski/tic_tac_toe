#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Player/player.hpp>

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
      iPlayer = new IPlayer(userCharacter, solverCharacter, board, lastTurn);
    }

    void run()
    {
      bool isFinished = false;
      while(!isFinished)
      {
	isFinished = makeMove();
      }
    }

  private:
    bool makeMove()
    {
      Player* player = iPlayer->getPlayer();
      while(true)
      {
	try
	{
	  board.markField(player->getPoint());
	  break;
	}
	catch(std::invalid_argument exception)
	{
	  std::cerr << exception.what();
	}
      }
      board.drawScreen();
      return board.checkIfCharacterWon(player->getCharacter());
    }

    Board board;
    LastTurn lastTurn;
    char userCharacter;
    char solverCharacter;
    IPlayer * iPlayer;
};
