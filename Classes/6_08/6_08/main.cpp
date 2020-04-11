struct A {
  mutable int i;
  void f() const { i = 10; }
};

void F (const A a)
{
     a.i = 10; // дозволена операція
     a.f();// дозволена операція
}

int main() {
    A a;
F(a);
   }


