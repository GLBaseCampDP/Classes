#include <iostream>
struct A {
  void (A::*f)();
  //можна використовувати typedef
  //typedef void (A::*F)();


  void happyNotice() { std::cout << "Wow\n"; }
  void sadNotice() { std::cout << "Ups\n"; }


  void behappy (bool yes) {
   f = (yes)? &A::happyNotice : &A::sadNotice;
  }
  A(bool yes) {  behappy(yes);  }
};


int main() {
  std::cout << sizeof(A) << "\n";

  A a(true);
  (a.*(a.f))();


   A *p = new A(false);
   (p->*(p->f))();
}


