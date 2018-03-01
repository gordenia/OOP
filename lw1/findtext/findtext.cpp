#include "stdafx.h"

void PrintNumberLine(int result)
{
	std::cout << result << "\n";
}

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

bool FindText(std::istream& input, const std::string& searchString)
{
	std::string line;
	int numberLine = 0;
	bool textFind = false;

	while (std::getline(input, line))
	{
		numberLine++;

		if (FindString(line, searchString))
		{
			PrintNumberLine(numberLine);
			textFind = true;
		}
	}

	return textFind;
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

	if (!inputFile)
	{
		std::cout << "File not found\n";
		return 1;
	}

	if (!FindText(inputFile, search))
	{
		std::cout << "Text not found\n";
		return 1;
	}

	inputFile.close();
	return 0;
}