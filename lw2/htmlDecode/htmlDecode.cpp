#include "stdafx.h"
#include "htmlDecode.h"

const std::unordered_map<std::string, std::string> htmlEntities =
{
	{ "&quot;", "\"" },
	{ "&apos;", "'" },
	{ "&lt;", "<" },
	{ "&gt;", ">" },
	{ "&amp;", "&" }
};

void Replace(std::string &str, const std::string &serchElement, const std::string &replaceableElement)
{
	size_t foundPos = str.find(serchElement);

	while (foundPos != std::string::npos)
	{
		str.replace(foundPos, serchElement.length(), replaceableElement);
		foundPos = str.find(serchElement, foundPos + replaceableElement.length());
	}
}


std::string HtmlDecode(const std::string &html)
{
	std::string outString = html;

	for (auto& htmlEntity : htmlEntities)
	{
		Replace(outString, htmlEntity.first, htmlEntity.second);
	}

	return outString;
}
