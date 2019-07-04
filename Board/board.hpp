#include <list>
#include <vector>

#define BOARD_SIZE 3

#pragma once

class Board
{
typedef std::vector<char> charVector;
typedef std::list<charVector> charVectorList;
typedef std::vector<charVector> charVectorVector;
public:
	Board(unsigned int boardSize = 3)
	{
		initializeEmptyBoard(boardSize);
		initializeCombinations();
		lastTurnCharacter = 'x';
	}

	void printCombinations()
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

	void markField(unsigned int x, unsigned int y)
	{
		const char character = (lastTurnCharacter == 'x') ? 'o' : 'x';
		board[y][x] = character;
		lastTurnCharacter = character;
		initializeCombinations(); //to be removed from here
	}

	void drawScreen()
	{
		for(auto const& row: board)
		{
		        drawRow(row);
			if(&row != &board.back())
			{
				std::cout << "-+-+-\n";
			}
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
	void initializeEmptyBoard(unsigned int boardSize)
	{
		board = charVectorVector(boardSize, charVector (boardSize, ' '));
	}

	void drawRow(charVector row)
	{
		for(auto const& character: row)
		{
			std::cout << character; 
			if(&character != &row.back())
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}

	bool checkIfCharacterWon(char character)
	{
		bool won;
		for (charVectorList::iterator charVectorIt = combinationList.begin(); charVectorIt != combinationList.end(); ++charVectorIt)
		{
			won = true;
			for (charVector::iterator it = charVectorIt->begin(); it != charVectorIt->end(); ++it)
			{
				if(character != *(it))
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

	void initializeCombinations()
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


	charVectorList combinationList;
	charVectorVector board; 
	char lastTurnCharacter;
};

