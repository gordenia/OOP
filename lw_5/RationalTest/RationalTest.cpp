#include "stdafx.h"
#include <sstream>
#include <functional>
#include "../RationalNumbers/Rational.h"

void ExpectOperationSuccess(const CRational &ob, int expectedNumerator, int expectedDenominator)
{
	CHECK(ob.GetNumerator() == expectedNumerator);
	CHECK(ob.GetDenominator() == expectedDenominator);
}


TEST_CASE("returns zero by default")
{
	ExpectOperationSuccess(CRational(), 0, 1);
};

TEST_CASE("returns a rational number in the form of an integer")
{
	ExpectOperationSuccess(CRational(-1), -1, 1);
	ExpectOperationSuccess(CRational(0), 0, 1);
	ExpectOperationSuccess(CRational(1), 1, 1);
};

TEST_CASE("returns a rational number with numerator and denominator")
{
	ExpectOperationSuccess(CRational(3, 2), 3, 2);
	ExpectOperationSuccess(CRational(-3, 2), -3, 2);
	ExpectOperationSuccess(CRational(3, -2), -3, 2);
	ExpectOperationSuccess(CRational(-3, -2), 3, 2);
};

TEST_CASE("rational number must be normalized")
{
	ExpectOperationSuccess(CRational(6, 2), 3, 1);
	ExpectOperationSuccess(CRational(2, 4), 1, 2);
	ExpectOperationSuccess(CRational(3, 9), 1, 3);
};

TEST_CASE("denominator can not be zero")
{
	CHECK_THROWS_AS(CRational(1, 0), std::invalid_argument);
}

TEST_CASE("can be converted into double")
{
	CHECK(CRational(3, 5).ToDouble() == CRational(3, 5).GetNumerator() / CRational(3, 5).GetDenominator());
	CHECK(CRational(-1, 2).ToDouble() == CRational(-1, 2).GetNumerator() / CRational(-1, 2).GetDenominator());
}

TEST_CASE("can use the unary minus operation")
{
	ExpectOperationSuccess(-CRational(6, 2), -3, 1);
	ExpectOperationSuccess(-CRational(1), -1, 1);
	ExpectOperationSuccess(-CRational(-1), 1, 1);
};

TEST_CASE("can use the unary plus operation")
{
	ExpectOperationSuccess(+CRational(6, 2), 3, 1);
	ExpectOperationSuccess(+CRational(1), 1, 1);
	ExpectOperationSuccess(+CRational(-1), -1, 1);
};

TEST_CASE("can use the binary plus operation")
{
	ExpectOperationSuccess(CRational(6, 2) + CRational(3, 2), 9, 2);
	ExpectOperationSuccess(CRational(2, 5) + 2, 12, 5);
	ExpectOperationSuccess(3 + CRational(6, 7), 27, 7);
};

TEST_CASE("can use the binary minus operation")
{
	ExpectOperationSuccess(CRational(6, 2) - CRational(3, 2), 3, 2);
	ExpectOperationSuccess(CRational(2, 5) - 2, -8, 5);
	ExpectOperationSuccess(3 - CRational(6, 7), 15, 7);
};

TEST_CASE("can use operation +=")
{
	ExpectOperationSuccess(CRational(1, 2) += CRational(1, 2), 1, 1);
	ExpectOperationSuccess(CRational(1, 2) += 1, 3, 2);
};

TEST_CASE("can use operation -=")
{
	ExpectOperationSuccess(CRational(1, 2)-= CRational(1, 2), 0, 1);
	ExpectOperationSuccess(CRational(1, 2)-= 1, -1, 2);
};

TEST_CASE("can use multiplication operation")
{
	ExpectOperationSuccess(CRational(6, 2) * CRational(3, 2), 9, 2);
	ExpectOperationSuccess(CRational(2, 5) * 2, 4, 5);
	ExpectOperationSuccess(3 * CRational(6, 7), 18, 7);
};

TEST_CASE("can use operation of division")
{
	ExpectOperationSuccess(CRational(6, 2) / CRational(3, 2), 2, 1);
	ExpectOperationSuccess(CRational(2, 5) / 2, 1, 5);
	ExpectOperationSuccess(3 / CRational(6, 7), 7, 2);
};

TEST_CASE("can use operation *=")
{
	ExpectOperationSuccess(CRational(1, 2) *= CRational(1, 2), 1, 4);
	ExpectOperationSuccess(CRational(1, 2) *= 3, 3, 2);
};

TEST_CASE("can use operation /=")
{
	ExpectOperationSuccess(CRational(1, 2) /= CRational(1, 4), 2, 1);
	ExpectOperationSuccess(CRational(1, 2) /= 3, 1, 6);
};

TEST_CASE("can use operation ==")
{
	CHECK(CRational(1, 2) == CRational(1, 2));
	CHECK(CRational(1, -2) == CRational(-1, 2));
	CHECK(CRational(2, 3) == CRational(4, 6));
};

TEST_CASE("can use operation !=")
{
	CHECK(CRational(1, 2) != CRational(1, 3));
	CHECK(CRational(1, -2) != CRational(1, 2));
};

TEST_CASE("can use operation comparisons <, <=, >, >=")
{
	CHECK(CRational(1, 5) < CRational(1, 3));
	CHECK(CRational(1, -2) < 1);
	CHECK(2 < CRational(13, 2));

	CHECK(CRational(1, 5) <= CRational(1, 5));
	CHECK(CRational(1, -1) <= -1);
	CHECK(2 <= CRational(4, 2));

	CHECK(CRational(1, 3) > CRational(1, 5));
	CHECK(1 > CRational(1, -2));
	CHECK(CRational(13, 2) > 2);

	CHECK(CRational(1, 5) >= CRational(1, 5));
	CHECK(CRational(1, -1) >= -1);
	CHECK(2 >= CRational(4, 2));
};

TEST_CASE("can put a rational number in the stream")
{
	std::ostringstream out;
	out << CRational(1, 2);
	CHECK(out.str() == "1/2");
}

TEST_CASE("can take a rational number from the stream")
{
	std::string str = "1/2";
	std::istringstream input(str);
	CRational rational;
	input >> rational;
	ExpectOperationSuccess(rational, 1, 2);
}




