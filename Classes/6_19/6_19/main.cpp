#include<iostream>
#include<string>
using namespace std;


string M("It's happeness from Global\n");


void LocalShow() {
  string m ("It's happeness from LocalShow\n");
  cout << m;
  static string m1{"sfsf"};
  class Lclass {
    public:
      void out() {
       //cout << m; доступу до локалсів не має
       cout << M << m1; // доступ до глобального М
       cout << "It's happeness from LClass\n";
      }
      int i, j = 10;
      // static int k; - заборонено
      Lclass() { cout << "lclass ctor \n"; };
  } lclass;


  lclass.out();
  //i = 10; немає доступу
  std::cout <<"Wow! Where is Intialization - " <<
    lclass.i << " " << lclass.j << "\n";
}


int main() {  LocalShow(); }
