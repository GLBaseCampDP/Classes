#include <iostream>
namespace O {   int l,m;
                void f(int p) {};
};


struct B {   int k; };
// оголошення класу А з
// атрибутами вирівнювання та використання
class alignas(16) [[O::l, m]] [[maybe_unused]]
    A final : public B {
  public: 			// специфікатор доступу
   using I = int; 	// аліас
   typedef unsigned UI; // оголошення  псевдо
   friend struct B; 	// декларація дружності
   I  i1; 			// використання аліаса
   UI i2; 			// використання  псевдо

   using B::k; 			// using декларація
   // вкладений шаблон класу
   template <typename T> struct NA { };
   struct NB { I k; }; 		// вкладений клас
                        // assert декларації
   static_assert(std::is_class<A>::value, "Oh");

   void f(A&& n) { 		// метод - класу
     using namespace std;	// using декларація
                        // assert декларації
     static_assert(is_class<A>::value, "Wow");
    }
                        // метод-шаблон функції
    template<typename T>void f(T&& n) {}
} a;
int main() { }
