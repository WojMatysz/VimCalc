#include "sheetDataStorage.hpp"

using namespace core;

std::optional<Cell> SheetDataStorage::get(const CellId & id) const
{ 
	auto iterator = m_data.find(id);
	if(iterator != m_data.end()) return iterator->second;
	return std::nullopt;
}

std::optional<Cell> SheetDataStorage::replace(const CellId & id, const Cell & cell)
{
	auto iterator = m_data.find(id);
	if(iterator != m_data.end())
	{
		auto oldCell = std::move(iterator->second);
		iterator->second = cell;
		return oldCell;
	}
	return std::nullopt;
}

bool SheetDataStorage::insert(const CellId & id, const Cell & cell)
{
	return m_data.try_emplace(id, cell).second; // try_emplace returns a pair of {iterator, bool}
}


std::optional<Cell> SheetDataStorage::upsert(const CellId & id, const Cell & cell)
{
    auto [iterator, inserted] = m_data.try_emplace(id, cell);

    if(!inserted)
    {
        auto oldCell = std::move(iterator->second);
        iterator->second = cell;
        return oldCell;
    }

    return std::nullopt;
}


void SheetDataStorage::remove(const CellId & id)
{
	m_data.erase(id);
}
