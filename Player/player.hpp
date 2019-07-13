#include <UserInterface/userInferface.hpp>

class Player
{
  public:
    Player(){}

    virtual Point getPoint() = 0;
    virtual char getCharacter()
    {
      return point.character;
    }
    virtual void setCharacter(char character)
    {
      point.character = character;
    }
  private:
    Point point;
};

class SolverPlayer : public Player
{
  public:
    SolverPlayer(Board& board) : Player(), solver(board){}

    virtual Point getPoint() override
    {
      Point solverPoint = solver.primitiveSolve();
      solverPoint.character = getCharacter();

      std::cout << "Computer's coordinates are x:" << solverPoint.x << " y: " << solverPoint.y << std::endl;
      return solverPoint;
    }
  private:
    Solver solver;
};

class UserPlayer : public Player
{
  public:
    UserPlayer(Board& _board) : Player(), board(_board){}

    virtual Point getPoint() override
    {
      Point userPoint = userInterface.getUserPoint(board.getSize());
      userPoint.character = getCharacter();

      return userPoint;
    }

    void setCharacterFromUserInput()
    {
       const char character = userInterface.getUserCharacter();
       setCharacter(character);
    }

  private:
    UserInterface userInterface;
    Board& board;
};

class Players
{
  public:
  Players(Board& board) : solverPlayer(board), userPlayer(board)
  {
    userPlayer.setCharacterFromUserInput();
    const char solverCharacter = (userPlayer.getCharacter() == 'o') ? 'x' : 'o';
    solverPlayer.setCharacter(solverCharacter);
    setFirstPlayer();
  }

  Player* getCurrentPlayer()
  {
    return player;
  }

  Player* switchToNextPlayer()
  {
    if(reinterpret_cast<Player*>(&solverPlayer) == player)
    {
      player = reinterpret_cast<Player*>(&userPlayer);
    }
    else
    {
      player = reinterpret_cast<Player*>(&solverPlayer);
    }
    return player;
  }
  private:
  void setFirstPlayer()
  {
    if(userPlayer.getCharacter() == 'o')
    {
      player = reinterpret_cast<Player*>(&userPlayer);
    }
    else
    {
      player = reinterpret_cast<Player*>(&solverPlayer);
    }
  }
  Player*      player;
  SolverPlayer solverPlayer;
  UserPlayer   userPlayer;
};

