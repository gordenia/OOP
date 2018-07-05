#include "stdafx.h"
#include "CCanvas.h"
#include <iostream>

void CCanvas::DrawLine(CPoint const &startPoint, CPoint const &endPoint)
{
	std::cout << "DrawLine:(<" << startPoint.x << "> , <" << startPoint.y << ") - (<" << endPoint.x << ">, <" << endPoint.y << ">)" << std::endl;
}