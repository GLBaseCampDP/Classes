// Massive and pointers to static field.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef void(*T)();

struct  A {
	static int x1;
	static void f()
	{
		cout << "���� A" << endl;
	}
};

struct  B {
	static int x2;
	static void f()
	{
		cout << "���� B" << endl;
	}
};

struct C {
	static int x3;
	static void f()
	{
		cout << "���� C" << endl;
	}

};

int A::x1 = 1;    int B::x2 = 2;   int C::x3 = 3;

int* m[] = { &A::x1, &B::x2, &C::x3 };

T n[] = { A::f, B::f, C::f };

void main() {
	n[0](); // ������ ������� A::f ����� �����
}

