#pragma once

#include <optional>

//#include "dataFormat.hpp"
#include "colorFormat.hpp"
#include "fontFormat.hpp"
#include "borderFormat.hpp"
#include "alignmentFormat.hpp"

namespace core
{
	struct Format
	{
		//std::optional<DataFormat> data;
		std::optional<ColorFormat> color;
		std::optional<FontFormat> font;
		std::optional<BorderFormat> border;
		std::optional<AlignmentFormat> alignment;
	};

	template <typename T>
		constexpr std::optional<T> mergeOptional(const std::optional<T> & first, const std::optional<T> & second)
		{
			if(second) return second;
			else return first;
		}

	constexpr std::optional<ColorFormat> mergeOptional(const std::optional<ColorFormat> & first, const std::optional<ColorFormat> & second)
	{
		if(!first) return second;
		if(!second) return first;

		ColorFormat result{};

		result.background = mergeOptional(first->background, second->background);
		result.text = mergeOptional(first->text, second->text);
		result.highlight = mergeOptional(first->highlight, second->highlight);

		return result;
	}

	constexpr std::optional<BorderFormat> mergeOptional(const std::optional<BorderFormat> & first, const std::optional<BorderFormat> & second)
	{
		if(!first) return second;
		if(!second) return first;

		BorderFormat result{};

		result.top = mergeOptional(first->top, second->top);
		result.bottom = mergeOptional(first->bottom, second->bottom);
		result.left = mergeOptional(first->left, second->left);
		result.right = mergeOptional(first->right, second->right);

		return result;
	}

	constexpr std::optional<AlignmentFormat> mergeOptional(const std::optional<AlignmentFormat> & first, const std::optional<AlignmentFormat> & second)
	{
		if(!first) return second;
		if(!second) return first;

		AlignmentFormat result{};

		result.vertical = mergeOptional(first->vertical, second->vertical);
		result.horizontal = mergeOptional(first->horizontal, second->horizontal);

		return result;
	}

	constexpr std::optional<FontFormat> mergeOptional(const std::optional<FontFormat> & first, const std::optional<FontFormat> & second)
	{
		if(!first) return second;
		if(!second) return first;

		FontFormat result{};

		result.bold = mergeOptional(first->bold, second->bold);
		result.underline = mergeOptional(first->underline, second->underline);
		result.italic = mergeOptional(first->italic, second->italic);
		result.strikethrough = mergeOptional(first->strikethrough, second->strikethrough);

		return result;
	}

	[[nodiscard]] constexpr Format merge(const Format & first, const Format & second)
	{
		Format result{};

		//result.data = mergeOptional(first.data, second.data);
		result.color = mergeOptional(first.color, second.color);
		result.font = mergeOptional(first.font, second.font);
		result.border = mergeOptional(first.border, second.border);
		result.alignment = mergeOptional(first.alignment, second.alignment);

		return result;
	}

	[[nodiscard]] constexpr Format operator|(const Format & first, const Format & second)
	{
		return merge(first, second);
	}
}
