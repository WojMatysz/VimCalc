#include "window.hpp"

using namespace tui;

Window::Window(Position pos, Dimention dim) : m_position(pos), m_dimention(dim)
{
	m_windowHandle = newwin(dim.height, dim.width, pos.y, pos.x);
}

Window::~Window()
{
	if(m_windowHandle) delwin(m_windowHandle);
}
