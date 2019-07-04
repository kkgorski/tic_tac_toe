#include <Global/global.hpp>

#pragma once

class Solver
{
public:
	Solver(charVectorList _combinationList) : combinationList(_combinationList){}
	Point primitiveSolve()
	{
		Point point;
		const unsigned int boardSize = combinationList.front().size();
		point.x = rand() % boardSize;
		point.y = rand() % boardSize;
		return point;
	}
private:
	charVectorList combinationList;
};

