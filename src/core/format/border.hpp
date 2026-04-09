#pragma once

namespace core
{
	enum class BorderType
	{
		None,
		Line,
		DoubleLine,
		Dotted
	};

	struct Border
	{
		BorderType type;
		int size;
	};
}
