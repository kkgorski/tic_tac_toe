#include <Global/global.hpp>
#include <Combinations/combinations.hpp>

#pragma once

class Board
{
  public:
    Board(unsigned int _size = 3) : size(_size),
    rawBoard(charVectorVector(size, charVector(size, ' '))),
    boardCombinations(rawBoard){}

    void markField(Point point)
    {
      if(point.x >= size || point.y >= size)
      {
	throw std::invalid_argument("Point coordinates out of range!!!\n\n");
      }
      if(rawBoard[point.y][point.x] != ' ')
      {
	throw std::invalid_argument("This point is already marked!!!\n\n");
      }
      rawBoard[point.y][point.x] = point.character;
      boardCombinations.update();
    }

    bool checkIfCharacterWon(char characterToWin)
    {
      return boardCombinations.checkIfCharacterWon(characterToWin);
    }

    const charVectorVector& getRawBoard() const
    {
      return rawBoard;
    }

    unsigned int getSize() const
    {
      return size;
    }

  private:

    const unsigned int    size;
    charVectorVector      rawBoard;
    Combinations          boardCombinations;
};

