#pragma once
#include <sstream>


class CRational
{
public:
	CRational(int numerator = 0 , int denominator = 1);

	int GetNumerator() const;
	int GetDenominator()const;
	double ToDouble() const;

	CRational const operator -() const;
	CRational const operator +() const;
	CRational &operator +=(const CRational &right);
	CRational &operator -=(const CRational &right);
	CRational &operator *=(const CRational &right);
	CRational &operator /=(const CRational &right);

private:
	int m_numerator;
	int m_denominator;
};

CRational const operator +(const CRational &left, const CRational &right);
CRational const operator -(const CRational &left, const CRational &right);

CRational const operator *(const CRational &left, const CRational &right);
CRational const operator /(const CRational &left, const CRational &right);

bool const operator ==(const CRational &left, const CRational &right);
bool const operator !=(const CRational &left, const CRational &right);

bool const operator <(const CRational &left, const CRational &right);
bool const operator <=(const CRational &left, const CRational &right);
bool const operator >(const CRational &left, const CRational &right);
bool const operator >=(const CRational &left, const CRational &right);

std::ostream &operator <<(std::ostream &strm, const CRational &right);
std::istream &operator >>(std::istream &strm, CRational &right);

