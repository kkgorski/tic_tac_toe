#define BOARD_SIZE 3

class Board
{
public:
	Board()
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			for(unsigned int j = 0; j < BOARD_SIZE; j++)
			{
				board[i][j] = ' ';
			}
		}
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

private:
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

	void drawSeparatingRow()
	{
		std::cout << "-+-+-" << std::endl;
	}

	char board[BOARD_SIZE][BOARD_SIZE];
	char lastTurnCharacter;
};

