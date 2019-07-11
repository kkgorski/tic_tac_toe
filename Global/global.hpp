#pragma once

#include <list>
#include <vector>

typedef std::vector<char> charVector;
typedef std::list<charVector> charVectorList;
typedef std::vector<charVector> charVectorVector;

struct Point
{
  unsigned int x;
  unsigned int y;
  char character;
};

enum LastTurn
{
  userTurn,
  solverTurn
};

