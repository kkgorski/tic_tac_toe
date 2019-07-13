#pragma once

#include <list>
#include <vector>
#include <iostream>

typedef std::vector<char> charVector;
typedef std::list<charVector> charVectorList;
typedef std::vector<charVector> charVectorVector;

struct Point
{
  unsigned int x;
  unsigned int y;
  char character;

  bool isValid(unsigned int bound)
  {
    if(x >= bound || y >= bound)
    {
      std::cout <<"Point coordinates out of range!!!" << std::endl;
      return false;
    }
    return true;
  }
};

