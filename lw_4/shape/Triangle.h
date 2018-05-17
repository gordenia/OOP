#pragma once
#include "SolidShape.h"

class CTriangle final :
	public CSolidShape
{
public:
	CTriangle(CPoint const &vertex1, CPoint const &vertex2, CPoint const &vertex3, std::string const &outlineColor, std::string const &fillColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};

