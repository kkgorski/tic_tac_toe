#include <Global/global.hpp>
#include <ncurses.h>
#include <menu.h>
#include <string.h>

#pragma once

#define MY_KEY_ENTER 10

class Board
{
public:

	Board(unsigned int _boardSize = 3) : boardSize(_boardSize),
					     board(charVectorVector(boardSize, charVector (boardSize, ' '))),
					     lastTurnCharacter('x')
	{
		initializeNcursesScreen();
		initializeNcursesItems();
		initializeNcursesMenu();
		initializeNcursesUserInstructions();
	}

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

	void markComputersField(Point point)
	{
		markField(point);
		const unsigned int itemIndex = point.x + boardSize * point.y;
		ITEM * item = my_items[itemIndex];
		setNcursesItem(item, "x");
	}

	void markField(const unsigned int itemIndex)
	{
		Point point;
		point.x = itemIndex % boardSize;
		point.y = itemIndex / boardSize;
		markField(point);
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
		refresh();
		post_menu(my_menu);
		wrefresh(my_menu_win);
	}

	void play()
	{
		int c;
		while((c = wgetch(my_menu_win)) != KEY_F(1))
		{
			switch(c)
			{	case KEY_DOWN:
					mvprintw(LINES - 4, 0, "DOWN");
					menu_driver(my_menu, REQ_DOWN_ITEM);
					break;
				case KEY_UP:
					mvprintw(LINES - 4, 0, "UP");
					menu_driver(my_menu, REQ_UP_ITEM);
					break;
				case KEY_LEFT:
					mvprintw(LINES - 4, 0, "LEFT");
					menu_driver(my_menu, REQ_LEFT_ITEM);
					break;
				case KEY_RIGHT:
					mvprintw(LINES - 4, 0, "RIGHT");
					menu_driver(my_menu, REQ_RIGHT_ITEM);
					break;
				case MY_KEY_ENTER:
					ITEM * currentItem = current_item(my_menu);
					setNcursesItem(currentItem, "x");
					break;
			}
			refresh(); //for debugging
			wrefresh(my_menu_win);
		}	
	}

	const charVectorVector& getBoard() const
	{
		return board;
	}

private:

	void setNcursesItem(ITEM * item, const char* _character)
	{
		if (item->name.str!=NULL)
		{
			mvprintw(LINES - 6, 0, item->name.str);
			char* character = strdup(_character);
			item->name.length = 1;
			item->name.str = character;

			const unsigned int itemIdx = item_index(item);
			markField(itemIdx);
			mvprintw(LINES - 4, 0, "enter %u", itemIdx);
		}
	}

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

	void initializeNcursesScreen()
	{
		initscr();
		start_color();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
	}

	void initializeNcursesItems()
	{
		const char * empty = " ";
		const unsigned int numOfBoardElements = boardSize * boardSize;
		my_items = (ITEM **)calloc(numOfBoardElements + 1, sizeof(ITEM *));
		for(unsigned int i = 0; i < numOfBoardElements; ++i)
		{
			const char * id = std::to_string(i).c_str();
			my_items[i] = new_item(empty, id);
		}
	}

	void initializeNcursesMenu()
	{
		/* Crate menu */
		my_menu = new_menu((ITEM **)my_items);

		/* Set menu option not to show the description */
		menu_opts_off(my_menu, O_SHOWDESC);

		/* Create the window to be associated with the menu */
		my_menu_win = newwin(5, 11, 2, 6);
		keypad(my_menu_win, TRUE);

		/* Set main window and sub window */
		set_menu_win(my_menu, my_menu_win);
		set_menu_sub(my_menu, derwin(my_menu_win, 3, 10, 1, 1));
		set_menu_format(my_menu, 3, 3);

		/* Print a border around the main window and print a title */
		box(my_menu_win, 0, 0);
	}

	void initializeNcursesUserInstructions()
	{
		attron(COLOR_PAIR(2));
		mvprintw(LINES - 2, 0, "Use Arrow Keys to navigate (F1 to Exit)");
		attroff(COLOR_PAIR(2));
	}

	void destroyNcurses()
	{
		unpost_menu(my_menu);
		free_menu(my_menu);
		const unsigned int numOfBoardElements = boardSize * boardSize;
		for(unsigned int i = 0; i < numOfBoardElements; ++i)
		{
			free_item(my_items[i]);
		}
		endwin();
	}

	ITEM **my_items;
	MENU *my_menu;
        WINDOW *my_menu_win;

	unsigned int boardSize;
	charVectorVector board; 
	char lastTurnCharacter;
};

