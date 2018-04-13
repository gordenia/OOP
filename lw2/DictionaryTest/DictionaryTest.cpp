#include "stdafx.h"
#include "../Dictionary/dictionary.h"

bool IsEqual(const std::string &x, const std::string &y)
{
	return x == y;
}

TEST_CASE("Add and search for a word in the dictionary")
{
	Dictionary dictionary;
	AddWordToDictionary("hamster", "�����", dictionary);
	auto word = FindWordInDictionary("hamster", dictionary);
	CHECK(IsEqual(word, "�����"));

	auto word1 = FindWordInDictionary("�����", dictionary);
	CHECK(IsEqual(word1, "hamster"));

	dictionary.clear();
	AddWordToDictionary("hamster", "�����", dictionary);
	auto word2 = FindWordInDictionary("cat", dictionary);
	CHECK(IsEqual(word2, ""));

	dictionary.clear();
	AddWordToDictionary("hamster", "�����", dictionary);
	AddWordToDictionary("hamster", "�������", dictionary);
	auto word3 = FindWordInDictionary("hamster", dictionary);
	CHECK(IsEqual(word3, "�����"));
}