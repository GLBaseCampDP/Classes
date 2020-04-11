#include <iostream>
class A {
  public:  class U;
  private:  int U;
};
int main() {
    int A = 1;
    //A a; помилка локальний ідентифікатор визначає змінну
    class A a; // OK: використовується ::A
    //A::U* u; // помилка доступу: A::U є private
    class A::U* u; // incomplete type
    std::cout <<sizeof(u) << ' ' << sizeof(a);
}
