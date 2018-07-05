#pragma once
#include "ICanvas.h"

// ���������� ������, ����������� ����� ���������� � �������� ���������� � stdout � ����:
// DrawLine:(<x0>, <y0>) - (<x1>, <y1>)
class CCanvas : public ICanvas
{
public:
	void DrawLine(CPoint const &startPoint, CPoint const &endPoint) override;
};
