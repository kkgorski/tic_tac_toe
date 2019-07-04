#include <list>
#include <vector>

#define BOARD_SIZE 3

#pragma once

class Board
{
public:
	Board()
	{
		initializeEmptyBoard();
		initializeCombinations();
		lastTurnCharacter = 'x';
	}

	void printCombinations()
	{
		for (charVectorList::iterator charVectorIt = combinationList.begin(); charVectorIt != combinationList.end(); ++charVectorIt)
		{
			for (charVector::iterator it = charVectorIt->begin(); it != charVectorIt->end(); ++it)
			{
				std::cout << *(it) << "|";
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
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
		        drawRow(i);
		        printIfNotLast(i,"-+-+-\n");
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
	void initializeEmptyBoard()
	{
		board = charVectorVector(BOARD_SIZE, charVector (BOARD_SIZE, ' '));
	}
	void drawRow(unsigned int row)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			std::cout << board[row][i];
		        printIfNotLast(i,"|");
		}
		std::cout << std::endl;
	}

	void printIfNotLast(unsigned int it, std::string printable)
	{
		const unsigned int lastElement = BOARD_SIZE - 1;
		if(it != lastElement)
		{
			std::cout << printable;
		}
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

	typedef std::vector<char> charVector;
	typedef std::list<charVector> charVectorList;
	typedef std::vector<charVector> charVectorVector;

	charVectorList combinationList;
	charVectorVector board; 
	char lastTurnCharacter;
};

