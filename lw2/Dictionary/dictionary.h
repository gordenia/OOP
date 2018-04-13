#pragma once
#include <string>
#include <map>
#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <Windows.h>
#include <algorithm>

typedef std::map<std::string, std::string> Dictionary;

std::ifstream OpenFileForReading(const std::string& fileName);

void ProcessInputString(const std::string &inputString, Dictionary &dictionary, bool &dictionaryChange);

void AddWordToDictionary(const std::string &word, const std::string &translation, Dictionary &dictionary);

void AddNewWord(const std::string &inputString, Dictionary &dictionary, bool &dictionaryChange);

std::string FindWordInDictionary(const std::string &word, Dictionary &dictionary);

void CopyFileToDictionary(std::ifstream &inputFile, Dictionary &dictionary);

void SaveDictionaryToFile(std::ofstream &inputFile, Dictionary &dictionary);

void MakeChangeToDictionary(std::string &fileName, Dictionary &dictionary);

void TranslateText(std::string &inputFileName, Dictionary &dictionary);
