#include <vector>

struct EquationRoot4
{
	size_t numRoots = 0;
	//double roots[4];
	std::vector<double> roots;
};

EquationRoot4 Solve4(double a, double b, double c, double d, double e);
double Solve3(double a, double b, double c);
std::vector<double> Solve2(double a, double b, double c);