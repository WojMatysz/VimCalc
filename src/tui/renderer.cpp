#include "renderer.hpp"

using namespace tui;

Renderer::Renderer(const WindowManager & windowManager) : m_windowManager(windowManager)
{
}

void Renderer::render(const Window & window) const
{
	wbkgd(window.getWindowHandle(), ' ' | COLOR_PAIR(1));
	werase(window.getWindowHandle());
	wrefresh(window.getWindowHandle());
}

void Renderer::render() const
{
	for(const auto & window : m_windowManager.getWindows())
	{
		render(window);
	}
}


/*
//rendering windows
wbkgd(m_inputFormulaWindow.getWindowHandle(), ' ' | COLOR_PAIR(1));
werase(m_inputFormulaWindow.getWindowHandle());

wbkgd(m_sheetWindow.getWindowHandle(), ' ' | COLOR_PAIR(2));
werase(m_sheetWindow.getWindowHandle());

wbkgd(m_statusBarWindow.getWindowHandle(), ' ' | COLOR_PAIR(3));
werase(m_statusBarWindow.getWindowHandle());

wbkgd(m_commandBarWindow.getWindowHandle(), ' ' | COLOR_PAIR(1));
werase(m_commandBarWindow.getWindowHandle());

wrefresh(m_inputFormulaWindow.getWindowHandle());
wrefresh(m_sheetWindow.getWindowHandle());
wrefresh(m_statusBarWindow.getWindowHandle());
wrefresh(m_commandBarWindow.getWindowHandle());
*/
