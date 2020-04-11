class A {
  // закритий cтатичний член класу
  static int x;
  public:
   // відкритий статичний член класу
   static int y;


   void f(int i) { x = i; } // метод класу


   friend void f1(int);	 // дружня функція
};


// визначення дружньої функції


void f1(int i) {   A::x = i; }


// визначення й ініціалізація стат. члена
int A::y = 2;
// доступ через визначення й ініціалізацію
int A::x = 1;


int main() {
  A a;
  a.f(1);// доступ через функцію-член
  f1(1); // доступ через дружню функцію
}



