#pragma once
#include "SolidShape.h"

class CCircle final
	:public CSolidShape
{
public:
	CCircle(CPoint const &center, double const &radius, std::string const &outlineColor, std::string const &fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetCenter() const;
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
};

