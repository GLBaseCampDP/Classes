// STDFunction to methos as field.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <functional>
#include <iostream>
#define MES(s) { std::cout << s << "\n"; }

struct A
{
	std::function<void(void)> p;
	static void happyNotice(void) MES("Wow");
	static void sadNotice(void) MES("Ups");

	A()
	{// <- тут создали лямбда функцию для вызова A_MNO
		p = [this](void) { return happyNotice(); };
	}

	void behappy(const std::function<void(void)>& f)
	{
		p = f;
	}

	void Exec(void)
	{
		 p();
	}
};
void main()
{
	A a;
	std::cout << sizeof(a) << "\n";
	a.Exec(); 

	a.behappy([&a](void) { return a.sadNotice(); });
	a.Exec(); 

	a.behappy([]() { MES("WOOOOOOOw"); });
	a.Exec(); 
	system("pause");
}