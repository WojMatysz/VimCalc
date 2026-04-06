#pragma once

#include <optional>

//#include "dataFormat.hpp"
#include "colorFormat.hpp"
#include "fontFormat.hpp"
#include "borderFormat.hpp"
#include "alignmentFormat.hpp"

namespace core
{
	struct Format
	{
		//std::optional<DataFormat> data;
		std::optional<ColorFormat> color;
		std::optional<FontFormat> font;
		std::optional<BorderFormat> border;
		std::optional<AlignmentFormat> alignment;
	};
}
