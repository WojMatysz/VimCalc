#pragma once

#include "cellValue.hpp"
#include "format/format.hpp"

namespace core
{
	struct Cell
	{
		CellValue value;
		Format format;
	};
}
