#include <Board/board.hpp>

#pragma once

class Combinations  
{
typedef std::vector<char> charVector;
typedef std::list<charVector> charVectorList;
typedef std::vector<charVector> charVectorVector;
public:
	Combinations(charVectorVector board)
	{
		combinationList.clear();
		for(unsigned int column = 0; column < BOARD_SIZE; column++)
		{
			charVector row;
			for(unsigned int i = 0; i < BOARD_SIZE; i++)
			{
				row.push_back(board[i][column]);
			}
                        combinationList.push_back(row);
		}
		for(unsigned int row = 0; row < BOARD_SIZE; row++)
		{
			charVector column;
			for(unsigned int i = 0; i < BOARD_SIZE; i++)
			{
				column.push_back(board[row][i]);
			}
                        combinationList.push_back(column);
		}
		charVector diagonalA;
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			diagonalA.push_back(board[i][i]);
		}

                combinationList.push_back(diagonalA);
		charVector diagonalB;
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			diagonalB.push_back(board[i][(BOARD_SIZE - 1) - i]);
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

	bool checkIfxWon()
	{
		return checkIfCharacterWon('x');
	}

	bool checkIfoWon()
	{
		return checkIfCharacterWon('o');
	}

private:
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

	charVectorList combinationList;
};

