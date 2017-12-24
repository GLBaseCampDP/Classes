// Static field 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

class A {
	// �������� c�������� ���� �����
	static int x;
public:
	// �������� c�������� ���� �����
	static int y;

	void f(int i) { x = i; } // �������-���� �����

							 // ������ �������
	friend void f1(int);
};

// ���������� ������ �������
void f1(int i) {
	A::x = i;
}

// ���������� � ������������ ����. �����
int A::y = 2;
// ������ ����� ���������� � ������������
int A::x = 1;

void main() {
	A a;
	a.f(1);// ������ ����� �������-����
	f1(1); // ������ ����� ������ �������
}