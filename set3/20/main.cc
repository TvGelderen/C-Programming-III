#include <iostream>

using namespace std;


template <typename ...Types>
struct Type{};

template <typename needle, typename index, typename ...Tail>
struct Type<needle, index, Tail...> 
{
    enum {tmp = Type<needle, Tail...>::located};    //Move to the next index!
    enum {located = tmp ==  0 ? 0 : 1 + tmp};       //If found return the correct index, 0 o.w.
};

template <typename needle, typename ...Tail>
struct Type<needle, needle, Tail...> 
{
    enum { located = 1 };                           //Index was found!                
};

template <typename needle>
struct Type<needle> 
{
    enum {located = 0};                              //Needle was not found
};

int main()
{
    cout <<
        Type<int>::located << ' ' << 
        Type<int, double>::located << ' ' << 
        Type<int, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int, int, int>::located << 
        '\n';
}
       