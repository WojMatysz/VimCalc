#pragma once

#include "format.hpp"

namespace tui
{
	struct CellFormat
		:public Format
	{
		int width;
		int height;
	};
}
