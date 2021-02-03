#include "pointerunion.h"
#include <iostream>

template <typename T>
T add(T const &lhs, T const &rhs);

void fun()
{
	PointerUnion pu = { add };

	std::cout << pu.vp << '\n';
}