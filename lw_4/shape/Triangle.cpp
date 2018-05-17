#include "stdafx.h"
#include <sstream>
#include <iomanip>
#include "Triangle.h"

CTriangle::CTriangle(CPoint const &vertex1, CPoint const &vertex2, CPoint const &vertex3, std::string const &outlineColor, std::string const &fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	SetOutlineColor(outlineColor);
	SetFillColor(fillColor);
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

double CTriangle::GetArea() const
{
	return abs((m_vertex1.x - m_vertex3.x) * (m_vertex2.y - m_vertex3.y)
		- (m_vertex2.x - m_vertex3.x) * (m_vertex1.y - m_vertex3.y)) * 0.5;
}

double CTriangle::GetPerimeter() const
{
	double side1 = hypot(m_vertex1.x - m_vertex2.x, m_vertex1.y - m_vertex2.y);
	double side2 = hypot(m_vertex1.x - m_vertex3.x, m_vertex1.y - m_vertex3.y);
	double side3 = hypot(m_vertex3.x - m_vertex2.x, m_vertex3.y - m_vertex2.y);

	return side1 + side2 + side3;
}

std::string CTriangle::ToString() const

{
	std::ostringstream str;
	str << std::fixed << std::setprecision(2);

	str << "Triangle:\n"
		<< "Vertex1 (" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		<< "Vertex2 (" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		<< "Vertex3 (" << m_vertex3.x << ", " << m_vertex3.y << ")\n"
		<< "Area: " << GetArea() << "\n"
		<< "Perimeter: " << GetPerimeter() << "\n"
		<< "Outline color: " << GetOutlineColor() << "\n"
		<< "Fill color: " << GetFillColor() << "\n";
	return str.str();
}
