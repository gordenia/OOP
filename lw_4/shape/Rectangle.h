#pragma once
#include "SolidShape.h"

class CRectangle final
	: public CSolidShape
{
public:
	CRectangle(CPoint const &leftTop, CPoint const &rightBottom, std::string const &outlineColor, std::string const & fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
};

