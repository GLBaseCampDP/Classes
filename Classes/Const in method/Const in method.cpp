// Const in method.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

class A
{
public:
	int x;
	const int F1(int);	//const-функція-член
	int F2() const; 	//функція-член з const this
};
const int A::F1(int x0)
{
	x = x0; return 3;
}
int A::F2() const
{
	return 3;
}


int main()
{
	A a;
	const int i = a.F1(15);	// вик. пост.-функція-член
	int j = a.F1(10);
	j = a.F2();	// вик. функція-член з пост. this
    return 0;
}

