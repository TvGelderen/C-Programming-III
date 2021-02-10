#include "add.h"
#include "pointerunion.h"
#include <iostream>

void fun()
{
	PointerUnion pu = { add };

	std::cout << pu.vp << '\n';
}
