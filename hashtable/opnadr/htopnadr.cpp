#include <cmath>
namespace lasd {



/* ************************************************************************** */
// DEFAULT CONSTRUCTOR
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    size=0;
    a=dista(gen);
    b=distb(gen);
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }
}

//specific constructors

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIn){
    size=0;
    a=dista(gen);
    b=distb(gen);
    tableSize=1<<(std::ceil(std::log2(sizeIn))); //calcolo la potenza di 2 superiore a sizeIn
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& traversableCon){
    size=0;
    a=dista(gen);
    b=distb(gen);
    tableSize = 1<<(std::ceil(std::log2(traversableCon.Size() * 10)));
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }
    traversableCon.Traverse(
        [this](const Data & data){
            Insert(data);
        }
    );

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIn,const TraversableContainer<Data>& traversableCon){
    size=0;
    a=dista(gen);
    b=distb(gen);
    if(sizeIn<=traversableCon.Size()){
        tableSize = 1<<(std::ceil(std::log2(traversableCon.Size() * 10)));
    }else{
        tableSize = 1<<(std::ceil(std::log2(sizeIn)));
    }
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }
    traversableCon.Traverse(
        [this](const Data & data){
            Insert(data);
        }
    );
}


template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MappableContainer<Data>&& mappableCon){
    size=0;
    a=dista(gen);
    b=distb(gen);
    tableSize = 1<<(std::ceil(std::log2(mappableCon.Size() * 10)));
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }
    mappableCon.Map(
        [this](Data & data){
            Insert(std::move(data));
        }
    );

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIn,MappableContainer<Data>&& mappableCon){
    size=0;
    a=dista(gen);
    b=distb(gen);
    if(sizeIn<=mappableCon.Size()){
        tableSize = 1<<(std::ceil(std::log2(mappableCon.Size() * 10)));
    }else{
        tableSize = 1<<(std::ceil(std::log2(sizeIn)));
    }
    Resize(tableSize);
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]="0";
    }
    mappableCon.Map(
        [this](Data & data){
            Insert(std::move(data));
        }
    );

}

//copy e move constructors

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& hashTable){
    a=hashTable.a;
    b=hashTable.b;
    size=hashTable.size; 
    tableSize=hashTable.tableSize;
    Table=hashTable.Table;
    flags=hashTable.flags;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& hashTable) noexcept{
    std::swap(size,hashTable.size);
    std::swap(a,hashTable.a);
    std::swap(b,hashTable.b);
    std::swap(tableSize,hashTable.tableSize);
    std::swap(Table,hashTable.Table);
    std::swap(flags,hashTable.flags);
}

//destructor

template <typename Data>
HashTableOpnAdr<Data>::~HashTableOpnAdr(){
    Table.Clear();
    flags.Clear();
    size=0;
    tableSize=128;
}

//copy e move assignment

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& hashTable){
    Clear();
    a=hashTable.a;
    b=hashTable.b;
    size=hashTable.size; 
    tableSize=hashTable.tableSize;
    Table=hashTable.Table;
    flags=hashTable.flags;
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& hashTable)noexcept{
    Clear();
    std::swap(size,hashTable.size);
    std::swap(a,hashTable.a);
    std::swap(b,hashTable.b);
    std::swap(tableSize,hashTable.tableSize);
    std::swap(Table,hashTable.Table);
    std::swap(flags,hashTable.flags);
    return *this;
}




/* ************************************************************************** */

}
