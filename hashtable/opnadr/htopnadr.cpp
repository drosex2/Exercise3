#include <cmath>
namespace lasd {



/* ************************************************************************** */
// DEFAULT CONSTRUCTOR
template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    size=0;
    a=dista(gen);
    b=distb(gen);
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
    }
}

//specific constructors

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long sizeIn){
    size=0;
    a=dista(gen);
    b=distb(gen);
    tableSize=std::pow(2,(std::ceil(std::log2(sizeIn)))); //calcolo la potenza di 2 superiore a sizeIn
    //tableSize=sizeIn;
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
    }

}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const TraversableContainer<Data>& traversableCon){
    size=0;
    a=dista(gen);
    b=distb(gen);
    tableSize = std::pow(2,(std::ceil(std::log2(traversableCon.Size()*10))));
    //tableSize=traversableCon.Size()*10;
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
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
        tableSize = std::pow(2,(std::ceil(std::log2(traversableCon.Size()*10))));
        tableSize=traversableCon.Size()*10;
    }else{
        tableSize = std::pow(2,(std::ceil(std::log2(sizeIn))));
        //tableSize=sizeIn;
    }
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
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
    tableSize = std::pow(2,(std::ceil(std::log2(mappableCon.Size()*10))));
    //tableSize=mappableCon.Size()*10;
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
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
        tableSize = std::pow(2,(std::ceil(std::log2(mappableCon.Size()*10))));
        //tableSize=mappableCon.Size()*10;
    }else{
        tableSize = std::pow(2,(std::ceil(std::log2(sizeIn))));
        //tableSize=sizeIn;
    }
    Vector<Data> t(tableSize);
    Vector<char> f(tableSize);
    Table=t;
    flags=f;
    for(unsigned long i=0;i<tableSize;i++){
        flags[i]='0';
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

//operator == e !=

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& hashTableCmp) const noexcept{
    bool val=true;
    if(size==hashTableCmp.size){
        unsigned long i=0;
        while(i<tableSize && val){
            if(flags[i]=='1'){
                    if(hashTableCmp.Exists(Table[i])){
                    val=true;
                }else{
                    val=false;
                }
            }
            i++;
        }
    }else{
        return false;
    }
    return val;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& hashTableCmp) const noexcept{
    return !(*this==hashTableCmp);
}


//INSERT E REMOVE

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& data){
    if(!Exists(data)){
        unsigned long ind=FindEmpty(data);
        if(ind<tableSize){
            Table[ind]=data;
            flags[ind]='1';
            size++;
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& data){
    if(!Exists(data)){
        unsigned long ind=FindEmpty(data);
        if(ind<tableSize){
            Table[ind]=std::move(data);
            flags[ind]='1';
            size++;
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& data){
    unsigned long ind=Find(data);
    if(ind!=tableSize){
        flags[ind]='2';
        size--;
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& data) const noexcept{
    unsigned long ind=Find(data);
    if(ind!=tableSize){
        return true;
    }else{
        return false;
    }
}

//Resize

template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long newSize){
    if(newSize>tableSize){
        tableSize = std::pow(2,(std::ceil(std::log2(newSize))));
        //tableSize=newSize;
        Vector<Data> oldTable;
        oldTable=Table;
        Vector<Data> newTable(tableSize);
        Table=newTable;
        Vector<char> oldFlags(tableSize);
        oldFlags=flags;
        Vector<char> newFlags(tableSize);
        for(unsigned long i=0;i<tableSize;i++){
            newFlags[i]='0';
        }
        flags=newFlags;
        
        size=0;
        for(unsigned long j=0;j<oldTable.Size();j++){
            if(oldFlags[j]=='1'){
                Insert(oldTable[j]);
            }
            
        }

    }
}

//clear

template <typename Data>
void HashTableOpnAdr<Data>::Clear(){
    if(size>0){
        // Table.Clear();
        // flags.Clear();
        for(unsigned long i=0;i<tableSize;i++){
            flags[i]='0';
        }
        size=0;
    }
}


//funzioni protette
template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& data, unsigned long i) const noexcept{
    return (HashKey(data)+11*i)%tableSize;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& data) const noexcept{
    unsigned long i=0;
    unsigned long key=HashKey(data,0);
    while(i<tableSize){
        key=HashKey(data,i);
        if(Table[key]==data && flags[key]=='1'){
            return key;
        }else{
            i++;
        }
    }
    return tableSize;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& data)const noexcept{
    unsigned long i=0;
    unsigned long key=0;
    do{
        key=HashKey(data,i);
        if(flags[key]!='1'){
            return key;
        }else{
            i++;
        }
    }while(i<tableSize);
    return tableSize;
}



/* ************************************************************************** */

}
