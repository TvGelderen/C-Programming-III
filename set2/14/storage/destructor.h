#ifndef _INCLUDED_STORAGE_DESTRUCTOR_
#define _INCLUDED_STORAGE_DESTRUCTOR_

template <typename Data> 
Storage<Data>::~Storage()
{
   for (auto &elem : d_storage)         //Delete all memory assigned by Storage
        delete elem;                    
}

#endif