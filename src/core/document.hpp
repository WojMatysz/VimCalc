#pragma once

#include <string>

#include "sheet.hpp"

namespace core
{
	class Document
	{
	public:
		Document() {}
	private:
		std::string m_name;
		Sheet m_sheet;
	};
}
