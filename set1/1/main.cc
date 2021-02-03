#include "add.h"
#include "pointerunion.h"
#include <iostream>

void fun();

int main()
{
	PointerUnion pu = { add };

	fun();
	std::cout << pu.vp << '\n';
}