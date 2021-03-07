#ifndef _INLCUDED_MATH_
#define _INCLUDED_MATH_

#include "basicmath.h" 
#include <iostream>

template<template<typename First, typename Second> typename Operator, BasicMath First, BasicMath Second>
void math(First &&arg1, Second &&arg2)
{
   Operator<First, Second>{}.operation(arg1, arg2);  
   std::cout << '\n';                                     // last one so close the line!
}

template<template<typename First, typename Second> typename Operator, BasicMath First, BasicMath Second, typename ...Params>
void math(First &&arg1, Second &&arg2, Params &&...params)
{
   Operator<First, Second>{}.operation(arg1, arg2);           //display the result of the operator
   math<Operator>(arg1, std::forward<Params>(params)...);     //go to next item
}

#endif

