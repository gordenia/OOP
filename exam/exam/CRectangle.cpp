#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(CPoint const &leftTop, double width, double height)
	: m_leftTop(leftTop)
	, m_width(width)
	, m_height(height)
{
}


CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightTop() const
{
	return { m_leftTop.x + m_width, m_leftTop.y };
}

CPoint CRectangle::GetLeftBottom() const
{
	return { m_leftTop.x, m_leftTop.y - m_height };
}

CPoint CRectangle::GetRightBottom() const
{
	return { m_leftTop.x + m_width, m_leftTop.y - m_height };
}


void CRectangle::Draw(ICanvas &canvas) const
{
	canvas.DrawLine(GetLeftTop(), GetRightTop());
	canvas.DrawLine(GetRightTop(), GetRightBottom());
	canvas.DrawLine(GetRightBottom(), GetLeftBottom());
	canvas.DrawLine(GetLeftBottom(), GetLeftTop());
}