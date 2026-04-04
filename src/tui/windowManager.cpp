#include "windowManager.hpp"

using namespace tui;

void WindowManager::addWindow(Window & window)
{
	m_windows.emplace_back(std::move(window));
}
