// UnionLikeclass.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

struct A {

	union { // на розмір впливає
		A *prev;
		A *next;
	}; 

	enum {FALSE = 0, TRUE = 1}; // на розмір не впливає

	enum { FalseE = 0, TrueE = 1 } t; // на розмір впливає

	static A* p;     // на розмір не впливає

	A() { std::cout << "ctor A()\n";  	}

	static int create () { 
		p = new A;  
		p->next = nullptr; 
		return TRUE;
		
	}
};

A* A::p = nullptr;


void main()
{
	//A::next = true; доступ заборонено
	int i = A::FALSE; // доступ дозволено
	std::cout << sizeof (A)<<"\n";
	A::create();
	std::cout << ((A::p->prev ) ? "TRUE " : "NULL ");
	std::cout << ((A::p->next ) ? "TRUE " : "NULL "); 

	system("pause");
}

