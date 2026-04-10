#pragma once

#include <unordered_map>
#include <optional>

#include "cellId.hpp"
#include "cell.hpp"

namespace core
{
	class SheetDataStorage
	{
	public:
		std::optional<Cell> get(const CellId & id) const;
		std::optional<Cell> replace(const CellId & id, const Cell & cell); // Returns previous Cell data; faild if not exists
		bool insert(const CellId & id, const Cell & cell); // Faild if id is occupied (already exists)
		std::optional<Cell> upsert(const CellId & id, const Cell & cell); // Update and insert, returns previous Cell data

		void remove(const CellId  & id);

	private:
		std::unordered_map<CellId, Cell> m_data;
	};
}
