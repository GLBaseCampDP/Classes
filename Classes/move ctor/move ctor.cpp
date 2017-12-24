// move ctor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

#define MES(S) std::cout << S <<"\n";
#define OUT(S, t) std::cout << S <<\
   (int)t << " " << t->i << "\n";

struct A {
	int i = 1;
	A() = default;
	A(int j) : i(j) {
		MES(" Wow. I'm created");
	}
	//A(A&) = default;
	A(A&) {
		MES(" Wow. I'm copied");
	}
	//A(A&&) = default;
	A(A&& a) {
		this->i = a.i;
		delete &a;
		MES(" Wow. I'm moved");
	}
	~A() {
		MES(" Ups. I'm killed\n");
	}
};

int main() {
	A * p = new A(10);
	OUT(" p :", p);

	A* p2 = new A(std::move(*p));
	OUT(" p :", p);
	OUT(" p2 :", p2);

	return 0;
}

