// LvalueRvalue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

struct A {
	void F() && { std::cout << "F rvalue object\n"; }
	// заборонене одночасне використання з ref методами
	//void f() & { std::cout << "lvalue object\n"; }
	void f() & { std::cout << "lvalue object\n"; }
	void f() && { std::cout << "rvalue object\n"; }
	bool operator < (A& a) && { std::cout << "In A";  return true; }
};
bool operator < (A& a, A& b) { std::cout << "Outside A";  return true; }

void main()  {
	A().f(); // "rvalue object"
	A().F(); // "F rvalue object"
	A a,b;   
	a.f();	// "lvalue object"
	// a.F(); - заборонений виклик
	(new A)->f();// "lvalue object"
	// виклик є помилковий при звичайному перевантеженні оператора <
	// стає довзоленою операцією зовнішня функція
	(a < b); // "Outside A"
	(A() < b); //"In A"

	system("pause");
}