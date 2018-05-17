#include "stdafx.h"
#include "../shape/Shape.h"
#include "../shape/LineSegment.h"
#include "../shape/SolidShape.h"
#include "../shape/Triangle.h"
#include "../shape/Rectangle.h"
#include "../shape/Circle.h"

//segment
TEST_CASE("segment has coordinates")
{
	//������� ����� ����������
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");

	CHECK(line.GetStartPoint().x == 0);
	CHECK(line.GetStartPoint().y == 1);
	CHECK(line.GetEndPoint().x == 2);
	CHECK(line.GetEndPoint().y == 3);
};

TEST_CASE("segment has zero area")
{
	//� ������� ������� �������
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");

	CHECK(line.GetArea() == 0);
};

TEST_CASE("segment has a length")
{
	//� ������� ���� �����
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffffff");
	CHECK(static_cast<int>(line.GetPerimeter()) == 2);
};

TEST_CASE("segment has a color")
{
	//� ������� ���� ����
	CLineSegment line({ 0, 1 }, { 2, 3 }, "#ffff00");
	CHECK(line.GetOutlineColor() == "#ffff00");
};

TEST_CASE("segment has a string representation")
{
	//������� ����� ��������� �������������
	CLineSegment line({ 0, 3 }, { 0, 4 }, "#ffff00");
	CHECK(line.ToString() == R"(LineSegment:
Start point (0.00, 3.00)
End point (0.00, 4.00)
Area: 0.00
Perimeter: 1.00
Outline color: #ffff00
)");
};

//triangle
TEST_CASE("triangle has coordinates")
{
	//����������� ����� ����������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(triangle.GetVertex1().x == 7);
	CHECK(triangle.GetVertex1().y == 8);
	CHECK(triangle.GetVertex2().x == -4);
	CHECK(triangle.GetVertex2().y == 5);
	CHECK(triangle.GetVertex3().x == 1);
	CHECK(triangle.GetVertex3().y == -4);
};

TEST_CASE("triangle has area")
{
	//� ������������ ����� ����� �������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(triangle.GetArea()) == 57);
};

TEST_CASE("triangle has perimeter")
{
	//� ������������ ����� ����� ��������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(triangle.GetPerimeter()) == 35);
};

TEST_CASE("triangle has a line color")
{
	//� ������������ ���� ���� �������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(triangle.GetOutlineColor() == "#ffffff");
};

TEST_CASE("triangle has a fill color")
{
	//� ������������ ���� �������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(triangle.GetFillColor() == "#ffff00");
};

TEST_CASE("triangle has a string representation")
{
	//����������� ����� ��������� �������������
	CTriangle triangle({ 7, 8 }, { -4, 5 }, { 1, -4 }, "#ffffff", "#ffff00");

	CHECK(triangle.ToString() == R"(Triangle:
Vertex1 (7.00, 8.00)
Vertex2 (-4.00, 5.00)
Vertex3 (1.00, -4.00)
Area: 57.00
Perimeter: 35.11
Outline color: #ffffff
Fill color: #ffff00
)");
};

//rectangle
TEST_CASE("rectangle has coordinates of the left upper vertex and the lower right vertex")
{
	//������������� ����� ���������� ����� ������� ������� � ������ ������ �������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(rectangle.GetLeftTop().x == 1);
	CHECK(rectangle.GetLeftTop().y == 8);
	CHECK(rectangle.GetRightBottom().x == 4);
	CHECK(rectangle.GetRightBottom().y == 5);
};

TEST_CASE("rectangle has width")
{
	//� �������������� ����� ����� ������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(rectangle.GetWidth()) == 3);
};

TEST_CASE("rectangle has height")
{
	//� �������������� ����� ����� ������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(rectangle.GetHeight()) == 3);
};

TEST_CASE("rectangle has area")
{
	//� �������������� ����� ����� �������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(rectangle.GetArea()) == 9);
};

TEST_CASE("rectangle has perimeter")
{
	//� �������������� ����� ����� ��������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(rectangle.GetPerimeter()) == 12);
};

TEST_CASE("rectangle has a line color")
{
	//� �������������� ���� ���� �������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(rectangle.GetOutlineColor() == "#ffffff");
};

TEST_CASE("rectangle has a fill color")
{
	//� �������������� ���� �������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(rectangle.GetFillColor() == "#ffff00");
};

TEST_CASE("rectangle has a string representation")
{
	//������������� ����� ��������� �������������
	CRectangle rectangle({ 1, 8 }, { 4, 5 }, "#ffffff", "#ffff00");

	CHECK(rectangle.ToString() == R"(Rectangle:
Left Top (1.00, 8.00)
Right Bottom (4.00, 5.00)
Width: 3.00
Height: 3.00
Area: 9.00
Perimeter: 12.00
Outline color: #ffffff
Fill color: #ffff00
)");
};

//circle
TEST_CASE("circle has center")
{
	//� ����� ���� �����
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(circle.GetCenter().x == 0);
	CHECK(circle.GetCenter().y == 0);
};

TEST_CASE("circle has radius")
{
	//� ����� ���� ������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(circle.GetRadius() == 1);
};

TEST_CASE("circle has area")
{
	//� ����� ����� ����� �������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(circle.GetArea()) == 3);
};

TEST_CASE("circle has perimeter")
{
	//� ����� ����� ����� ��������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(static_cast<int>(circle.GetPerimeter()) == 6);
};

TEST_CASE("circle has a line color")
{
	//� ����� ���� ���� �������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(circle.GetOutlineColor() == "#ffffff");
};

TEST_CASE("circle has a fill color")
{
	//� ����� ���� �������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(circle.GetFillColor() == "#ffff00");
};

TEST_CASE("circle has a string representation")
{
	//���� ����� ��������� �������������
	CCircle circle({ 0, 0 }, 1, "#ffffff", "#ffff00");

	CHECK(circle.ToString() == R"(Circle:
Center (0.00, 0.00)
Radius: 1.00
Area: 3.14
Perimeter: 6.28
Outline color: #ffffff
Fill color: #ffff00
)");
};
