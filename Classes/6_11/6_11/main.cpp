#include <iostream>
struct A {
 void F() && {std::cout << "F rvalue object\n";}
// заборонене одночасне використання
// з ref методами
//void f() { std::cout << "lvalue object\n"; }
 void f() & { std::cout << "lvalue object\n"; }
 void f() && { std::cout << "rvalue object\n"; }
 bool operator < (A& a) && {
  std::cout << "In A";
  return true;
 }
};


bool operator < (A& a, A& b) {


    std::cout << "Outside A";  return true; }


int main()  {
  A().f(); 			// "rvalue object"
  A().F(); 			// "rvalue object"
  A a,b;
  a.f();			// "lvalue object"
// a.F(); - заборонений виклик
  (new A)->f();		// "lvalue object"
// при звичайному перевантаженні оператора <
// виклик є помилковий
// стає дозволеною операцією зовнішня функція
  (a < b); // "Outside A"
  (A() < b); //"In A"
}



