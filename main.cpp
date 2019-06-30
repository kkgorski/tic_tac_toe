#include <iostream>

#define BOARD_SIZE 3

void drawRow(const char* board)
{
	for(unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << board[i];
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

void drawScreen(const char board[][BOARD_SIZE] )
{
	drawRow(board[0]);
	drawSeparatingRow();
	drawRow(board[1]);
	drawSeparatingRow();
	drawRow(board[2]);
}

void initBoard(char board[][BOARD_SIZE])
{
	for(unsigned int i = 0; i < BOARD_SIZE; i++)
	{
		for(unsigned int j = 0; j < BOARD_SIZE; j++)
		{
			board[i][j] = ' ';
		}
	}
}

int main()
{
	char board[BOARD_SIZE][BOARD_SIZE] = {};
	char character = 'o';
	initBoard(board);
	while(true)
	{
		unsigned int x;
		unsigned int y;
	        std::cout << "Give me coordinate x" << std::endl;
	        std::cin >> x;
	        std::cout << "Give me coordinate y" << std::endl;
	        std::cin >> y;
		board[x][y] = character;
		drawScreen(board);

		character = (character == 'o') ? 'x' : 'o';
	}
}

