#pragma once
#include "ICanvasDrawable.h"

// Треугольник, задается координатами трех вершин
class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(const CPoint &vertex1, const CPoint &vertex2, const CPoint &vertex3);
	void Draw(ICanvas &canvas) const override;

	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};

