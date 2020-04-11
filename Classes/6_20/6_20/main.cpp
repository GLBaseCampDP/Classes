class A { 			// enclosing class
  class C {};		// private nested class
  public:
    struct B { 		// public nested class
      A* pA; 		// class B members
      int i;
      static int z; 	// оголошення допустиме
    };
  int j;			// class A members
  void f(){
   B* pB;			// доступ в тілі f до B
   // i = 0; B::i =0; немає доступу до членів класу В
   pB = new B; 	// доступ до членів об’єкта В
   pB->i = 0;
   j = 1;
   pB->pA = this;	// доступ з nclass до eclass

   pB->pA->j = 1;
}};


int A::B::z;


int main() {
  A a;
  a.f(); a.j = 0; // доступ до членів об'єкта а
  //a.i=0; немає прямого доступу
  A::B b; 		// створення об'єкта nclass
  b.i = 0;
  //b.j = 1; немає прямого доступу
  // доступ через об'єкт nclass до eclass
  // b.pA->j = 2; // немає об'єкта
  b.pA = new A;
  b.pA->j = 2; 	// немає об'єкта
  //A::C c; немає прямого доступу
}
