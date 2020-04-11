#include <iostream>
using namespace std;
struct A {
  int i;
  int f(int j) { i = j; return i + j; }
};
void F(A& a) {
  //оголошення вказівника на член класу
  int A::*p1 = &A::i;
    a.*p1 = 2; //присвоєння значення через вказівник
  cout <<"In F: " << a.i<< "\n";
  //оголошення вказівника на функцію-член
  int (A::*p2)(int) = &A::f;
  (a.*p2)(3); //виклик функції через вказівник
  cout << "In F: " << a.i << "\n";
}

int main() {
  A a, b;
  F(a);
  int A::*m1 = &A::i;
  a.*m1 = 10;
  b.*m1 = 30;
  cout << "In main : "<< a.i << "  " << b.i<<"\n";
  cout << "sizeof(A) - " << sizeof(A) << "\n";
}
