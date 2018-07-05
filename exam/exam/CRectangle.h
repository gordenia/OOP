#pragma once
#include "ICanvasDrawable.h"


// ѕр€моугольник, обладающий координатами верхнего левого угла, шириной и высотой
class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(CPoint const &leftTop, double width, double height);

	void Draw(ICanvas & canvas) const override;

	CPoint GetLeftTop() const;
	CPoint GetRightTop() const;
	CPoint GetLeftBottom() const;
	CPoint GetRightBottom() const;

private:
	double m_width = 0;
	double m_height = 0;
	CPoint m_leftTop;
};

