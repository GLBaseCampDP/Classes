// Dtor.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
struct  A {
	int i;
	A() { i = 0; }
	A(int j) { i = j; }
	void show(); // �������-����
	~A() {        // ����������
		std::cout << "��'��� ���� �������";
	}
};

void A::show() {
	std::cout << "i=" << i;
}

void f(A a) { // �������� �������
	a.show();
} // ���� ��������� ���������� �::~A()

int main() {
	A a2(1);
	f(a2);
	return 0;
}

