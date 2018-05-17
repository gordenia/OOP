#include "stdafx.h"
#include <sstream>
#include <iomanip>
#include "Rectangle.h"

CRectangle::CRectangle(CPoint const &leftTop, CPoint const &rightBottom, std::string const &outlineColor, std::string const &fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
{
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}

double CRectangle::GetWidth() const
{
	return abs(m_rightBottom.x - m_leftTop.x);
}

double CRectangle::GetHeight() const
{
	return abs(m_rightBottom.y - m_leftTop.y);
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

std::string CRectangle::ToString() const

{
	std::ostringstream str;
	str << std::fixed << std::setprecision(2);

	str << "Rectangle:\n"
		<< "Left Top (" << m_leftTop.x << ", " << m_leftTop.y << ")\n"
		<< "Right Bottom (" << m_rightBottom.x << ", " << m_rightBottom.y << ")\n"
		<< "Width: " << GetWidth() << "\n"
		<< "Height: " << GetHeight() << "\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "Outline color: " << GetOutlineColor() << "\n"
		<< "Fill color: " << GetFillColor() << "\n";
	return str.str();
}
