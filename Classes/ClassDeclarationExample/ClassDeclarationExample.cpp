// ClassDeclarationExample.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <type_traits>
#include <iostream>

namespace O
{
	int l,m;
	void f(int p) {};
};

struct B
{
	int k;
};
// атрибути вирівнювання та використання
class alignas(16) [[O::l, m]] [[maybe_unused]] A final : public B { 	// оголошення класу А

public: // специфікатор доступу
	using I = int; // аліас
	typedef unsigned UI;

	friend struct B; // декларація дружності
	

	I  i1; // використання аліаса
	UI i2; // використання  

	using B::k; // using декларація

	// вкладений шаблон класу
	template <typename T> struct NA 	{ 	};

	 // вкладений клас
	struct NB	{
		I k;
	};

	// assert дикларації
	static_assert(std::is_class<A>::value, "A may be POD type");

	// метод - класу
	void f(A&& n) {
		using namespace std; // using декларація
		// assert дикларації
		static_assert(is_class<A>::value, "A may be POD type");
	}

	// метод - шаблон функції
	template<typename T>	void f(T&& n) {}

	
} a;
int main()
{
	
	return 0;
}


