// Massive and pointer to clasess.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

struct A {
	int x;
	A() { x = 0; }
	A(int x) { this->x = x; }
	int getValue() { return x; }
};

A* d[3];
A* f[3] = { new A(1), new A(2), new A(3) };

void main()
{
	for (int i = 0; i<3; i++)
		d[i] = new A;
	std::cout << f[1]->getValue();
	delete[] d;
	delete[] f;
}
