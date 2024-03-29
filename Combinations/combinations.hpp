#include <Global/global.hpp>
#include <iostream>

#pragma once

class Combinations
{
  public:
    Combinations(charVectorVector& _rawBoard) : rawBoard(_rawBoard), boardSize(_rawBoard.front().size()), combinationList(){}

    void update()
    {
      combinationList.clear();
      for(unsigned int column = 0; column < boardSize; column++)
      {
        charVector row;
        for(unsigned int i = 0; i < boardSize; i++)
        {
          row.push_back(rawBoard[i][column]);
        }
        combinationList.push_back(row);
      }
      for(unsigned int row = 0; row < boardSize; row++)
      {
        charVector column;
        for(unsigned int i = 0; i < boardSize; i++)
        {
          column.push_back(rawBoard[row][i]);
        }
        combinationList.push_back(column);
      }
      charVector diagonalA;
      for(unsigned int i = 0; i < boardSize; i++)
      {
        diagonalA.push_back(rawBoard[i][i]);
      }

      combinationList.push_back(diagonalA);
      charVector diagonalB;
      for(unsigned int i = 0; i < boardSize; i++)
      {
        diagonalB.push_back(rawBoard[i][(boardSize - 1) - i]);
      }
      combinationList.push_back(diagonalB);
    }

    void print()
    {
      for(auto const& combination: combinationList)
      {
        for(auto const& field: combination)
        {
          std::cout << field << "|";
        }
        std::cout << std::endl;
      }
    }

    bool checkIfCharacterWon(char characterToWin)
    {
      bool won;
      for (auto const& combination : combinationList)
      {
        won = true;
        for (auto const character : combination)
        {
          if(character != characterToWin)
          {
            won = false;
          }
        }
        if(won)
        {
          return won;
        }
      }
      return false;
    }

    charVectorList getCombinationList()
    {
      return combinationList;
    }

  private:
    charVectorVector& rawBoard;
    const unsigned int boardSize;
    charVectorList combinationList;
};

