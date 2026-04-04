#include "tui.hpp"

using namespace tui;

Tui::Tui() : m_screenView(stdscr), m_renderer(Renderer(m_windowManager))
{
}

void Tui::run()
{
	Window inputFormulaWindow{"InputWindow", Position{0, 0}, Dimension{10, 2}};
	Window sheetWindow{"SheetWindow", Position{0, 2}, Dimension{10, 20}};
	Window statusBarWindow{"StatusBarWindow", Position{0, 22}, Dimension{10, 1}};
	Window commandBarWindow{"CommandBarWindow", Position{0, 23}, Dimension{10, 1}};

	Dimension screenDimension = m_screenView.getDimension();
	int inputWindowHeight = 2;
	int statusBarWindowHeight = 1;
	int commandBarWindowHeight = 1;

	inputFormulaWindow.setDimension(Dimension{screenDimension.width, inputWindowHeight});

	sheetWindow.setDimension({screenDimension.width, screenDimension.height - inputWindowHeight - statusBarWindowHeight});

	statusBarWindow.setDimension(Dimension{screenDimension.width, statusBarWindowHeight});
	statusBarWindow.setPosition(Position{0, screenDimension.height - statusBarWindowHeight - commandBarWindowHeight});

	commandBarWindow.setDimension(Dimension{screenDimension.width, commandBarWindowHeight});
	commandBarWindow.setPosition(Position{0, screenDimension.height - commandBarWindowHeight});

	m_windowManager.addWindow(inputFormulaWindow);
	m_windowManager.addWindow(sheetWindow);
	m_windowManager.addWindow(statusBarWindow);
	m_windowManager.addWindow(commandBarWindow);

	while(true)
	{
		//geting input
		int input = m_ncurses.getInput();
		if(input == (int)('q')) break;

		m_renderer.render();
	}
}
