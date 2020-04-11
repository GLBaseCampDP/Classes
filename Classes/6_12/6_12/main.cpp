class A {
  public:
   int i;
   // конструктор з параметрами
   A(int i) {
     A::i = i;
   }
   // конструктор з параметрами
   A(int x, int y) {
     this->i = x + y;
   }



};

int main(){

// використання конструктора A::A(int,int)
A* p = new A(2, 3);


//використання конструктора A::A(int)
A a(5);


// A c; помилка – default ctor відсутній

}


