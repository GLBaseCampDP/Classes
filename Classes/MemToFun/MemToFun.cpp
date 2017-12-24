// MemToFun.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define OT cout <<




struct A {
	void welcome() { OT "It's class.\n"; }
	void out(int i) {
		OT "data: " << i << "\n";
	}
	int& get() { return data; }
	int data;
	A() :data(7) { OT "Ctor \n"; }
	A(int j) :data(j) {}
};

void main() {
	A a;
	auto Welcome = mem_fn(&A::welcome);
	Welcome(a);
	auto Out =
		mem_fn(&A::out);
	Out(a, 42);

	auto Data = mem_fn(&A::data);
	OT "data: " << Data(a) << "\n";

	auto Get = mem_fn<int&()>(&A::get);
	OT "data = " << Get(a) << "\n";

	auto WWelcome = [](A& a) {return a.welcome(); };
	WWelcome(a);

	vector<A> v;
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(A(i));
		( bind(printf, "%d \n",
			Get(v[i])))();
	}

	for_each(v.begin(), v.end(),
		mem_fun_ref(&A::welcome));

	for_each(v.begin(), v.end(),
		WWelcome);

	system("pause");
}

