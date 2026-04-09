#pragma once

#include <optional>

// #include "font.hpp"

namespace core
{
	struct FontFormat
	{
		//std::optional<Font> font;
		std::optional<bool> bold;
		std::optional<bool> underline;
		std::optional<bool> italic;
		std::optional<bool> strikethrough;
	};
}
