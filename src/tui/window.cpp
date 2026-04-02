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

void Window::setDimention(const Dimention dimention)
{
	wresize(m_windowHandle, dimention.height, dimention.width);
	m_dimention = dimention;
}

void Window::setPosition(const Position position)
{
	mvwin(m_windowHandle, position.y, position.x);
	m_position = position;
}
