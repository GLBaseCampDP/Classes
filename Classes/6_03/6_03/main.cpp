class A {
  int i_A;  		// закр. члени класу
  void Funct_A(int) { i_A = 1; }
  friend void f(A& a);	// дружня функція
  friend class B; 	// дружній клас
};


class B {
  int i_B;			// закр. член B
  public:			// відкриті члени B
   void Funct_B(A* a){
     i_B = 1;
     // доступ до закр. функції з класу А
     a->Funct_A(2);
   }

};


void f(A& a) {
// доступ до закр. функції з класу А
a.Funct_A(2);
}


int main() {
A a;  B b;
// виклик функції дружньої до класу А
f(a);
// виклик функції дружнього об'єкта
b.Funct_B(&a);
return 0;
}

