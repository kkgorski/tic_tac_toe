#include <Global/global.hpp>
#include <Combinations/combinations.hpp>

#pragma once

class Solver
{
public:
	Solver(charVectorList _combinationList) : combinationList(_combinationList){}
	void solve(){}
private:
	charVectorList combinationList;
};

