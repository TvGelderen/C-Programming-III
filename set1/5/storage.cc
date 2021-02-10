#include "storage.ih"

Storage::Storage(std::initializer_list<size_t> const &list)
:
    d_data(list)            //for testing purpose, initialize d_data
{}
