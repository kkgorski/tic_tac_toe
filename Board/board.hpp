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
		drawRow(0);
		drawSeparatingRow();
		drawRow(1);
		drawSeparatingRow();
		drawRow(2);
	}

private:

	void drawRow(unsigned int row)
	{
		for(unsigned int i = 0; i < BOARD_SIZE; i++)
		{
			std::cout << board[row][i];
			const unsigned int lastElement = BOARD_SIZE - 1;
			if(i != lastElement)
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
	}

	void drawSeparatingRow()
	{
		std::cout << "-+-+-" << std::endl;
	}

	char board[BOARD_SIZE][BOARD_SIZE];
	char lastTurnCharacter;
};

