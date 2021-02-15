#ifndef _INCLUDED_SHOW_
#define _INCLUDED_SHOW_

template <typename Type>
void Counter<Type>::show()
{
    std::cout << "s_count: " << s_count << " s_actual: " << s_actual << '\n';
}

#endif