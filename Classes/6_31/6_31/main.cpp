#include <utility>


struct B {
  int i_B;
  B() { i_B = -1; }  		// ctor по замовчуванні
  B(int j) { i_B = j; } 	// ctor з параметрами
  B(B& b) { i_B = b.i_B; } 	// ctor копіювання
  B(B&& b) { i_B = b.i_B; }	// ctor переміщення
};


struct A{
  B& b;  				// посилання-член класу
  B&& b3;				// посилання-член класу
  // ініціалізація через поле
  B& b1 = *new B;
  B&& b2 = std::move(*new B);
  A() :b(*new B), b3(std::move(*new B)) {}
  A(A& a) :b(a.b), b3(std::move(*new B)) {}
  ~A() { delete &b; }
};


int main() {
  A a;
  a.b.i_B++;// доступ до члена посилання b
  A a1 (a);
}

