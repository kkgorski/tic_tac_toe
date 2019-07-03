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
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			for(unsigned int j = 0; j < BOARD_SIZE; j++)
			{
				board[i][j] = ' ';
			}
		}
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
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			if(checkIfColumnIs(character, i) || checkIfRowIs(character, i))
			{
				return true;
			}
		}

		if(checkIfDiagonalAIs(character) || checkIfDiagonalBIs(character))
		{
			return true;
		}

		return false;
	}

	bool checkIfColumnIs(char character, unsigned int column)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			if(character != board[i][column])
			{
				return false;
			}
		}
		return true;
	}

	bool checkIfRowIs(char character, unsigned int row)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			if(character != board[row][i])
			{
				return false;
			}
		}
		return true;
	}

	bool checkIfDiagonalAIs(char character)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			if((character != board[i][i]))
			{
				return false;
			}
		}
		return true;
	}

	bool checkIfDiagonalBIs(char character)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			if(character != board[i][(BOARD_SIZE - 1) - i])
			{
				return false;
			}
		}
		return true;
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

	charVectorList combinationList;
	char board[BOARD_SIZE][BOARD_SIZE];
	char lastTurnCharacter;
};

