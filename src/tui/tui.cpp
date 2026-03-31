#include "tui.hpp"

using namespace tui;

void Tui::run()
{
	while(true)
	{
		int input = m_ncurses.getInput();
		if(input == (int)('q')) break;
	}
}
