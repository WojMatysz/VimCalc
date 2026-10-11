#pragma once

#include "color.hpp"

namespace tui
{
	struct Format
	{
		Color backgroungColor;
		Color textColor;
		Color highlight;
		bool bold;
		bool underline;
		bool italic;
		bool strikethrough;
		bool topBorder;
		bool bottomBorder;
		bool leftBorder;
		bool rightBorder;
	};
}
