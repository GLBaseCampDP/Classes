// Reference as class field 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <utility>

struct B {
	int i_B;
	B() { i_B = -1; }  // ctor по замовчуванні
	B(int j) { i_B = j; } // ctor з параметрами
	B(B& b) { i_B = b.i_B; } // ctor копіювання
	B(B&& b) { i_B = b.i_B; }// ctor переміщення

};

struct A{
	B& b;// посилання-член класу A
	B&& b3;
    B& b1 = *new B; // ініціалізація через поле
	B&& b2 = std::move(*new B); // ініціалізація через поле
    A() :b(*new B), b3(std::move(*new B)) {}// ctor по замовчуванні 
				 // ctor з параметрами
	A(A& a) :b(a.b), b3(std::move(*new B))  {}
   ~A() { delete &b; }
};

void main() {
	A a;// створеня об'єкта
	a.b.i_B++;// доступ до члена посилання b
	A a1 (a);// створеня об'єкта
}
