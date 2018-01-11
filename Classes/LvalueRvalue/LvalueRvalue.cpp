// LvalueRvalue.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

struct A {
	void F() && { std::cout << "F rvalue object\n"; }
	// ���������� ��������� ������������ � ref ��������
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
	// a.F(); - ����������� ������
	(new A)->f();// "lvalue object"
	// ������ � ���������� ��� ���������� ������������� ��������� <
	// ��� ���������� ��������� ������� �������
	(a < b); // "Outside A"
	(A() < b); //"In A"

	system("pause");
}