// Pointer as field.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

struct B {
	int i;
	B() { i = -1; }
	B(int j) { i = j; }
};

struct A {
	int i;// член даних класу A
	B* b = NULL;// вказівник-член класу 
	A() { b = new B(10); } //
	A(B* p, int j) {
		b = new B;
		*b = *p;
		i = j;
	}
	~A() { if (b) delete b; }
};

void main() {
	B b(3);
	B* p = &b;
	A a(p, 3);// створення об'єкта
}
