// Massive and objects.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
class A
{
public:
	int x;
	A() { x = 0; }
	A(int x) { this->x = x; }
	int getValue() { return x; }
};

A a[5];
A b0[5] = { A(0), A(1), A(2), A(3), A(4) };
A b[5] = { 0, 1, 2, 3, 4 };
void main()
{
	for (int i = 0; i<5; i++)
		a[i] = b[i].getValue();
}


