#include <Global/global.hpp>

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

