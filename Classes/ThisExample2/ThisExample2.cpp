// ThisExample2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#define OUT \
    std::cout <<" "<< int(&p) <<" " <<\
     (int)p << " " << *p<<"\n"


struct A
{
	int i;
	void  set(int j)
	{
		this->i = j;
	}
	int  get()
	{
		return this->i;
	}
	~A() { std::cout << " Wow.I'm killed\n"; }
};

int main()
{
	int* p = new int;
	*p = 10;
	OUT;
	delete p;
	
	((A*)p)->set(100);
	OUT;

	p = (int*)(int(p) + sizeof(A));
	((A*)p)->set(700);
	OUT;

	delete (A*)p;
	std::cout << " " << ((A*)p)->get() << "  \n\n Who I'm?";

	return 0;
}

