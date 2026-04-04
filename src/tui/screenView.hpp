#pragma once

#include "ncurses.hpp"
#include "dimension.hpp"

namespace tui
{
	class ScreenView
	{
	public:
		explicit ScreenView(WINDOW * window);
		WINDOW * get();
		void  updateSize();
		Dimension getDimension();

	private:
		WINDOW * m_window;
		Dimension m_dimension;
	};
}
