#include "stdafx.h"
#include "dictionary.h"

std::ifstream OpenFileForReading(const std::string& fileName)
{
	std::ifstream strm(fileName);

	if (!strm.is_open())
		std::cout << "Failed to open " << fileName << "\n";

	return strm;
}

void AddWordToDictionary(const std::string &word, const std::string &translation, Dictionary &dictionary)
{
	dictionary.insert({ word, translation });
	dictionary.insert({ translation, word });
}

std::string FindWordInDictionary(const std::string &word, Dictionary &dictionary)
{
	auto pairWordTranslation = dictionary.find(word);

	if (pairWordTranslation != dictionary.end())
	{
		return {(*pairWordTranslation).second};
	}
	else
		return {};
}

void CopyFileToDictionary(std::ifstream &inputFile, Dictionary &dictionary)
{
	std::string word, translation;

	dictionary.clear();

	while (getline(inputFile, word) && (getline(inputFile, translation)))
	{
		std::string foundWord = FindWordInDictionary(word, dictionary);

		if (foundWord.empty())
		{
			AddWordToDictionary(word, translation, dictionary);
		}
	}
}

void SaveDictionaryToFile(std::ofstream &inputFile, Dictionary &dictionary)
{
	for (auto &word : dictionary)
	{
		inputFile << word.first << std::endl << word.second << std::endl;
	}
}

void AddNewWord(const std::string &word, Dictionary &dictionary, bool &dictionaryChange)
{
	std::cout << "����������� ����� \"" << word << "\". ������� ������� ��� ������ ������ ��� ������." << std::endl;
	std::cout << ">";
	std::string translation;
	getline(std::cin, translation);

	if (!translation.empty())
	{
		AddWordToDictionary(word, translation, dictionary);
		std::cout << "����� \"" << word << "\" ��������� � ������� ��� \"" << translation << "\"." << std::endl;
		dictionaryChange = true;
	}
	else
	{
		std::cout << "����� \"" << word << "\" ���������������." << std::endl;
		dictionaryChange = false;
	}
}

void ProcessInputString(const std::string &inputString, Dictionary &dictionary, bool &dictionaryChange)
{
	std::string foundWord = FindWordInDictionary(inputString, dictionary);

	if (!foundWord.empty())
	{
		std::cout << foundWord << std::endl;
	}
	else 
	{
		AddNewWord(inputString, dictionary, dictionaryChange);
	}
}

void MakeChangeToDictionary(std::string &inputFileName, Dictionary &dictionary)
{
	char exit;
	std::cout << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������." << std::endl;

	std::cout << ">";
	std::cin >> exit;

	if ((exit == 'Y') ||( exit == 'y'))
	{
		if (inputFileName.empty())
		{
			std::cout << "������� �������� �������." << std::endl;
			std::cout << ">";
			std::cin >> inputFileName;
		}

		std::ofstream inputFile(inputFileName);
		SaveDictionaryToFile(inputFile, dictionary);
		std::cout << "��������� ���������. �� ��������." << std::endl;
	}
	else
	{
		std::cout << "��������� �� ���������. �� ��������." << std::endl;
	}
}

void TranslateText(std::string &inputFileName, Dictionary &dictionary)
{
	std::string inputString;
	bool dictionaryChange = false;

	while (inputString != "...")
	{
		std::cout << ">";
		getline(std::cin, inputString);

		if ((inputString != "...") && (inputString != ""))
		{
			ProcessInputString(inputString, dictionary, dictionaryChange);
		}
	}

	if (dictionaryChange)
	{
		MakeChangeToDictionary(inputFileName, dictionary);
	}
	else
	{
		std::cout << "���������� ������ �� ��������" << std::endl;
	}
}
