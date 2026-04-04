#pragma once

#include <string>

#include "position.hpp"
#include "dimension.hpp"
#include "ncurses.hpp"

namespace tui
{
	class Window
	{
	public:
		Window(const std::string name, Position pos, Dimension dim);
		~Window();
	
		Window(const Window &) = delete;
		Window & operator=(const Window &) = delete;

		Window(Window && other);

		WINDOW * getWindowHandle() const { return m_windowHandle; }

		void setDimension(const Dimension dimension);
		void setPosition(const Position position);

		const Dimension & getDimension() const { return m_dimension; }
		const Position & getPosition() const { return m_position; }
		const std::string & getName() const { return m_name; }

	private:
		std::string m_name;
		Position m_position;
		Dimension m_dimension;
		WINDOW * m_windowHandle;
	};
}
