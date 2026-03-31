#include "ncurses.hpp"

Ncurses::Ncurses()
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
}


Ncurses::~Ncurses()
{
	endwin();
}

int Ncurses::getInput()
{
	return getch();
}
