#pragma once
#include "ICanvas.h"

// –еализаци€ холста, выполн€юща€ вывод информации о рисуемых примитивах в stdout в виде:
// DrawLine:(<x0>, <y0>) - (<x1>, <y1>)
class CCanvas : public ICanvas
{
public:
	void DrawLine(CPoint const &startPoint, CPoint const &endPoint) override;
};
