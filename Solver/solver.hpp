#include <Global/global.hpp>

#pragma once

class Solver
{
public:
	Solver(charVectorList _combinationList) : combinationList(_combinationList){}
	void solve(){}
private:
	charVectorList combinationList;
};

