#pragma once

#include <vector>
#include <memory>

#include "format/format.hpp"
#include "format/formatAttribute.hpp"

namespace tui
{
	class Formater
	{
	public:
		std::vector<std::unique_ptr<FormatAttribute>> apply(const Format & format) const;
	};
}
