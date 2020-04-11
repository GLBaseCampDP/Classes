#include<iostream>

struct A {
  union { 			// на розмір впливає
      A *prev;
      A *next;
  };
                // на розмір не впливає
  enum {FALSE = 0, TRUE = 1};
                // на розмір впливає
  enum { FalseE = 0, TrueE = 1 } t;
  static A* p;     	// на розмір не впливає


  A() { std::cout << "ctor A()\n";  }
  static int create () {
     p = new A;
     p->next = nullptr;

     return TRUE;
    }
};


A* A::p = nullptr;


int main() {
  //A::next = true; доступ заборонено
  int i = A::FALSE; // доступ дозволено
  std::cout << sizeof (A)<<"\n";
  A::create();
  std::cout <<
     ((A::p->prev ) ? "TRUE " : "NULL ") <<
     ((A::p->next ) ? "TRUE " : "NULL ");
}
