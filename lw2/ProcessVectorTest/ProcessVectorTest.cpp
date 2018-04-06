#include "stdafx.h"
#include "../ProcessVector/ProcessVector.h"

bool IsEqually(const std::vector<double> &input, const std::vector<double> &output)
{
	return input == output;
}

TEST_CASE("input - empty vector, output - empty vector")
{
	std::vector<double> numbers = {};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {}));
}

TEST_CASE("all elements are multiplied by the minimum")
{
	std::vector<double> numbers = { 10, 20, 30 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {100, 200, 300}));
}


TEST_CASE("all elements are multiplied by the minimum = 0")
{
	std::vector<double> numbers = {5, 0, 5.5};
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {0, 0, 0}));
}


TEST_CASE("all elements are multiplied by the minimum(double elements)")
{
	std::vector<double> numbers = { -3.1, 2.1, 3.7 };
	ProcessVector(numbers);
	CHECK(IsEqually(numbers, {(-3.1*(-3.1)), (2.1*(-3.1)), (3.7*(-3.1))}));
}
