// Inline.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class A
{
public:
	int i;
	int f(int j) { i = j; return j; }
};


class A
{
public:
	int i;
	inline int f(int j);
};

inline int A::f(int j) { i = j; return j; }

int main()
{
	A a;
	a.f(2);
	return 0;
}



