#include <Combinations/combinations.hpp>

#pragma once

class Solver
{
typedef std::vector<char> charVector;
typedef std::list<charVector> charVectorList;
typedef std::vector<charVector> charVectorVector;
public:
	Solver(charVectorList _combinationList) : combinationList(_combinationList){}
	void solve(){}
private:
	charVectorList combinationList;
};

