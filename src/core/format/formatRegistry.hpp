#pragma once

#include <unordered_map>
#include <optional>
#include <vector>

#include "formatId.hpp"
#include "format.hpp"

namespace core
{
	class FormatRegistry
	{
	public:
		std::optional<Format> get(const FormatId & id);
		FormatId add(const Format & format);
		void remove(const FormatId & id);

	private:
		std::unordered_map<FormatId, Format> m_registry;
		std::vector<FormatId> m_freeIds;
		FormatId m_nextNewId{1};
	};
}
