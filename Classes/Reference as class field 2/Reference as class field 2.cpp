// Reference as class field 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <utility>

struct B {
	int i_B;
	B() { i_B = -1; }  // ctor �� �����������
	B(int j) { i_B = j; } // ctor � �����������
	B(B& b) { i_B = b.i_B; } // ctor ���������
	B(B&& b) { i_B = b.i_B; }// ctor ����������

};

struct A{
	B& b;// ���������-���� ����� A
	B&& b3;
    B& b1 = *new B; // ����������� ����� ����
	B&& b2 = std::move(*new B); // ����������� ����� ����
    A() :b(*new B), b3(std::move(*new B)) {}// ctor �� ����������� 
				 // ctor � �����������
	A(A& a) :b(a.b), b3(std::move(*new B))  {}
   ~A() { delete &b; }
};

void main() {
	A a;// �������� ��'����
	a.b.i_B++;// ������ �� ����� ��������� b
	A a1 (a);// �������� ��'����
}
