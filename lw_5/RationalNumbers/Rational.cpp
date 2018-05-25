#include "stdafx.h"
#include <stdexcept>
#include <boost/math/common_factor.hpp>
#include "Rational.h"

void Normalization(int &m_numerator, int &m_denominator)
{
	int gcd = boost::math::gcd(abs(m_numerator), m_denominator);
	m_numerator = m_numerator / gcd;
	m_denominator = m_denominator / gcd;
}


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("The denominator can not be zero");
	}

	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}

	Normalization(m_numerator, m_denominator);
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator / m_denominator);
}

CRational const CRational::operator -() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator +() const
{
	return *this;
}

CRational const operator +(const CRational &left, const CRational &right)
{
	int lcm = boost::math::lcm(left.GetDenominator(), right.GetDenominator());
	int numerator = left.GetNumerator() * (lcm / left.GetDenominator()) + right.GetNumerator() * (lcm / right.GetDenominator());
	return CRational(numerator, lcm);
}

CRational const operator -(const CRational &left, const CRational &right)
{
	int lcm = boost::math::lcm(left.GetDenominator(), right.GetDenominator());
	int numerator = left.GetNumerator() * (lcm / left.GetDenominator()) - right.GetNumerator() * (lcm / right.GetDenominator());
	return CRational(numerator, lcm);
}

CRational &CRational::operator +=(const CRational &right)
{
	return (*this) = (*this) + right;
}

CRational &CRational::operator -=(const CRational &right)
{
	return (*this) = (*this) - right;
}

CRational const operator *(const CRational &left, const CRational &right)
{
	return CRational(left.GetNumerator() * right.GetNumerator(), left.GetDenominator() * right.GetDenominator());
}

CRational const operator /(const CRational &left, const CRational &right)
{
	return CRational(left.GetNumerator() * right.GetDenominator(), left.GetDenominator() * right.GetNumerator());
}

CRational &CRational::operator *=(const CRational &right)
{
	return (*this) = (*this) * right;
}

CRational &CRational::operator /=(const CRational &right)
{
	return (*this) = (*this) / right;
}

bool const operator ==(const CRational &left, const CRational &right)
{
	if ((left.GetNumerator() == right.GetNumerator()) && (left.GetDenominator() == right.GetDenominator()))
		return true;

	return false;
}

bool const operator !=(const CRational &left, const CRational &right)
{
	if (left == right)
		return false;
	
	return true;
}

bool const operator <(const CRational &left, const CRational &right)
{
	if ((left.GetNumerator() * right.GetDenominator()) < (right.GetNumerator() * left.GetDenominator()))
		return true;

	return false;
}

bool const operator <=(const CRational &left, const CRational &right)
{
	if ((left < right) || (left == right))
		return true;

	return false;
}

bool const operator >(const CRational &left, const CRational &right)
{
	if (left <= right)
		return false;

	return true;
}

bool const operator >=(const CRational &left, const CRational &right)
{
	if ((left > right) || (left == right))
		return true;

	return false;
}

std::ostream &operator <<(std::ostream &strm, const CRational &right)
{
	strm << right.GetNumerator() << '/' << right.GetDenominator();
	return strm;
}

std::istream &operator >>(std::istream &strm, CRational &right)
{
	int numerator;
	int denominator;

	if ((strm >> numerator) && (strm.get() == '/') && (strm >> denominator))
	{
		right = CRational(numerator, denominator);
	}


	return strm;
}