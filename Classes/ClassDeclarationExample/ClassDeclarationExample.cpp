// ClassDeclarationExample.cpp: ���������� ����� ����� ��� ����������� ����������.
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
// �������� ����������� �� ������������
class alignas(16) [[O::l, m]] [[maybe_unused]] A final : public B { 	// ���������� ����� �

public: // ������������ �������
	using I = int; // ����
	typedef unsigned UI;

	friend struct B; // ���������� ��������
	

	I  i1; // ������������ �����
	UI i2; // ������������  

	using B::k; // using ����������

	// ��������� ������ �����
	template <typename T> struct NA 	{ 	};

	 // ��������� ����
	struct NB	{
		I k;
	};

	// assert ����������
	static_assert(std::is_class<A>::value, "A may be POD type");

	// ����� - �����
	void f(A&& n) {
		using namespace std; // using ����������
		// assert ����������
		static_assert(is_class<A>::value, "A may be POD type");
	}

	// ����� - ������ �������
	template<typename T>	void f(T&& n) {}

	
} a;
int main()
{
	
	return 0;
}


