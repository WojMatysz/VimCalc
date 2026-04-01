#include "tui.hpp"

using namespace tui;

Tui::Tui() : 
	m_inputFormulaWindow(Position{0, 0}, Dimention{10, 2}),
	m_sheetWindow(Position{0, 2}, Dimention{10, 20}),
	m_statusBarWindow(Position{0, 22}, Dimention{10, 2})
{
}

void Tui::run()
{
	while(true)
	{
		//rendering windows
		wbkgd(m_inputFormulaWindow.getWindowHandle(), ' ' | COLOR_PAIR(1));
		werase(m_inputFormulaWindow.getWindowHandle());

		wbkgd(m_sheetWindow.getWindowHandle(), ' ' | COLOR_PAIR(2));
		werase(m_sheetWindow.getWindowHandle());

		wbkgd(m_statusBarWindow.getWindowHandle(), ' ' | COLOR_PAIR(3));
		werase(m_statusBarWindow.getWindowHandle());

		wrefresh(m_inputFormulaWindow.getWindowHandle());
		wrefresh(m_sheetWindow.getWindowHandle());
		wrefresh(m_statusBarWindow.getWindowHandle());

		//geting input
		int input = m_ncurses.getInput();
		if(input == (int)('q')) break;
	}
}
