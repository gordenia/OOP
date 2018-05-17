#include "stdafx.h"
#include "Shape.h"

std::string CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

void CShape::SetOutlineColor(const std::string &color)
{
	m_outlineColor = color;
}


