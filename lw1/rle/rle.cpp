#include "stdafx.h"

struct counter
{
	char character;
	uint8_t countCharacters = 0;
};

std::ifstream OpenFileForBinReading(const std::string& fileName)
{
	std::ifstream strm(fileName, std::ios_base::binary);
	
	if (!strm.is_open())
		std::cout << "Failed to open " << fileName << "\n";

	return move(strm);
}

std::ofstream OpenFileForBinWriting(const std::string& fileName)
{
	std::ofstream strm(fileName, std::ios_base::binary);
	if (!strm.is_open())
		std::cout << "Failed to open " << fileName << "\n";

	return move(strm);
}

bool StartCounter(std::istream& inputFile, counter& counterState)
{
	if (inputFile.get(counterState.character))
	{
		counterState.countCharacters = 1;
		return true;
	}
	else
		return false;
}

void FlushCounter(std::ostream& outputFile, counter& counterState)
{
	outputFile.put(static_cast<char>(counterState.countCharacters));
	outputFile.put(counterState.character);
}

void UpdateCounter(std::ostream& outputFile, counter& counterState, char currentCharacter)
{
	if ((currentCharacter != counterState.character) || (counterState.countCharacters == 255))
	{ 
		FlushCounter(outputFile, counterState);

		counterState.character = currentCharacter;
		counterState.countCharacters = 1;
	}
	else
	{
		++counterState.countCharacters;
	}
}

bool GetTwoBytes(std::istream& inputFile, counter& counterState, bool& wasError)
{
	char countCharacters;

	if (!inputFile.get(countCharacters))
	{
		return false;
	}
	
	if ((static_cast<uint8_t>(countCharacters) == 0) || (!inputFile.get(counterState.character)))
	{
		wasError = true;
		return false;
	}
	else
	{
		counterState.countCharacters = static_cast<uint8_t>(countCharacters);
	}

	return true;
}

void WriteSequenceOfBytes(std::ostream& outputFile, counter& counterState)
{
	while (counterState.countCharacters)
	{
		outputFile.put(counterState.character);
		--counterState.countCharacters;
	}
}

bool Packing(std::istream& inputFile, std::ostream& outputFile)
{
	char currentCharacter;
	counter counterState;
	
	if (StartCounter(inputFile, counterState))
	{
		while (inputFile.get(currentCharacter))
		{
			UpdateCounter(outputFile, counterState, currentCharacter);
		}
		
		FlushCounter(outputFile, counterState);
	}

	outputFile.flush();

	return true;
}

bool Unpacking(std::istream& inputFile, std::ostream& outputFile)
{
	counter counterState;
	bool wasError = false;

	while (GetTwoBytes(inputFile, counterState, wasError))
	{
		WriteSequenceOfBytes(outputFile, counterState);
	}

	outputFile.flush();

	return !wasError;
}

bool Compression(const std::string& mode, const std::string& inputFileName, const std::string& outputFileName)
{
	if ((mode != "pack") && (mode != "unpack"))
	{
		std::cout << "Invalid pack/unpack argument" << std::endl;
		return false;
	}

	if (inputFileName == outputFileName)
	{
		std::cout << "Incoming and outgoing files are the same" << std::endl;
		return false;
	}

	std::ifstream inputFile;
	inputFile = OpenFileForBinReading(inputFileName);

	if (!inputFile)
	{
		return false;
	}

	std::ofstream outputFile;
	outputFile = OpenFileForBinWriting(outputFileName);

	if (!outputFile)
	{
		return false;
	}

	if ((mode == "pack") && (Packing(inputFile, outputFile)))
	{
		return true;
	}

	if ((mode == "unpack") && (Unpacking(inputFile, outputFile)))
	{
		return true;
	}

	std::cout << "compression/decompression failed" << std::endl;
	return false;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: rle.exe <moode> <input file> <output file>" << std::endl;
		return 1;
	}

	std::string mode = argv[1];
	std::string inputFileName = argv[2];
	std::string outputFileName = argv[3];

	if (!Compression(mode, inputFileName, outputFileName))
	{
		return 1;
	}
	
	return 0;
}