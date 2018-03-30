#include "stdafx.h"
#include "ProcessVector.h"


int main()
{
	std::vector<double> numbers;

	GetVector(std::cin, numbers);
	ProcessVector(numbers);
	std::sort(numbers.begin(), numbers.end());
	PrintVector(std::cout, numbers);

	return 0;
}

