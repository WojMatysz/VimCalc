#pragma once

#include <optional>

#include "cellValue.hpp"
#include "format/formatId.hpp"

namespace core
{
	struct Cell
	{
		CellValue value;
		std::optional<FormatId> formatId;
	};
}
