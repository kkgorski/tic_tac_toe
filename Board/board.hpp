#define BOARD_SIZE 3

class Board
{
public:
	Board()
	{
		initializeEmptyBoard();
		lastTurnCharacter = 'x';
	}

	void markField(unsigned int x, unsigned int y)
	{
		const char character = (lastTurnCharacter == 'x') ? 'o' : 'x';
		board[y][x] = character;
		lastTurnCharacter = character;
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
	char board[BOARD_SIZE][BOARD_SIZE];
	char lastTurnCharacter;
};

