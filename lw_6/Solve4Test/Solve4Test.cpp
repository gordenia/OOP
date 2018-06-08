#include "stdafx.h"
#include "../Solve4/Solve4.h"

std::vector<double> GetRoots(EquationRoot4 const &result)
{
	std::vector<double> roots;
	for (double root : result.roots)
		roots.push_back(root);

	std::sort(roots.begin(), roots.end());

	return roots;
}

size_t GetNumberRoots(EquationRoot4 const &result)
{
	return result.numRoots;
}

TEST_CASE("throws an exception if the first coefficient is zero")
{
	CHECK_THROWS_AS(Solve4(0, 1, 1, 1 ,1), std::invalid_argument);
};

TEST_CASE("returns the maximal real root of the equation of the third degree")
{
	CHECK(Solve3(-3, 21, -19) == Approx(1).epsilon(DBL_EPSILON));
	CHECK(Solve3(0, -1, 0) == Approx(1).epsilon(DBL_EPSILON));
	CHECK(Solve3(-1, -1, -2) == Approx(2).epsilon(DBL_EPSILON));
	CHECK(Solve3(-1, 1, -1) == Approx(1).epsilon(DBL_EPSILON));
	CHECK(Solve3(3, 3, 2) == Approx(-2).epsilon(DBL_EPSILON));
	CHECK(Solve3(3, 0, -4) == Approx(1).epsilon(DBL_EPSILON));
	CHECK(Solve3(0, 0, 0) == Approx(0).epsilon(DBL_EPSILON));
};

TEST_CASE("throws an exception if the equation has no real roots")
{
	CHECK_THROWS_AS(Solve4(1, 4, 6, 4, 2), std::domain_error);
};

TEST_CASE("the equation has one real root")
{
	std::vector<double> result = GetRoots(Solve4(1, 0, 0, 0, 0));
	std::vector<double> expectedResult = { 0 };
	CHECK(result == expectedResult);
	CHECK(GetNumberRoots(Solve4(1, 0, 0, 0, 0)) == 1);
}

TEST_CASE("the equation has two real roots")
{
	std::vector<double> result = GetRoots(Solve4(1, 1, 0, 0, 0));
	std::vector<double> expectedResult = { -1, 0 };
	CHECK(result == expectedResult);
	CHECK(GetNumberRoots(Solve4(1, 1, 0, 0, 0)) == 2);
}

TEST_CASE("the equation has three real roots")
{
	std::vector<double> result = GetRoots(Solve4(1, 0, -1, 0, 0));
	std::vector<double> expectedResult = { -1, 0, 1 };
	CHECK(result == expectedResult);
	CHECK(GetNumberRoots(Solve4(1, 0, -1, 0, 0)) == 3);
}

TEST_CASE("the equation has for real roots")
{
	std::vector<double> result = GetRoots(Solve4(1, -6, 11, -6, 0));
	std::vector<double> expectedResult = {0, 1, 2, 3 };
	CHECK(result == expectedResult);
	CHECK(GetNumberRoots(Solve4(1, -6, 11, -6, 0)) == 4);
}


