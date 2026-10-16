#pragma once

#include <unordered_map>
#include <vector>
#include <memory>

#include "uiElement.hpp"
#include "window.hpp"

namespace tui
{
	class UiElementManager
	{
	public:

		void add(const std::string & windowName, std::vector<std::unique_ptr<UiElement>> & uiElementsCollection);
		void add(const std::string & windowName, std::unique_ptr<UiElement> uiElement);
		const std::vector<std::unique_ptr<UiElement>> & getUiElements(const std::string & windowName);
	private:
		std::unordered_map<std::string, std::vector<std::unique_ptr<UiElement>>> m_uiElements;
	};
}
