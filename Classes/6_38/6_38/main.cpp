#include <iostream>
using namespace std;


typedef void(*T)();


struct  A {
  static int x1;
  static void f() { cout << "клас A" << endl; }
};


struct  B {
  static int x2;
  static void f() { cout << "клас B" << endl; }
};
struct C {
  static int x3;
  static void f() { cout << "клас C" << endl; }
};


int A::x1 = 1;
int B::x2 = 2;
int C::x3 = 3;


int* m[] = { &A::x1, &B::x2, &C::x3 };


T n[] = { A::f, B::f, C::f };


int main() {
  n[0](); // виклик функції A::f через масив
}
