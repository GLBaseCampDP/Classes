// Static field.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>

int j;

struct A {
	// ���������� ����. ����. �����
	static int x;
	static int x1;
	static int x2;
	static int x3;
	int i;
};

// ������� ���������� � ���� ������������ // ��������� �� ������� �� ��������� � ���'�� 
int A::x;//���������� ����. ����. ����� � 
int A::x2;//������ ��������� �� �������� �������
int A::x1 = 1; //���������� � ���� ����.

void main() {

	A::x = 1; //���� ������������ ��.��.
	A a, b; //��������� ��'���� ����� �
	a.x++; b.x--; //�������� � ��.��. ����� ��'���
	A::x++; //�������� � ����. ����. ����� ����
	a.x1++;//�������� � ���� �������������� ��.��.
	a.x2++;//�������� � ������������� ���� ��.��.

	std::cout << "sizeof (int) - " << sizeof(int) <<
		"\nsizeof (A) - " << sizeof(A) <<
		"\n&j - " << &j << " \n&A::x - " << &A::x <<
		" \n&A::x1 - " << &A::x1 <<
		" \n&A::x2 - " << &A::x2 << " \n&a -" <<
		&a << "\n";
}