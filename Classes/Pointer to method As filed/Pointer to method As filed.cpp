// Pointer to method As filed.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
struct A {
	void (A::*f)();
	void happyNotice() {
		std::cout << "Wow\n";
	}
	void sadNotice() {
		std::cout << "Ups\n";
	}

	void behappy (bool yes)
	{
		f = (yes)? &A::happyNotice : &A::sadNotice;
		/*if (yes) 
			f = &happyNotice; 
		else 
			f = &sadNotice;
			*/
	}

	A(bool yes)
	{
		behappy(yes);
	}
};
int main()
{
	A a(true);
	std::cout << sizeof(a) << "\n";
	(a.*(a.f))();
	A *p = new A(false);
	(p->*(p->f))();
	return 0;
}