struct B {
  int i;
  B() { i = -1; }
  B(int j) { i = j; }
};


struct A {
  int i;			// член даних класу A
  B* b = nullptr;		// вказівник-член класу
  A() { b = new B(10); }
  A(B* p, int j) {
    b = new B;
    *b = *p;
    i = j;
  }
  ~A() { if (b) delete b; }
};


int main() {
  B b(3);
  B* p = &b;
  A a(p, 3); // створення об'єкта
}


