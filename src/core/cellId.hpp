#pragma once

#include <cstdint>
#include <functional>

#include "columnId.hpp"
#include "rowId.hpp"

namespace core
{
	struct CellId
	{
		std::uint64_t value;

		CellId(RowId rowId, ColumnId columnId)
			: value((static_cast<std::uint64_t>(rowId.value) << 32) | columnId.value) {}

		constexpr bool operator==(const CellId &) const = default;
	};
}

template <>
struct std::hash<core::CellId>
{
	size_t operator()(const core::CellId & id) const noexcept
	{
		return std::hash<std::uint64_t>{}(id.value);
	}
};
