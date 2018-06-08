#include "stdafx.h"
#include <array>
#include <vector>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h> 
#include "Solve4.h"

int sgn(double r)
{
	if (r > 0)
		return 1;
	else if (r < 0)
		return -1;

	return 0;
}

void GetSolution(const std::vector<double> &roots, EquationRoot4 &solution)
{
	for (double root : roots)
	{
		if (std::find(solution.roots.begin(), solution.roots.end(), root) == solution.roots.end())
		{
			if (fabs(root) < DBL_EPSILON)
				root = 0;

			solution.roots.push_back(root);
			++solution.numRoots;
		}
	}
}

std::vector<double> Solve2(double a, double b, double c)
{
	std::vector<double> result;

	double D = pow(b, 2) - 4 * a * c;
	if (D == 0)
	{
		result.push_back(-b / (2 * a));
	}
	else if (D > 0)
	{
		result.push_back((-b + sqrt(D)) / (2 * a));
		result.push_back((-b - sqrt(D)) / (2 * a));
	}

	return result;
}

double Solve3(double a, double b, double c)
{
	std::array<double, 3> roots;

	double q = (pow(a, 2) - 3 * b) / 9;
	double r = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54;
	double s = pow(q, 3) - pow(r, 2);
	double fi;


	if (s > 0)
	{
		fi = acos(r / sqrt(pow(q, 3))) / 3;
		roots[0] = -2 * sqrt(q) * cos(fi) - a / 3;
		roots[1] = -2 * sqrt(q) * cos(fi + 2 * M_PI / 3.0) - a / 3;
		roots[2] = -2 * sqrt(q) * cos(fi - 2 * M_PI / 3.0) - a / 3;
	}
	else if (s < 0)
	{
		if (q > 0)
		{
			fi = acosh(abs(r) / sqrt(pow(q, 3))) / 3;
			roots[0] = -2 * sgn(r) * sqrt(q) * cosh(fi) - a / 3;
		}
		else if (q < 0)
		{
			fi = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			roots[0] = -2 * sgn(r) * sqrt(abs(q)) * sinh(fi) - a / 3;
		}
		else
		{
			roots[0] = -pow((c - pow(a, 3) / 27), 1 / 3) - a / 3;
		}
	}
	else
	{
		roots[0] = -2 * sgn(r) * sqrt(q) - a / 3;
		roots[1] = sgn(r) * sqrt(q) - a / 3;
	}

	return *max_element(roots.begin(), roots.end());
}

EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw std::invalid_argument("A zero coefficient value is not allowed for x^4");
	}

	double a0 = a;
	EquationRoot4 solution;

	a = b / a0;
	b = c / a0;
	c = d / a0;
	d = e / a0;

	double y0 = Solve3(-b, a * c - 4 * d, -pow(a, 2) * d + 4 * b *d - pow(c, 2));

	double p = sqrt(pow(a, 2) / 4 - b + y0);
	double q = sqrt(pow(y0, 2) / 4 - d);

	if ((a / 2 * y0 - c) < 0)
		q = -q;

	GetSolution(Solve2(1, a / 2 + p, y0 / 2 + q), solution);
	GetSolution(Solve2(1, a / 2 - p, y0 / 2 - q), solution);

	if (solution.numRoots == 0)
	{
		throw std::domain_error("The equation has no real solutions");
	}

	return solution;
}