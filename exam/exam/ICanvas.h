#pragma once

class CPoint
{
public:
	double x;
	double y;
};


// �����, ����������� �������� ����������� ���������
class ICanvas
{
public:
	virtual void DrawLine(CPoint const &startPoint, CPoint const &endPoint) = 0;
	virtual ~ICanvas() {}
};