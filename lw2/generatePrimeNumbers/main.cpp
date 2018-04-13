#include "stdafx.h"
#include "generatePrimeNumbers.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: generatePrimeNumber.exe <upper bound>" << std::endl;
		return 1;
	}

	int upperBound;

	if (!GetNumber(argv[1], upperBound))
	{
		return 1;
	}

	std::set<int> primeNumbers = GeneratePrimeNumbersSet(upperBound);
	PrintPrimeNumbers(std::cout, primeNumbers);

	return 0;
}

