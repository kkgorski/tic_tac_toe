#include <Global/global.hpp>
//////////////////#include <ncurses.h>


//from tutorial
#include <curses.h>
#include <menu.h>
#include <string.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

char *choices[] = {
                        " ", " ", " ", " ", " ",
			" ", " ", " ", " ",
                        (char *)NULL,
                  };
// from tutorial

#pragma once

#define MY_KEY_ENTER 10

class Board
{
public:

	Board(unsigned int _boardSize = 3) : boardSize(_boardSize),
					     board(charVectorVector(boardSize, charVector (boardSize, ' '))),
					     lastTurnCharacter('x')
	{
		initializeNcurses();
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
		//from tutorial
	int c;				
        int n_choices, i;
	
	/* Initialize curses */

	/* Create items */
        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i)
                my_items[i] = new_item(choices[i], choices[i]);

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
	
	attron(COLOR_PAIR(2));
	mvprintw(LINES - 3, 0, "Use PageUp and PageDown to scroll");
	mvprintw(LINES - 2, 0, "Use Arrow Keys to navigate (F1 to Exit)");
	attroff(COLOR_PAIR(2));
	refresh();

	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);

	int errorCode = 0;
	
	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       switch(c)
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
				char* character;
				ITEM * currentItem = current_item(my_menu);
				if (currentItem->name.str!=NULL)
				{
					mvprintw(LINES - 6, 0, currentItem->name.str);
					character = strdup("x");
					currentItem->name.length = 1;
					currentItem->name.str = character;
				}
				
				errorCode = set_current_item(my_menu, currentItem);
				switch(errorCode)
				{
					case E_BAD_ARGUMENT:
						mvprintw(LINES - 5, 0, "E_BAD_ARGUMENT");
						break;
					case E_BAD_STATE:
						mvprintw(LINES - 5, 0, "E_BAD_STATE");
	    					break;
					case E_NOT_CONNECTED:
						mvprintw(LINES - 5, 0, "E_NOT_CONNECTED");
						break;
					case E_SYSTEM_ERROR:
						mvprintw(LINES - 5, 0, "E_SYSTEM_ERROR");
						break;
					default:
						break;
				}
				mvprintw(LINES - 4, 0, "ENTER");
				break;
		}
		refresh(); //for debugging
                wrefresh(my_menu_win);
	}	

	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	endwin();
	//from tutorial
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

	void initializeNcurses()
	{
		initscr();
		start_color();
		cbreak();
		noecho();
		keypad(stdscr, TRUE);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_CYAN, COLOR_BLACK);
	}

	ITEM **my_items;
	MENU *my_menu;
        WINDOW *my_menu_win;
	unsigned int boardSize;
	charVectorVector board; 
	char lastTurnCharacter;
};

