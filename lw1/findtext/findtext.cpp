#include "stdafx.h"

bool FindString(const std::string& line, const std::string& searchString)
{
	size_t foundPos = line.find(searchString);

	if (foundPos != std::string::npos)
	{
		return true;
	}
	else
		return false;
}

bool PrintLineNumbersContainingString(std::istream& input, const std::string& searchString)
{
	std::string line;
	int lineNumber = 0;
	bool textWasFound = false;

	while (std::getline(input, line))
	{
		++lineNumber;

		if (FindString(line, searchString))
		{
			std::cout << lineNumber << "\n";
			textWasFound = true;
		}
	}

	return textWasFound;
}

int SearchTextInFile(std::istream& inputFile, const std::string& searchString)
{
	if (!inputFile)
	{
		std::cout << "File not found\n";
		return 1;
	}

	if (!PrintLineNumbersContainingString(inputFile, searchString))
	{
		std::cout << "Text not found\n";
		return 1;
	}

	return 0;
}

int main(int argc, char* argv[])
{

	if (argc != 3)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: findtext.exe <inputFile> <searchString>\n";
		return 1;
	}

	std::ifstream inputFile;

	inputFile.open(argv[1]);
	std::string search = argv[2];

	return SearchTextInFile(inputFile, search);
}