// Const in method.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

class A
{
public:
	int x;
	const int F1(int);	//const-�������-����
	int F2() const; 	//�������-���� � const this
};
const int A::F1(int x0)
{
	x = x0; return 3;
}
int A::F2() const
{
	return 3;
}


int main()
{
	A a;
	const int i = a.F1(15);	// ���. ����.-�������-����
	int j = a.F1(10);
	j = a.F2();	// ���. �������-���� � ����. this
    return 0;
}

