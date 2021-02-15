#include "counter.h"
#include <string>

using namespace std;

int main()
{
    Counter<int> counter;
    Counter<int> i_counter(3); 
    Counter<string> s_counter; 
    Counter<string> s_counter2("Hi!"); 
    Counter<int> counter2 = counter;



    counter.show();
    i_counter.show();
    s_counter.show();
    s_counter2.show();
    counter2.show();
}