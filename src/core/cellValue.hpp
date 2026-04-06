#pragma once

#include "formula.hpp"
#include "valueType.hpp"

namespace core
{
	struct CellValue
	{
		ValueType valueType;
		float numericValue;
		std::string stringValue;
		Formula formulaValue;
	};
}
