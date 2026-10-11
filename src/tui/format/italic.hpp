#pragma once

#include "formatAttribute.hpp"

namespace tui
{
	struct Italic
		: public FormatAttribute
	{
		Italic() { attron(A_ITALIC); }
		~Italic() { attroff(A_ITALIC); }
	};
}
