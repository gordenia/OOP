#include "stdafx.h"
#include "CreateShape.h"
#include "Shape.h"
#include "LineSegment.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

CCreateShape::CCreateShape(std::istream &input)
	: m_actionMap({
		{ "line", std::bind(&CCreateShape::CreateLine, this, std::placeholders::_1) },
		{ "triangle", std::bind(&CCreateShape::CreateTriangle, this, std::placeholders::_1) },
		{ "rectangle", std::bind(&CCreateShape::CreateRectangle, this, std::placeholders::_1) },
		{ "circle", std::bind(&CCreateShape::CreateCircle, this, std::placeholders::_1) }
		}),
	m_input(input)
{
}

std::shared_ptr<CShape> CCreateShape::ExecuteCommand() const
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strm(commandLine);

	std::string figure;
	strm >> figure;

	auto it = m_actionMap.find(figure);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return nullptr;
}

std::shared_ptr<CShape> CCreateShape::CreateLine(std::istream &args) const
{
	CPoint startPoint, endPoint;
	std::string outlineColor, input;

	try
	{
		args >> input;
		startPoint.x = std::stod(input);
		input.clear();
		args >> input;
		startPoint.y = std::stod(input);
		input.clear();

		args >> input;
		endPoint.x = std::stod(input);
		input.clear();
		args >> input;
		endPoint.y = std::stod(input);
		input.clear();

		args >> outlineColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
}

std::shared_ptr<CShape> CCreateShape::CreateTriangle(std::istream &args) const
{
	CPoint vertex1, vertex2, vertex3;
	std::string outlineColor, fillColor, input;

	try
	{
		args >> input;
		vertex1.x = std::stod(input);
		input.clear();
		args >> input;
		vertex1.y = std::stod(input);
		input.clear();

		args >> input;
		vertex2.x = std::stod(input);
		input.clear();
		args >> input;
		vertex2.y = std::stod(input);
		input.clear();

		args >> input;
		vertex3.x = std::stod(input);
		input.clear();
		args >> input;
		vertex3.y = std::stod(input);

		args >> outlineColor;
		args >> fillColor;
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

std::shared_ptr<CShape> CCreateShape::CreateRectangle(std::istream &args) const
{
	CPoint leftTop, rightBottom;
	std::string outlineColor, fillColor, input;

	try
	{
		args >> input;
		leftTop.x = std::stod(input);
		input.clear();
		args >> input;
		leftTop.y = std::stod(input);
		input.clear();

		args >> input;
		rightBottom.x = std::stod(input);
		input.clear();
		args >> input;
		rightBottom.y = std::stod(input);

		args >> outlineColor;
		args >> fillColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
}

std::shared_ptr<CShape> CCreateShape::CreateCircle(std::istream &args) const
{
	CPoint center;
	double radius;
	std::string outlineColor, fillColor, input;

	try
	{
		args >> input;
		center.x = std::stod(input);
		input.clear();
		args >> input;
		center.y = std::stod(input);
		input.clear();
		args >> input;
		radius = std::stod(input);

		args >> outlineColor;
		args >> fillColor;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return nullptr;
	}

	return std::make_shared<CCircle>(center, radius, outlineColor, fillColor);
}


