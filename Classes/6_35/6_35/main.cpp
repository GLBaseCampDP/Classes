#include <functional>
#include <iostream>
#define MES(s) { std::cout << s << "\n"; }


struct A {
  std::function<void(void)> p; //Обгортка на функції
  static void happyNotice(void) MES("Wow");
  static void sadNotice(void) MES("Ups");


//дефолтна ініціалізація вказівника
A(){ p = [this](void) { return happyNotice(); }; }


  void behappy  // ініціалізатор вказівника
    (const std::function<void(void)>& f) { p = f; }
  void Exec(void) { p(); }  // виклик через вказівник
};

int main() {
  A a;
  std::cout << sizeof(a) << "\n";
  a.Exec(); //запуск дефолтної ініціалізації

  //реініціалізція і запуск її результату
  a.behappy([&a](void) { return a.sadNotice(); });
  a.Exec();


  //реініціалізція зовнішньою функцією і запуск
  a.behappy([]() { MES("WOOOOOOOw"); });
  a.Exec();
}


