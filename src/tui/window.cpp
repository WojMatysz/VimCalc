#include "window.hpp"

using namespace tui;

Window::Window(const std::string name, Position pos, Dimension dim) : m_name(name), m_position(pos), m_dimension(dim)
{
	m_windowHandle = newwin(dim.height, dim.width, pos.y, pos.x);
}

Window::~Window()
{
	if(m_windowHandle) delwin(m_windowHandle);
}

Window::Window(Window && other) : m_name(other.m_name), m_position(other.m_position), m_dimension(other.m_dimension), m_windowHandle(other.m_windowHandle)
{
	other.m_windowHandle = nullptr;
}

void Window::setDimension(const Dimension dimension)
{
	wresize(m_windowHandle, dimension.height, dimension.width);
	m_dimension = dimension;
}

void Window::setPosition(const Position position)
{
	mvwin(m_windowHandle, position.y, position.x);
	m_position = position;
}
