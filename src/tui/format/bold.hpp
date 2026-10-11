#pragma once

#include "formatAttribute.hpp"

namespace tui
{
	struct Bold
		: public FormatAttribute
	{
		Bold() { attron(A_BOLD); }
		~Bold() { attroff(A_BOLD); }
	};
}
