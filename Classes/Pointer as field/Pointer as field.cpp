// Pointer as field.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

struct B {
	int i;
	B() { i = -1; }
	B(int j) { i = j; }
};

struct A {
	int i;// ���� ����� ����� A
	B* b = NULL;// ��������-���� ����� 
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
	A a(p, 3);// ��������� ��'����
}
