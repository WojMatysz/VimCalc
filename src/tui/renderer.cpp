#include "renderer.hpp"

#include "format/bold.hpp"
#include "format/italic.hpp"
#include "format/underline.hpp"

using namespace tui;

Renderer::Renderer(const WindowManager & windowManager, Formater & formater) 
	: m_windowManager(windowManager), m_formater(formater)
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
	CellFormat format{.width = 10, .height = 3};
	format.bold = true;
	format.italic = true;
	format.underline = true;
	render(CellData("Hello"), Position(100, 10), format);
}

void Renderer::render(const CellData & data, const Position & cellPosition, const CellFormat & format) const
{
	// Render border
	render(cellPosition, Dimension{format.width, format.height});
	
	// Formanting
	const auto scopeAttributes = m_formater.apply(format);
	
	// Insert string to the cell
	render(data, cellPosition, format.width);
}

void Renderer::render(const CellData & data, const Position & cellPosition, const int & width) const
{
	mvaddnstr(cellPosition.y + 1, cellPosition.x + 1, data.data.c_str(), width - 2);
	refresh();
}

void Renderer::render(const Position & cellPosition, const Dimension & cellSize) const
{
	// Border's corners
	mvaddch(cellPosition.y, cellPosition.x, '+');
	mvaddch(cellPosition.y, cellPosition.x + cellSize.width - 1, '+');
	mvaddch(cellPosition.y + cellSize.height - 1, cellPosition.x, '+');
	mvaddch(cellPosition.y + cellSize.height - 1, cellPosition.x + cellSize.width - 1, '+');

	// Border's edges
	mvhline(cellPosition.y, cellPosition.x + 1, '-', cellSize.width - 2);
	mvhline(cellPosition.y + cellSize.height - 1, cellPosition.x + 1, '-', cellSize.width - 2);
	mvvline(cellPosition.y + 1, cellPosition.x, '|', cellSize.height - 2);
	mvvline(cellPosition.y + 1, cellPosition.x + cellSize.width - 1, '|', cellSize.height - 2);
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
