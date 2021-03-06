#include "stdafx.h"
#include <vector>
#include <memory>
#include "ICanvasDrawable.h"
#include "CTriangle.h"
#include "CCanvas.h"
#include "CRectangle.h"

void DrawPicture(ICanvas &canvas, const std::vector<std::shared_ptr<const ICanvasDrawable>> &picture)
{
	for (const auto& shape : picture)
	{
		shape->Draw(canvas);
	}
}

int main()
{
	std::vector<std::shared_ptr<const ICanvasDrawable>> picture;

	CPoint v1, v2, v3, leftTop;
	v1.x = 1;
	v1.y = 2;
	v2.x = 2;
	v2.y = 3;
	v3.x = 3;
	v3.y = 2;
	int*  
	leftTop.x = 1;
	leftTop.y = 2;
	double width = 2, height=2;
	CCanvas canvas;

	picture.push_back(std::make_shared<CTriangle>(v1, v2, v3));
	picture.push_back(std::make_shared<CRectangle>(leftTop, width, height));

	DrawPicture(canvas, picture);

	return 0;
}

