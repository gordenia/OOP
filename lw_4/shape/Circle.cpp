#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <sstream>
#include <iomanip>
#include "Circle.h"


CCircle::CCircle(CPoint const &center, double const &radius, std::string const &outlineColor, std::string const &fillColor)
	: m_center(center)
	, m_radius(radius)
{
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
}


CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const

{
	std::ostringstream str;
	str << std::fixed << std::setprecision(2);

	str << "Circle:\n"
		<< "Center (" << m_center.x << ", " << m_center.y << ")\n"
		<< "Radius: " << m_radius << "\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "Outline color: " << GetOutlineColor() << "\n"
		<< "Fill color: " << GetFillColor() << "\n";
	return str.str();
}
