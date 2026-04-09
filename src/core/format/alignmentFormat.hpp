#pragma once

#include <optional>

namespace core
{
	enum class VerticalAlignment
	{
		Top,
		Center,
		Bottom
	};

	enum class HorizontalAlignment
	{
		Left,
		Center,
		Right
	};

	struct AlignmentFormat
	{
		std::optional<VerticalAlignment> vertical;
		std::optional<HorizontalAlignment> horizontal;
	};
}
