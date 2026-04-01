#pragma once

#include "position.hpp"
#include "dimention.hpp"
#include "ncurses.hpp"

namespace tui
{
	class Window
	{
	public:
		Window(Position pos, Dimention dim);
		~Window();
	
		Window(const Window &) = delete;
		WINDOW * getWindowHandle() { return m_windowHandle; }
	private:
		Position m_position;
		Dimention m_dimention;
		WINDOW * m_windowHandle;
	};
}
