// Pointer to static class  field.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>

class A { //���������� �����
public:
	static int i;
	static int f(int j) { i = j; return i + j; }
};

//���������� ���������� �����
int A::i = 3;

void main() {
	// ���������� ��������� �� ���������
	// ���� ����� �����
	int *p1 = &A::i;
	// ������� �������� ����� ��������   
	*p1 = 1;
	// ���������� ��������� �� �������� 
	// ������� ���� �����
	int(*p2)(int) = &A::f;
	// ������ ������� ����� ��������
	(*p2)(3);
	A a;
	std::cout << a.i;
}

