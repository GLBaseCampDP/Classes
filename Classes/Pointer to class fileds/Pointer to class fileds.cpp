// Pointer to class fileds.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
struct A {
	int i;
	int f(int j) { i = j; return i + j; }
};

void F(A& a) { 
			   //���������� ��������� �� ���� ����� 
	int A::*p1 = &A::i;
	//��������� �������� ����� �������� 
	a.*p1 = 2;
	std::cout <<"In F: " << a.i<< "\n";
	//���������� ��������� �� �������-����
	int (A::*p2)(int) = &A::f;
	//������ ������� ����� ��������
	(a.*p2)(3);
	std::cout << "In F: " << a.i << "\n";
}

void main() {
	A a, b;
	F(a);
	int A::*m1 = &A::i;
	a.*m1 = 10;
	b.*m1 = 30;
	std::cout << "In main : "<< a.i << "  " << b.i<<"\n";
	std::cout << "sizeof(A) - " << sizeof(A) << "\n";
	system("pause");
}


