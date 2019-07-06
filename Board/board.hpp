#include <Global/global.hpp>
#include <ncurses.h>

#pragma once

class Board
{
public:

	Board(unsigned int _boardSize = 3) : boardSize(_boardSize),
					     board(charVectorVector(boardSize, charVector (boardSize, ' '))),
					     lastTurnCharacter('x'){}

	void markField(Point point)
	{
		if(point.x >= boardSize || point.y >= boardSize)
		{
			throw std::invalid_argument("Point coordinates out of range!!!\n\n");
		}

		const char character = (lastTurnCharacter == 'x') ? 'o' : 'x';
		board[point.y][point.x] = character;
		lastTurnCharacter = character;
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

	void drawMenu()
	{
		WINDOW *window;
		char itemArray[5][9] = { "Choice 1", "Choice 2", "Choice 3", "Choice 4", "Exit" };
		char item[9];
		initscr();
		window = newwin (10, 12, 1, 1);
		box (window, 0, 0);

		for(unsigned int i = 0; i < 5; ++i)
		{
			if(0 == i)
			{
				wattron(window, A_STANDOUT);
			}
			else
			{
			wattroff(window, A_STANDOUT);
			}
			sprintf(item, "%-7s", itemArray[i]);
			mvwprintw(window, i+1, 2, "%s", item);
		}

		wrefresh(window);
		cbreak(); //?
		noecho();
		keypad(window, TRUE);
		curs_set(0);

		int character = 0;
		int i = 0;
		while((character = wgetch(window)) != 'q')
		{
			sprintf(item, "%-7s", itemArray[i]);
			mvwprintw(window, i+1, 2, "%s", item);
			switch(character)
			{
				case KEY_UP:
					i--;
					i = (i < 0) ? 4 : i;
					break;
				case KEY_DOWN:
					i++;
					i = (i > 4) ? 0 : i;
					break;
			}
			wattron(window, A_STANDOUT);

			sprintf(item, "%-7s", itemArray[i]);
			mvwprintw(window, i+1, 2, "%s", item);
			wattroff(window, A_STANDOUT);
		}

		clear();
		delwin( window );
		endwin();
	}

	const charVectorVector& getBoard() const
	{
		return board;
	}

private:

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

	unsigned int boardSize;
	charVectorVector board; 
	char lastTurnCharacter;
};

