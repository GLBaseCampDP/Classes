#include<functional>
#include<iostream>


auto f = []() { std::cout << "Wow"; };


struct A {
  static std::function<void()> F0;
};
std::function<void()>A::F0 = f;


int main() {
 A::F0();
 return 1;
}
