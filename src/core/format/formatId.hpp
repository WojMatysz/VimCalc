#pragma once

#include <cstdint>
#include <functional>

namespace core
{
	struct FormatId
	{
		std::uint16_t value{};

		constexpr explicit FormatId(std::uint16_t id) : value(id) {}
		constexpr bool operator==(const FormatId &) const = default;
		FormatId & operator++()
		{
			++value;
			return *this;
		}
	};
}

template <>
struct std::hash<core::FormatId>
{
	size_t operator()(const core::FormatId & id) const noexcept
	{
		return std::hash<std::uint16_t>{}(id.value);
	}
};


