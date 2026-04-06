#pragma once

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
		VerticalAlignment vertical;
		HorizontalAlignment horizontal;
	};
}
