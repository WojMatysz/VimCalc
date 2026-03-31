#pragma once

#include "ncurses.hpp"

#include "../interface/ui.hpp"

namespace tui
{
	class Tui
		:public interface::Ui
	{
	public:
		Tui() {};
		void run() override;
	private:
		Ncurses m_ncurses;
	};
}
