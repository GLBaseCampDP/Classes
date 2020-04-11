#include<functional>
#include<iostream>


struct A
{
  const char* mes = "Hi";
  std::function<void()> F = [this]()
  {
    std::cout << mes;
  };
};
int main() {
  A*p = new A;
  p->F();
  return 1;
}



