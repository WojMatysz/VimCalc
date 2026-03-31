#pragma once

#include "../core/core.hpp"
#include "ui.hpp"

namespace interface
{
	class CoreUiControler
	{
	public:
		CoreUiControler(const core::Core * core, const Ui * ui) : m_core(core), m_ui(ui) {};
	private:
		const core::Core * m_core;
		const Ui * m_ui;
	};
}
