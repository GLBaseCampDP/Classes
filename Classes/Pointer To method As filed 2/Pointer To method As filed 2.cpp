// Pointer To method As filed 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>
#define MES(s) { std::cout << s << "\n"; }

struct A {
	void(*p)(void);  //�������� �� �������
	static void happyNotice(void) MES("Wow");
	static void sadNotice(void) MES("Ups");

	
		
	A() { 
		//�������� ����������� ���������
		//p = &A::sadNotice; 
		behappy(&A::happyNotice);
	}

	
	void behappy(static void(*f)(void)) 	{
		// ����������� ���������
		p = *f;
	}

	//������ ����� ��������
	void Exec(void) 	{
		(this->p)();
	}

};


// ������� �������
void sadNotice_All(void) MES("UPPPPPs");

 

void main() {
	A a;
	// ������ �������� �������
	a.Exec();
	// ������ �������� �������
	a.behappy(sadNotice_All);
	a.Exec();
	 
	system("pause");
		
}