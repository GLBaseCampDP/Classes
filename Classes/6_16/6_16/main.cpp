#include <iostream>
int j;
struct A {   // оголошення стат. членів
  static int x;
  static int x1;
  static int x2;
  static int x3;
  int i;
};
// порядок визначення і явна ініціалізацію
// впливають на порядок їх розміщення в пам'яті
int A::x;//визначення стат. член. даних і неявне
int A::x2;// присвоєння їм нульових значень
int A::x1 = 1; //визначення й явна ініц.



int main() {
  A::x = 1; 	// явна ініціалізація ст.чл.
  A a, b; 		// створення об'єктів класу А
  a.x++; b.x--; 	// операції з ст.чл. через об'єкт
  A::x++;	//операції з стат. член. через клас
  a.x1++;	//операції з явно ініціалізованим ст.чл.
  a.x2++;	//операції з неіціалізованим явно ст.чл.


  std::cout << "sizeof (int) - " << sizeof(int) <<
    "\nsizeof (A) - " << sizeof(A)<<
    "\n&j - "<< &j << " \n&A::x - " << &A::x <<
    " \n&A::x1 - " << &A::x1 <<
    " \n&A::x2 - " << &A::x2 << " \n&a -" <<
    &a << "\n";
}