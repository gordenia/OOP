#include "stdafx.h"
#include "Solve4.h"

void GetRoots(const EquationRoot4 &roots)
{
	if (roots.numRoots)
	{
		std::cout << "Equation has " << roots.numRoots << std::endl;
		std::cout << "Roots: " << std::endl;

		for (size_t i = 0; i < roots.numRoots; ++i)
		{
			std::cout << roots.roots[i] << "  ";
		}

		std::cout << std::endl;
	}
}


int main()
{
	double a, b, c, d, e;
	while ((std::cin >> a) && (std::cin >> b) && (std::cin >> c) && (std::cin >> d) && (std::cin >> e))
	{
		try
		{
			GetRoots(Solve4(a, b, c, d, e));
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return 0;
}

