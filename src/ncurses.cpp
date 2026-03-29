#include "ncurses.hpp"

Ncurses::Ncurses()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	getch();
}


Ncurses::~Ncurses()
{
	endwin();
}
