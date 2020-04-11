struct A {
  int x;
  //const-функція-член
  const int F1(int);
  //функція-член з const this
  int F2() const;
};


const int A::F1(int x0) {  x = x0; return 3;}


int A::F2() const {  return 3;}




int main() {
  A a;
  // call const-методу
  const int i = a.F1(15);
  int j = a.F1(10);
  // call методу із пост. this
  j = a.F2();
   return 0;
}


