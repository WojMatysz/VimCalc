#pragma once

#include <optional>

#include "color.hpp"

namespace core
{
	struct ColorFormat
	{
		std::optional<Color> background;
		std::optional<Color> text;
		std::optional<Color> highlight;
	};
}
