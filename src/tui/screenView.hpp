#pragma once

#include "ncurses.hpp"
#include "dimention.hpp"

namespace tui
{
	class ScreenView
	{
	public:
		explicit ScreenView(WINDOW * window);
		WINDOW * get();
		void  updateSize();
		Dimention getDimention();

	private:
		WINDOW * m_window;
		Dimention m_dimention;
	};
}
