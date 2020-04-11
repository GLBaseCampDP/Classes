#include <iostream>
#define ctorD(M) M() {std::cout <<  \
  "Default Ctor "#M << " \n" ; M::i = 0;}
#define ctorP(M, N) M(int N) { std::cout << \
  "Parametrized Ctor "#M <<"\n" ; M::i = N;}


struct B {   int i;
  ctorD(B); 		// ctor - B1
  ctorP(B,j); 		// ctor - B2
};


struct C {   int i;
  ctorD(C);		// ctor - C1
  ctorP(C, j);		// ctor - C2
};
struct A { 	// оголошення основного класу
  int i;
  B b;		// об'єкт-член класу A
  C c;		// об'єкт-член класу A
  ctorD(A); 	// ctor - A0
  ctorP(A, j);  // ctor - A1
  A(int i, int j): b(j) { i = i; }// ctor - A2
  A(int, int, int);               // ctor - A3
};


A::A(int i, int j, int w): b(j), c(w) {i = i;}


int main() {
  A a, a1(1), a2(1, 2), a3(1, 2, 'c');
}
