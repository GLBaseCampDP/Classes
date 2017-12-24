// Pointer to static class  field.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class A { //оголошення класу
public:
	static int i;
	static int f(int j) { i = j; return i + j; }
};

//визначення статичного члена
int A::i = 3;

void main() {
	// оголошення вказівника на статичний
	// член даних класу
	int *p1 = &A::i;
	// присвоєєня значення через вказівник   
	*p1 = 1;
	// оголошення вказівника на статичну 
	// функцію член класу
	int(*p2)(int) = &A::f;
	// виклик функції через вказівник
	(*p2)(3);
	A a;
	std::cout << a.i;
}

