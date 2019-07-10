#include <Global/global.hpp>

#pragma once

class Solver
{
public:
	Solver(Board& _board) : board(_board){}
	Point primitiveSolve()
	{
		while(true)
		{
			Point point;
			const unsigned int boardSize = board.getSize();
			point.x = rand() % boardSize;
			point.y = rand() % boardSize;
			if(board.getRawBoard()[point.y][point.x] == ' ')
			{
				return point;
			}
		}
	}
private:
	Board& board;
};

