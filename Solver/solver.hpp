#include <Board/board.hpp>

#pragma once

class Solver
{
public:
	Solver(Board& _board) : board(_board){}
	void solve(){}
private:
	Board& board;
};

