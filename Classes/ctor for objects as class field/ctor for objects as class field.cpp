// ctor for objects as class field.cpp: определяет точку входа для консольного приложения.
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
	ctorD(B); // конструктор B1
	ctorP(B,j); // конструктор B2
};
struct C
{
	int i;
	ctorD(C);// конструктор С1
	ctorP(C, j);// конструктор С2
	
};
struct A	// оголошення основного класу
{
	int i;	// член даних класу A
	B b;	// об'єкт-член класу A
	C c;	// об'єкт-член класу A
	ctorD(A); 	// конструктор A0
	ctorP(A, j); 	// конструктор A1
	A(int i, int j) :b(j) { i = i; }	// конструктор A2
	A(int i, int j, int w);	// конструктор A3
};

A::A(int i, int j, int w) :b(j), c(w) { i = i; }

void main()
{
	A a, a1(1), a2(1, 2), a3(1, 2, 'c');
	system("pause");
}
