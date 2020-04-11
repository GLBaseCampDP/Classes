#include<iostream>
#define MES(s) { std::cout << s << "\n"; }


struct A {
  void(*p)(void);  //Вказівник на функцію


  static void happyNotice(void) MES("Wow");
  static void sadNotice(void) MES("Ups");


  //дефолтна ініціалізація вказівника
  A() { behappy(&A::happyNotice); }


  // ініціалізатор вказівника
  void behappy(void(*f)(void)) { p = *f; }
  // Виклик через вказівник
  void Exec(void) {   (this->p)(); }
};


// зовнішня функція
void sadNotice_All(void) MES("UPPPPPs");


int main() {
  A a;
  a.Exec(); // запуск статичної функції
  // запуск зовнішньої функції
  a.behappy(sadNotice_All);
  a.Exec();
}
