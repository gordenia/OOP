#include "stdafx.h"
#include <sstream>
#include <iomanip>
#include "LineSegment.h"

CLineSegment::CLineSegment(CPoint const &startPoint, CPoint const &endPoint, std::string const &outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
{
	SetOutlineColor(outlineColor);
}


CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0.0;
}

double CLineSegment::GetPerimeter() const
{
	return hypot(m_startPoint.x - m_endPoint.x, m_startPoint.y - m_endPoint.y);
}

std::string CLineSegment::ToString() const

{
	std::ostringstream str;
	str << std::fixed << std::setprecision(2);

	str << "LineSegment:\n"
		<< "Start point (" << m_startPoint.x << ", " << m_startPoint.y << ")\n"
		<< "End point (" << m_endPoint.x << ", " << m_endPoint.y << ")\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "Outline color: " << GetOutlineColor() << "\n";

	return str.str();
}
