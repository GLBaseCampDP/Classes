// ConstClassAndMutable.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct A {
	mutable int i;
	void f() const { i = 10; }
};

int main()
{
	const A a;

	a.i = 10; // дозволена операція
	return true;
	//system("pause");
    
}

