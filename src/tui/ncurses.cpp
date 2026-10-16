#include "ncurses.hpp"
#include <stdexcept>

Ncurses::Ncurses()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	if(!has_colors())
	{
		endwin();
		throw std::runtime_error("No color support");
	}
	start_color();
	use_default_colors();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_BLACK, COLOR_YELLOW);
}


Ncurses::~Ncurses()
{
	endwin();
}

int Ncurses::getInput()
{
	return getch();
}
