#pragma once

#include "ncurses.hpp"

#include "../interface/ui.hpp"
#include "window.hpp"
#include "screenView.hpp"
#include "windowManager.hpp"
#include "renderer.hpp"

namespace tui
{
	class Tui
		:public interface::Ui
	{
	public:
		Tui();
		void run() override;
	private:
		Ncurses m_ncurses;
		ScreenView m_screenView;
		WindowManager m_windowManager;
		Renderer m_renderer;
	};
}
