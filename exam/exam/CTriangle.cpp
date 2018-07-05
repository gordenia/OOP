#include "stdafx.h"
#include "CTriangle.h"

CTriangle::CTriangle(CPoint const &vertex1, CPoint const &vertex2, CPoint const &vertex3)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
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

void CTriangle::Draw(ICanvas & canvas) const
{
	canvas.DrawLine(GetVertex1(), GetVertex2());
	canvas.DrawLine(GetVertex2(), GetVertex3());
	canvas.DrawLine(GetVertex3(), GetVertex1());
}