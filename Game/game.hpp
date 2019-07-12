#include <iostream>
#include <Board/board.hpp>
#include <Solver/solver.hpp>
#include <Player/player.hpp>

class Game
{
  public:
    Game() : board(){}
    ~Game()
    {
      delete [] players;
    }

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
      players = new Players(userCharacter, solverCharacter, board);
    }

    void run()
    {
      while(true)
      {
        Player* player = players->getCurrentPlayer();
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
	if(board.checkIfCharacterWon(player->getCharacter()))
	{
	  break;
	}
	players->switchToNextPlayer();
      }
    }

  private:
    Board board;
    char userCharacter;
    char solverCharacter;
    Players* players;
};
