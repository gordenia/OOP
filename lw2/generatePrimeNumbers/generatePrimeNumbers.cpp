#include "stdafx.h"
#include "generatePrimeNumbers.h"
#include <iostream>
#include <set>
#include <iterator>

bool GetNumber(const std::string &arg, int &upperBound)
{
	try
	{
		upperBound = std::stoi(arg);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}

	if ((upperBound < 1) || (upperBound > 100000000))
	{
		std::cout << "Invalid upper bound number\n"
			<< "Use a number between 1 and 100000000" << std::endl;
		return false;
	}

	return true;
}

void UseSieveErythosthene(std::vector<bool> &numbers)
{
	for (size_t i = 2; i * i <= numbers.size(); ++i)
	{
		if (numbers[i])
		{
			for (size_t j = i * i; j <= numbers.size(); j += i)
			{
				numbers[j] = false;
			}
		}
	
	}
}

std::set<int> GetPrimeNumbers(const std::vector<bool> &numbers)
{
	std::set<int> primeNumbers;

	for (size_t i = 2; i < numbers.size(); ++i)
	{
		if (numbers[i])
		{
			primeNumbers.emplace_hint(primeNumbers.end(), i);
		}
	}
	
	return primeNumbers;
}

void PrintPrimeNumbers(std::ostream &output, const std::set<int> &primeNumbers)
{
	std::copy(primeNumbers.begin(), primeNumbers.end(), std::ostream_iterator<int>(output, " "));
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
	std::vector<bool> numbers(upperBound + 1, true);
	UseSieveErythosthene(numbers);

	std::set<int> primeNumbers = GetPrimeNumbers(numbers);

	return primeNumbers;
}