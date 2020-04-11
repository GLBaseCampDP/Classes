#include <iostream>
#include <type_traits>


#define OUT(S) \
 { std::cout << (long)this << S << i<< "\n";}


class A {
  public:
  int i;
  void f() OUT("Non - cv - ");
  void f() const OUT("Const - ");
  void f() volatile OUT("Volatile - ");

};

A a = { 1 };
int main() {


  a.f();


  std::add_const<A>::type k1 = { 2 };     k1.f();


  std::add_volatile<A>::type k2;  k2.f();


  std::remove_cv<A>::type k3;     k3.f();


  return 0;
}

