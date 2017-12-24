// FriendExample.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


class A
{
	int i_A;	// ����. ����� �����
	void Funct_A(int) { i_A = 1; }
	friend void f(A& a);// ������ �������
	friend class B;	 // ������ ����
};

class B
{
	int i_B;	// ����. ���� �����
	public:	// ������ ����� ����� �
		void Funct_B(A* a)	{
			i_B = 1;
			// ������ �� ����. ������� � ����� �
			a->Funct_A(2);
		}
};

void f(A& a)
{
	// ������ �� ����. ������� � ����� �
	a.Funct_A(2);
}

int main()
{
	A a;  B b;
	// ������ ������� ������� �� ����� �
	f(a);
	// ������ ������� ��������� ��'����
	b.Funct_B(&a);
	return 0;
}


