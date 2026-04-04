#include "screenView.hpp"

using namespace tui;

ScreenView::ScreenView(WINDOW * window) : m_window(window) 
{
	updateSize();
}

WINDOW * ScreenView::get() 
{ 
	return m_window;
}

void  ScreenView::updateSize() 
{ 
	getmaxyx(m_window, m_dimension.height, m_dimension.width);
}

Dimension ScreenView::getDimension() 
{
	return m_dimension;
}
