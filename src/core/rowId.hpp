#pragma once

#include <cstdint>

namespace core
{
	struct RowId
	{
		std::uint32_t value;
		constexpr explicit RowId(std::uint32_t row) : value(row) {}
		constexpr bool operator==(const RowId &) const = default;
	};
}
