// ctor for objects as class field.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#define ctorD(M) M() {\
   std::cout << "Default Ctor "#M << " \n" ; M::i = 0;}
#define ctorP(M, N) M(int N) \
 { std::cout << "Parametrized Ctor "#M <<"\n" ; M::i = N;}


struct B
{
	int i;
	ctorD(B); // ����������� B1
	ctorP(B,j); // ����������� B2
};
struct C
{
	int i;
	ctorD(C);// ����������� �1
	ctorP(C, j);// ����������� �2
	
};
struct A	// ���������� ��������� �����
{
	int i;	// ���� ����� ����� A
	B b;	// ��'���-���� ����� A
	C c;	// ��'���-���� ����� A
	ctorD(A); 	// ����������� A0
	ctorP(A, j); 	// ����������� A1
	A(int i, int j) :b(j) { i = i; }	// ����������� A2
	A(int i, int j, int w);	// ����������� A3
};

A::A(int i, int j, int w) :b(j), c(w) { i = i; }

void main()
{
	A a, a1(1), a2(1, 2), a3(1, 2, 'c');
	system("pause");
}
