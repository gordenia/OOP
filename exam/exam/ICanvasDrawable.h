#pragma once
#include "ICanvas.h"

// Интерфейс объектов, которые можно нарисовать на холсте
class ICanvasDrawable
{
public:
	virtual ~ICanvasDrawable() = default;
	virtual void Draw(ICanvas & canvas) const = 0;
};

