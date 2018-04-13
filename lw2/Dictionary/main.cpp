#include "stdafx.h"
#include "dictionary.h"


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string fileName;
	Dictionary dictionary;

	if (argc == 2)
	{
		fileName = argv[1];

		std::ifstream inputFile;
		inputFile = OpenFileForReading(fileName);

		if (inputFile)
		{
			CopyFileToDictionary(inputFile, dictionary);
			inputFile.close();
		}
	}
	else
	{
		fileName = "";
	}

	TranslateText(fileName, dictionary);
	return 0;
}
