// Local class.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

string M("It's happeness from Global\n");

void LocalShow() {
	string m(
		"It's happeness from LocalShow\n");
	cout << m;

	class Lclass {
	public:
		void out() {
			//cout << m; ������� �� ��
			cout << M; // ������ �� ����������
			cout << "It's happeness from LClass\n";

		}
		int i, j = 10;
		// static int k; - ����������
		Lclass() { cout << "lclass ctor \n"; };
	} lclass;

	lclass.out();
	//i = 10; ���� �������
	std::cout << "Wow! Where is Intialization - " <<
		lclass.i << " " << lclass.j << "\n";

};

void main() {
	LocalShow();
	system("pause");
}
