#include "stdafx.h"
#include "../shape/createShape.h"

void VerifyCommandHandling(const std::string &command, const std::string &expectedOutput)
{
	std::stringstream input;
	input = std::stringstream();
	CCreateShape createShape(input);
	std::shared_ptr<CShape> shape;

	CHECK(input << command);
	shape = createShape.ExecuteCommand();
	CHECK(shape->ToString() == expectedOutput);
}

void ExpectOperationFailure(const std::string &command)
{
	std::stringstream input;
	input = std::stringstream();
	CCreateShape createShape(input);
	std::shared_ptr<CShape> shape;

	CHECK(input << command);
	shape = createShape.ExecuteCommand();
	CHECK(!shape);
}


TEST_CASE("can create a segment")
{
	VerifyCommandHandling("line 1 2 3 4 ff0000",
		R"(LineSegment:
Start point (1.00, 2.00)
End point (3.00, 4.00)
Area: 0.00
Perimeter: 2.83
Outline color: ff0000
)");
};

TEST_CASE("can create a triangle")
{
	VerifyCommandHandling("triangle 1 2 5 1 0 0 ff0000 ff0000",
		R"(Triangle:
Vertex1 (1.00, 2.00)
Vertex2 (5.00, 1.00)
Vertex3 (0.00, 0.00)
Area: 4.50
Perimeter: 11.46
Outline color: ff0000
Fill color: ff0000
)");
};

TEST_CASE("can create a rectangle")
{
	VerifyCommandHandling("rectangle 0 2 2 0 ff0000 ff0000",
		R"(Rectangle:
Left Top (0.00, 2.00)
Right Bottom (2.00, 0.00)
Width: 2.00
Height: 2.00
Area: 4.00
Perimeter: 8.00
Outline color: ff0000
Fill color: ff0000
)");
};

TEST_CASE("can create a circle")
{
	VerifyCommandHandling("circle 0 0 1 ff0000 ff0000",
		R"(Circle:
Center (0.00, 0.00)
Radius: 1.00
Area: 3.14
Perimeter: 6.28
Outline color: ff0000
Fill color: ff0000
)");
};

TEST_CASE("can not enter incorrect parameters")
{
	ExpectOperationFailure("circle 1 5 d");
	ExpectOperationFailure("rectangle 0 0 1");
	ExpectOperationFailure("triangle");
	ExpectOperationFailure("line a a");
};


