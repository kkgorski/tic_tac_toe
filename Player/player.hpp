class Player
{
public:
        Player(char character)
        {
                point.character = character;
        }

        virtual Point getPoint() = 0;
protected:
        Point point;
};

class SolverPlayer : public Player
{
public:
        SolverPlayer(char character, Board& board) : Player(character), solver(board){}

	virtual Point getPoint() override
	{
		Point solverPoint = solver.primitiveSolve();
		solverPoint.character = point.character;

		std::cout << "Computer's coordinates are x:" << solverPoint.x << " y: " << solverPoint.y << std::endl;
	        return solverPoint;
	}
private:
	Solver solver;
};

class UserPlayer : public Player
{
public:
        UserPlayer(char character) : Player(character){}

	virtual Point getPoint() override
	{
                Point userPoint;
                userPoint.character = point.character;
                std::cout << "Give me coordinate x" << std::endl;
                std::cin >> userPoint.x;
                std::cout << "Give me coordinate y" << std::endl;
                std::cin >> userPoint.y;

                return userPoint;
	}
};
