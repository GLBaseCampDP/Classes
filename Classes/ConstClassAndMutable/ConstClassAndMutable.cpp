// ConstClassAndMutable.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

struct A {
	mutable int i;
	void f() const { i = 10; }
};

int main()
{
	const A a;

	a.i = 10; // ��������� ��������
	return true;
	//system("pause");
    
}

