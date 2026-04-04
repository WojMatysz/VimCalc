#pragma once

#include <vector>

#include "window.hpp"

namespace tui
{
	class WindowManager
	{
	public:
		WindowManager() {}
		void addWindow(Window & window);
		const std::vector<Window> & getWindows() const { return m_windows; }

	private:
		std::vector<Window> m_windows;
	};
}
