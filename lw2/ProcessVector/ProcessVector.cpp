#include "stdafx.h"
#include "ProcessVector.h"
#include <iterator>
#include <iostream>

std::vector<double> GetVector(std::istream &input)
{
	std::vector<double> numbers(std::istream_iterator<double>(input), (std::istream_iterator<double>()));
	return numbers;
}

void ProcessVector(std::vector<double> &numbers)
{
	if (numbers.empty())
	{
		return;
	}

	const double minElement = *std::min_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) {return number = number * minElement; });
}

void PrintVector(std::ostream &output, const std::vector<double> &numbers)
{
	std::cout << std::fixed << std::setprecision(3);
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<double>(output, " "));
	std::cout << std::endl;
}