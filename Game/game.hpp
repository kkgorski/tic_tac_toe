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
      Player* player = players->getCurrentPlayer();
      bool isFinished = false;
      while(!isFinished)
      {
        makeMove(player);
        isFinished = didPlayerWon(player);
        userInterface.drawScreen(board.getRawBoard());
	player = players->switchToNextPlayer();
      }
    }

    void makeMove(Player* player)
    {
	while(true)
	{
          Point point = player->getPoint();
	  try
	  {
	    board.markField(point);
	    break;
	  }
	  catch(std::invalid_argument exception)
	  {
	    std::cerr << exception.what();
	  }
	}
    }

    bool didPlayerWon(Player* player)
    {
      if(board.checkIfCharacterWon(player->getCharacter()))
      {
	return true;
      }
      else
      {
        return false;
      }
    }

  private:
    Board         board;
    Players*      players;
    UserInterface userInterface;
};
