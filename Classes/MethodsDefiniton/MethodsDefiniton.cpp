// MethodsDefiniton.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
class A
{
	long lx;
public:
	int  x;
	int  F(int x)
	{
		A::lx = A::x + 2;
		return A::x + x + lx;
	}
};



int main()
{
	A a;    a.x = 1;  std::cout << a.F(2);
    return 0;
}




