#include "stdafx.h"
#include "../Dictionary/dictionary.h"

bool IsEqual(const std::string &x, const std::string &y)
{
	return x == y;
}

TEST_CASE("Add and search for a word in the dictionary")
{
	Dictionary dictionary;
	AddWordToDictionary("hamster", "хомяк", dictionary);
	auto word = FindWordInDictionary("hamster", dictionary);
	CHECK(IsEqual(word, "хомяк"));

	auto word1 = FindWordInDictionary("хомяк", dictionary);
	CHECK(IsEqual(word1, "hamster"));

	dictionary.clear();
	AddWordToDictionary("hamster", "хомяк", dictionary);
	auto word2 = FindWordInDictionary("cat", dictionary);
	CHECK(IsEqual(word2, ""));

	dictionary.clear();
	AddWordToDictionary("hamster", "хомяк", dictionary);
	AddWordToDictionary("hamster", "хомячок", dictionary);
	auto word3 = FindWordInDictionary("hamster", dictionary);
	CHECK(IsEqual(word3, "хомяк"));
}