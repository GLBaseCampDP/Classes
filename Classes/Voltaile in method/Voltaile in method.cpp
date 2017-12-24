// Voltaile in method.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
class A
{
public:
	int x;
	volatile int F3();	//volatile-�������-����
	const volatile int F1(int);	//const-�������-����

	int F4() volatile;	//�������-���� � ������ this
	int F5() volatile const;	//�������-���� � ������� this
};
const volatile int A::F1(int x0)
{
	x = x0; return 3;
}


volatile int A::F3()
{
	return x;
}
int A::F4()volatile
{
	x = 4; return x;
}
int A::F5() volatile const
{
	return 3;
}

int main()
{
	A a;
	const int i = a.F1(15);	// ���. ����.-�������-����
	a.F3();	// ���. �����-�������-����
	int j = a.F4();	// ���. �������-���� � ������ this
	j = a.F5();	// ���. �������-���� � ������ i 
				// ����. this
	return 0;
}
