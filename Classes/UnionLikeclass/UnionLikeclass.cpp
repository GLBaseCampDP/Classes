// UnionLikeclass.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

struct A {

	union { // �� ����� ������
		A *prev;
		A *next;
	}; 

	enum {FALSE = 0, TRUE = 1}; // �� ����� �� ������

	enum { FalseE = 0, TrueE = 1 } t; // �� ����� ������

	static A* p;     // �� ����� �� ������

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
	//A::next = true; ������ ����������
	int i = A::FALSE; // ������ ���������
	std::cout << sizeof (A)<<"\n";
	A::create();
	std::cout << ((A::p->prev ) ? "TRUE " : "NULL ");
	std::cout << ((A::p->next ) ? "TRUE " : "NULL "); 

	system("pause");
}

