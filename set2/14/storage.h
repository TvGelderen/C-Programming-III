#ifndef _INCLUDED_STORAGE_
#define _INCLUDED_STORAGE_

template <typename Data>
class Storage
{
    std::vector<Data *> d_storage;

    public:
            Storage()
            push_back(Data const &value)
            get
            // the usual stuff goes here

};

template <typename Data>
inline Storage<Data>::push_back(Data const &value)
{
    Data *ptr = new Data(value);
    d_storage.push_back(ptr);
}
#endif