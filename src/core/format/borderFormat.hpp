#pragma once

#include <optional>

#include "border.hpp"

namespace core
{
	struct BorderFormat
	{
		std::optional<Border> top;
		std::optional<Border> bottom;
		std::optional<Border> left;
		std::optional<Border> right;
	};
}
