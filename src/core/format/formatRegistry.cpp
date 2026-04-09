#include "formatRegistry.hpp"

using namespace core;

std::optional<Format> FormatRegistry::get(const FormatId & id)
{
	auto iterator = m_registry.find(id);
	if(iterator != m_registry.end()) return iterator->second;
	return std::nullopt;
}

FormatId FormatRegistry::add(const Format & format)
{
	FormatId id{0};
	if(!m_freeIds.empty())
	{
		id = m_freeIds.back();
		m_freeIds.pop_back();
	}
	else
	{
		id = m_nextNewId;
		++m_nextNewId;
	}

	m_registry[id] = format;
	return id;
}

void FormatRegistry::remove(const FormatId & id)
{
	auto iterator = m_registry.find(id);
	if(iterator != m_registry.end())
	{
		m_registry.erase(iterator);
		m_freeIds.push_back(iterator->first);
	}
}
