#include "uiElementManager.hpp"

using namespace tui;

void UiElementManager::add(const std::string & windowName, std::vector<std::unique_ptr<UiElement>> & uiElementsCollection)
{
	auto & collection = m_uiElements[windowName];
	collection.reserve(collection.size() + uiElementsCollection.size());
	collection.insert(
			collection.end(), 
			std::make_move_iterator(uiElementsCollection.begin()), 
			std::make_move_iterator(uiElementsCollection.end()));
	uiElementsCollection.clear();
}

void UiElementManager::add(const std::string & windowName, std::unique_ptr<UiElement> uiElement)
{
	m_uiElements[windowName].push_back(std::move(uiElement));
}

const std::vector<std::unique_ptr<UiElement>> & UiElementManager::getUiElements(const std::string & windowName)
{
	return m_uiElements[windowName];
}

