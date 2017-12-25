// ConstexprCtor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <type_traits>  
struct A
{
	union { int i = 4; };
	const int& k = i;
	int j = 6;
	int z;
	constexpr A (int Z): z(Z){ }
	A() = delete;
	A(A&) = default;
	A(A&&) = default;
};

int main()
{
	A a(5);
    return 0;
}

