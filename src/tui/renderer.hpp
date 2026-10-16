#pragma once

#include "windowManager.hpp"
#include "formater.hpp"
#include "format/cellFormat.hpp"
#include "cellData.hpp"
#include "dimension.hpp"
#include "uiElementManager.hpp"

namespace tui
{
	class Renderer
	{
	public:
		Renderer(const WindowManager & windowManager, Formater & formater, const UiElementManager & uiElementManager);
		void render() const;
	private:
		void render(const Window & window, int color) const;
		void render(const CellData & data, const Position & cellPosition, const CellFormat & format) const;
		void render(const Position & cellPosition, const Dimension & cellSize) const;
		void render(const CellData & data, const Position & cellPosition, const int & width) const;

		const WindowManager & m_windowManager;
		const Formater & m_formater;
		const UiElementManager & m_uiElementManager;
	};
}
