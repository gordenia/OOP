#include "stdafx.h"
#include "../FindMax/FindMax.h"

struct Athlete
{
	std::string name;
	double height;
	double weight;
};

Athlete One = { "Number One", 220.5, 100.50 };
Athlete Two = { "Number Two", 190, 100 };
Athlete Three = { "Number Three", 190, 120 };
Athlete Four = { "Number Four", 180, 150.5 };
Athlete Five = { "Number Five", 100, 180 };

std::vector<Athlete> emptyVector;
std::vector<Athlete> athletes = { One, Two, Three, Four, Five};

bool LessWeight(Athlete const left, Athlete const right)
{
	return (left.weight < right.weight);
}

bool LessHeight(Athlete const &left, Athlete const &right)
{
	return (left.height < right.height);
}


TEST_CASE("an empty array does not have the required element")
{
	Athlete maxWeight;
	CHECK(!FindMaxEx(emptyVector, maxWeight, LessWeight));
};

TEST_CASE("returns the maximum weight")
{
	Athlete maxWeight;
	CHECK(FindMaxEx(athletes, maxWeight, LessWeight));
	CHECK(maxWeight.weight == 180);
	CHECK(maxWeight.name == "Number Five");
};

TEST_CASE("returns the maximum height")
{
	Athlete maxHeight;
	CHECK(FindMaxEx(athletes, maxHeight, LessHeight));
	CHECK(maxHeight.height == 220.5);
	CHECK(maxHeight.name == "Number One");
};
