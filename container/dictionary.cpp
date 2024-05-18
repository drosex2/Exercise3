
namespace lasd {

/* ************************************************************************** */

template<typename Data>
 bool DictionaryContainer<Data>::InsertAll(const TraversableContainer<Data>& container){
    bool all=true;
    container.Traverse(
        [this,&all](const Data& data){
            all&= Insert(data);
        }
    );
    return all;
}
template<typename Data>
 bool DictionaryContainer<Data>::InsertAll(MappableContainer<Data>&& container){
    bool all=true;
    container.Map(
        [this,&all](const Data& data){
            all&= Insert(std::move(data));
        }
    );
    return all;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveAll(const TraversableContainer<Data>& container){
    bool all=true;
    container.Traverse(
        [this,&all](const Data& data){
            all &=Remove(data);
        }
    );
    return all;
}


template<typename Data>
 bool DictionaryContainer<Data>::InsertSome(const TraversableContainer<Data>& container){
   bool some=false;
    container.Traverse(
        [this,&some](const Data& data){
            some|=Insert(data);
        }
    );
    return some;
}
template<typename Data>
 bool DictionaryContainer<Data>::InsertSome(MappableContainer<Data>&& container){
    bool some=false;
    container.Map(
        [this,&some](const Data& data){
            some|= Insert(std::move(data));
        }
    );
    return some;
}

template<typename Data>
bool DictionaryContainer<Data>::RemoveSome(const TraversableContainer<Data>& container){
    bool some=false;
    container.Traverse(
        [this,&some](const Data& data){
            some|=Remove(data);
        }
    );
    return some;
}

/* ************************************************************************** */

}
