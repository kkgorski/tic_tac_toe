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
      players = new Players(board);
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
    Board         board;
    Players*      players;
};
