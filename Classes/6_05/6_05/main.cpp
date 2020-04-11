#include <iostream>
#define OUT std::cout <<" "<< long(&p) <<" " <<\
     (long)p << " " << *p<<"\n"


struct A {
  int i;
  void  set(int j) {    this->i = j;  }
  int  get() {    return this->i;  }
  ~A() { std::cout << " Wow.I'm killed\n"; }
};


int main()  {
  int* p = new int;
  *p = 10;
  OUT;

  delete p;
  ((A*)p)->set(100);
  OUT;

  p = new int;
  *p = 10;
  delete (A*)p;
  OUT;


  p = (int*)(long(p) + sizeof(A));
  ((A*)p)->set(700);
  OUT;

  //delete (A*)p; - error
  //вказівник вказує на вільну память
  std::cout << ((A*)p)-> get()<<'\n';




  return 0;
}
