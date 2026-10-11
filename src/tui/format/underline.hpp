#pragma once

#include "formatAttribute.hpp"

namespace tui
{
	struct Underline
		: public FormatAttribute
	{
		Underline() { attron(A_UNDERLINE); }
		~Underline() { attroff(A_UNDERLINE); }
	};
}
