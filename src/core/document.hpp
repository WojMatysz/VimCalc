#pragma once

#include <string>

#include "sheet.hpp"
#include "format/formatRegistry.hpp"

namespace core
{
	class Document
	{
	public:
		Document() {}
	private:
		std::string m_name;
		Sheet m_sheet;
		FormatRegistry m_formatRegistry;
	};
}
