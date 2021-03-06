#include "stdafx.h"

struct Chunk
{
	char character;
	uint8_t countCharacters = 0;
};

std::ifstream OpenFileForBinReading(const std::string& fileName)
{
	std::ifstream strm(fileName, std::ios_base::binary);
	
	if (!strm.is_open())
		std::cout << "Failed to open " << fileName << "\n";

	return strm;
}

std::ofstream OpenFileForBinWriting(const std::string& fileName)
{
	std::ofstream strm(fileName, std::ios_base::binary);
	if (!strm.is_open())
		std::cout << "Failed to open " << fileName << "\n";

	return strm;
}


void FlushChunk(std::ostream& outputFile, Chunk& chunkState)
{
	if (chunkState.countCharacters != 0)
	{
		outputFile.put(static_cast<char>(chunkState.countCharacters));
		outputFile.put(chunkState.character);
	}
}

void UpdateChunk(std::ostream& outputFile, Chunk& chunkState, char currentCharacter)
{
	if ((currentCharacter != chunkState.character) || (chunkState.countCharacters == 255) || (chunkState.countCharacters == 0))
	{ 
		FlushChunk(outputFile, chunkState);

		chunkState.character = currentCharacter;
		chunkState.countCharacters = 1;
	}
	else
	{
		++chunkState.countCharacters;
	}
}

bool ReadChunk(std::istream& inputFile, Chunk& chunkState, bool& wasError)
{
	char countCharacters;

	if (!inputFile.get(countCharacters))
	{
		return false;
	}
	
	if ((static_cast<uint8_t>(countCharacters) == 0) || (!inputFile.get(chunkState.character)))
	{
		wasError = true;
		return false;
	}
	else
	{
		chunkState.countCharacters = static_cast<uint8_t>(countCharacters);
	}

	return true;
}

void UnpackChunk(std::ostream& outputFile, Chunk& chunkState)
{
	while (chunkState.countCharacters)
	{
		outputFile.put(chunkState.character);
		--chunkState.countCharacters;
	}
}

bool Pack(std::istream& inputFile, std::ostream& outputFile)
{
	char currentCharacter;
	Chunk chunkState;
	
	while (inputFile.get(currentCharacter))
	{
		UpdateChunk(outputFile, chunkState, currentCharacter);
	}
		
	FlushChunk(outputFile, chunkState);

	outputFile.flush();

	return true;
}

bool Unpack(std::istream& inputFile, std::ostream& outputFile)
{
	Chunk ChunkState;
	bool wasError = false;

	while (ReadChunk(inputFile, ChunkState, wasError))
	{
		UnpackChunk(outputFile, ChunkState);
	}

	outputFile.flush();

	return !wasError;
}

bool ParseCommandLine(const std::string& mode, const std::string& inputFileName, const std::string& outputFileName)
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

	if ((mode == "pack") && (Pack(inputFile, outputFile)))
	{
		return true;
	}

	if ((mode == "unpack") && (Unpack(inputFile, outputFile)))
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

	if (!ParseCommandLine(mode, inputFileName, outputFileName))
	{
		return 1;
	}
	
	return 0;
}