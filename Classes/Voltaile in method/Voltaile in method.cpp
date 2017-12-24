// Voltaile in method.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
class A
{
public:
	int x;
	volatile int F3();	//volatile-функція-член
	const volatile int F1(int);	//const-функція-член

	int F4() volatile;	//функція-член зі змінним this
	int F5() volatile const;	//функція-член з сумісним this
};
const volatile int A::F1(int x0)
{
	x = x0; return 3;
}


volatile int A::F3()
{
	return x;
}
int A::F4()volatile
{
	x = 4; return x;
}
int A::F5() volatile const
{
	return 3;
}

int main()
{
	A a;
	const int i = a.F1(15);	// вик. пост.-функція-член
	a.F3();	// вик. змінна-функція-член
	int j = a.F4();	// вик. функція-член зі змінним this
	j = a.F5();	// вик. функція-член зі змінним i 
				// пост. this
	return 0;
}
