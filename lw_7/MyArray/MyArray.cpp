#include "stdafx.h"
#include "iostream"
#include "MyArray.h"


int main()
{
	CMyArray<int> a;
	CMyArray<std::string> b;
	
	a.Append(1);
	std::cout << a[0] << std::endl;

	a[0] = 2;
	std::cout << a[0] << std::endl;

    return 0;
}

