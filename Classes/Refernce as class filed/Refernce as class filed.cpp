// Refernce as class filed.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <utility>

struct B {

	int i_B;
	B() { i_B = -1; } // ctor �� �����������
	B(int j) { i_B = j; }// ctor � �����������
	B(B& b) { i_B = b.i_B; }// ctor ���������
	B(B&& b) { i_B = b.i_B; }// ctor ����������
} a0;

struct A { // ���������� ��������� �����
	int i_A;// ���� ����� ����� A
	B& b;// ���������-���� ����� A
		 // ����������� ����� ����
	B& b1 = a0; 
	B&& b2 = std::move(a0); 
	B&& b3;
	A(B* p) :b(*p), b3 (std::move(*p)) { i_A = 0; }
	A(B& p) :b(p), b3(std::move(p)) { i_A = 0; }
	A(B&& p) :b(p), b3(std::move(p)) { i_A = 0; }
};

void main() {
	B b(3); B& p1 = b; B* p2 = &b;
	// ����������� ������������ ��'����, 
	// ��������� �� ���������  ��������
	A a(b), a1(p1), a2(p2);
}

