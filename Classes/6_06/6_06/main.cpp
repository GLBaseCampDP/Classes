struct A {
   int i;
   inline int f(int j);
};


inline int A::f(int j) { i = j; return j; }
int main() {
  A a;
  a.f(2);
  return 0;
}

