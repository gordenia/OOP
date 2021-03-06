#include "stdafx.h"

uint8_t FlipByte(uint8_t inputByte)
{
	uint8_t outputByte;

	outputByte = ((inputByte & 0b11110000) >> 4) | ((inputByte & 0b00001111) << 4);
	outputByte = ((outputByte & 0b11001100) >> 2) | ((outputByte & 0b00110011) << 2);
	outputByte = ((outputByte & 0b10101010) >> 1) | ((outputByte & 0b01010101) << 1);

	return outputByte;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: flipbyte.exe <input byte>" << std::endl;
		return 1;
	}

	int inputByte;
	int outputByte;

	try
	{
		inputByte = std::stoi(argv[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	if ((inputByte < 0) || (inputByte > 255))
	{
		std::cout << "Invalid number\n"
			<< "Use a number between 0 and 255" << std::endl;
		return 1;
	}

	outputByte = static_cast<int>(FlipByte(static_cast<uint8_t>(inputByte)));

	std::cout << outputByte << std::endl;

	return 0;
}