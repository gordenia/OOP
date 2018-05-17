#pragma once
#include <string>

class CPoint
{
public:
	double x;
	double y;
};

class CShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;

	std::string GetOutlineColor() const;
	void SetOutlineColor(const std::string &color);

private:
	std::string m_outlineColor;
};

