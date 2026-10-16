#pragma once

#include "ncurses.hpp"

#include "../interface/ui.hpp"
#include "window.hpp"
#include "screenView.hpp"
#include "windowManager.hpp"
#include "renderer.hpp"
#include "uiElementManager.hpp"

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
		Formater m_formater;
		UiElementManager m_uiElementManager;
	};
}
