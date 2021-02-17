template <typename Data> 
Storage<Data>::~Storage()
{
   for (auto &elem : d_storage)
        delete elem;
}
