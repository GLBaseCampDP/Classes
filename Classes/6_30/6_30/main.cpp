#include <utility>


struct B {
  int i_B;
  B() {i_B = 0;} 		// ctor по замовчуванні
  B(int j) {i_B = j;}		// ctor з параметрами
  B(B& b) { i_B = b.i_B; }	// ctor копіювання
  B(B&& b) { i_B = b.i_B; }	// ctor переміщення
} a0;


struct A { 			// оголошення класу
  B& b;				// посилання-член класу
  B&& b3;
                    // ініціалізація через поля
  // ініціалізація через поля
  B& b1 = a0;
  B&& b2 = std::move(a0);
  A(B* p) :b(*p), b3 (std::move(*p)) {}
  A(B& p) :b(p), b3(std::move(p)) {}
  A(B&& p) :b(p), b3(std::move(p)) {}
};


int main() {
  B b(3); B& p1 = b; B* p2 = &b;
  // передавання конструктору об'єкта,
  // посилання та вказівника  відповідно
  A a(b), a1(p1), a2(p2);
}
