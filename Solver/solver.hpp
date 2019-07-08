#include <Global/global.hpp>

#pragma once

class Solver
{
public:
	Solver(charVectorList _combinationList, Board& _board) : combinationList(_combinationList), board(_board){}
	Point primitiveSolve()
	{
		while(true)
		{
			Point point;
			const unsigned int boardSize = combinationList.front().size();
			point.x = rand() % boardSize;
			point.y = rand() % boardSize;
			if(board.getBoard()[point.y][point.x] == ' ')
			{
				return point;
			}
		}
	}
private:
	charVectorList combinationList;
	Board& board;
};

