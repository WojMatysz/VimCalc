#pragma once

#include <array>

#include "cell.hpp"

namespace core
{

	class Sheet
	{
	public:
		Sheet() {}
	private:
		std::array<std::array<Cell, 10>, 20> m_cells;

	};
}
