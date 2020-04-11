#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct A {
  void welcome() { cout << "It's class.\n"; }
  void out(int i) {cout << "data: " << i << "\n";}
  int& get() { return data; }
  int data;
  A() :data(7) { cout << "Ctor \n"; }
  A(int j) :data(j) {}
} a;


int main() {
  auto Welcome = mem_fn(&A::welcome);
  Welcome(a);

  auto Out = mem_fn(&A::out);    Out(a, 42);
  auto Data = mem_fn(&A::data);  Data(a);
  auto Get = mem_fn<int&()>(&A::get);  Get(a);


  auto WWelcome = [](A& a) {return a.welcome();};
  WWelcome(a);


  vector<A> v;
  for (int i = 0; i < 4; ++i) {
    v.push_back(A(i));
    ( bind(printf, "%d \n",Get(v[i])) )();
  }


  for_each(v.begin(), v.end(),
    mem_fun_ref(&A::welcome));


  for_each(v.begin(), v.end(), WWelcome);
}

