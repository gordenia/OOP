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

Dictionary LoadDictionary(const std::string &fileName);

void ProcessInputString(const std::string &inputString, Dictionary &dictionary, bool &dictionaryChange);

void AddTranslation(const std::string &word, const std::string &translation, Dictionary &dictionary);

void AddNewWord(const std::string &inputString, Dictionary &dictionary, bool &dictionaryChange);

std::string FindTranslation(const std::string &word, const Dictionary &dictionary);

Dictionary ReadDictionary(std::istream &inputFile);

void WriteDictionary(std::ostream &inputFile, Dictionary &dictionary);

void SaveDictionary(std::string fileName, Dictionary &dictionary);

bool ProcessUserInput(Dictionary &dictionary);
