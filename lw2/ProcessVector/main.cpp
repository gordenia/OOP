#include "stdafx.h"
#include "ProcessVector.h"


int main()
{
	std::vector<double> numbers;

	numbers = GetVector(std::cin);
	ProcessVector(numbers);
	std::sort(numbers.begin(), numbers.end());
	PrintVector(std::cout, numbers);

	return 0;
}

