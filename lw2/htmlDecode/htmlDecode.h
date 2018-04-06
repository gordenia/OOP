#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

struct PairSearchReplace
{
	std::string searchElement;
	std::string replaceableElement;
};

std::string HtmlDecode(const std::string &html);
