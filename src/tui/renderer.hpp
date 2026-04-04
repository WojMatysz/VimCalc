#pragma once

#include "windowManager.hpp"

namespace tui
{
	class Renderer
	{
	public:
		Renderer(const WindowManager & windowManager);
		void render() const;
	private:
		void render(const Window & window) const;

		const WindowManager & m_windowManager;
	};
}
