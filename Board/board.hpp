#include <Global/global.hpp>

#pragma once

class Board
{
public:

	Board(unsigned int boardSize = 3) : board(charVectorVector(boardSize, charVector (boardSize, ' '))),
					    lastTurnCharacter('x'){}

	void markField(Point point)
	{
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

	charVectorVector board; 
	char lastTurnCharacter;
};

