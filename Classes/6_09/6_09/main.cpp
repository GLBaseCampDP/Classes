struct A  {
  int x;
  volatile int F3();//volatile-метод
  const volatile int F1(int);//const-метод
  int F4() volatile;//метод зі змінним this
  int F5() volatile const;//метод із cv this
};


const volatile int A::F1(int x0) {
   x = x0; return 3;
}


volatile int A::F3() {  return x;  }
int A::F4()volatile {   x = 4; return x;  }
int A::F5() volatile const {  return 3;  }


int main() {
  A a;
  const int i = a.F1(15);// call const-методу
  a.F3();// call volatile-методу
  int j = a.F4();// call методу зі змінним this
  j = a.F5();// call методу з vc this
  return 0;
}
