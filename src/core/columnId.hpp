#pragma once

#include <cstdint>

namespace core
{
	struct ColumnId
	{
		std::uint32_t value;
		constexpr explicit ColumnId(std::uint32_t column) : value(column) {}
		constexpr bool operator==(const ColumnId &) const = default;
	};
}

