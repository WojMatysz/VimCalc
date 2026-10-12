#include "formater.hpp"

#include "format/bold.hpp"
#include "format/italic.hpp"
#include "format/underline.hpp"

using namespace tui;

std::vector<std::unique_ptr<FormatAttribute>> Formater::apply(const Format & format) const
{
	std::vector<std::unique_ptr<FormatAttribute>> attributes;
	attributes.reserve(5);

	if(format.bold) attributes.push_back(std::move(std::make_unique<Bold>()));
	if(format.italic) attributes.push_back(std::move(std::make_unique<Italic>()));
	if(format.underline) attributes.push_back(std::move(std::make_unique<Underline>()));

	return attributes;
}
