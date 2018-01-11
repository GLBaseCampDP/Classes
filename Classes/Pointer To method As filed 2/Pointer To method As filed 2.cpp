// Pointer To method As filed 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#define MES(s) { std::cout << s << "\n"; }

struct A {
	void(*p)(void);  //Вказівник на функцію
	static void happyNotice(void) MES("Wow");
	static void sadNotice(void) MES("Ups");

	
		
	A() { 
		//дефолтна ініціалізація вказівника
		//p = &A::sadNotice; 
		behappy(&A::happyNotice);
	}

	
	void behappy(static void(*f)(void)) 	{
		// ініціалізатор вказівника
		p = *f;
	}

	//Виклик через вказівник
	void Exec(void) 	{
		(this->p)();
	}

};


// зовнішня функція
void sadNotice_All(void) MES("UPPPPPs");

 

void main() {
	A a;
	// запуск статичної функції
	a.Exec();
	// запуск зовнішньої функції
	a.behappy(sadNotice_All);
	a.Exec();
	 
	system("pause");
		
}