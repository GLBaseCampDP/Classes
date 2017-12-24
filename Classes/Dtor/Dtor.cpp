// Dtor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
struct  A {
	int i;
	A() { i = 0; }
	A(int j) { i = j; }
	void show(); // функція-член
	~A() {        // деструктор
		std::cout << "Об'єкт буде знищено";
	}
};

void A::show() {
	std::cout << "i=" << i;
}

void f(A a) { // стороння функція
	a.show();
} // буде викликано деструктор а::~A()

int main() {
	A a2(1);
	f(a2);
	return 0;
}

