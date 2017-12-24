// ThisExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#define OUT \
    std::cout <<" "<< int(&p) <<" " << (int)p << " " << p->i<<"\n"


struct A
{
	int i;
	void  set(int j)
	{
		this->i = j;
	}
	~A() { std::cout << " Wow.I'm killed\n"; }
};

int main()
{
	A* p = new A;
	p->set(100);
	OUT;
	delete p;
	p->set(100);
	OUT;
	p->i++;
	OUT;
	return 0;
}
