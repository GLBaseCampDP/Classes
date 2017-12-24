// Refernce as class filed.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <utility>

struct B {

	int i_B;
	B() { i_B = -1; } // ctor по замовчуванні
	B(int j) { i_B = j; }// ctor з параметрами
	B(B& b) { i_B = b.i_B; }// ctor копіювання
	B(B&& b) { i_B = b.i_B; }// ctor переміщення
} a0;

struct A { // оголошення основного класу
	int i_A;// член даних класу A
	B& b;// посилання-член класу A
		 // ініціалізація через поля
	B& b1 = a0; 
	B&& b2 = std::move(a0); 
	B&& b3;
	A(B* p) :b(*p), b3 (std::move(*p)) { i_A = 0; }
	A(B& p) :b(p), b3(std::move(p)) { i_A = 0; }
	A(B&& p) :b(p), b3(std::move(p)) { i_A = 0; }
};

void main() {
	B b(3); B& p1 = b; B* p2 = &b;
	// передавання конструктору об'єкта, 
	// посилання та вказівника  відповідно
	A a(b), a1(p1), a2(p2);
}

