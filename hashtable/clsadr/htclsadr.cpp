
namespace lasd {

/* ************************************************************************** */
// DEFAULT CONSTRUCTOR
template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    Resize(tableSize);
}

//specific constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIn){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    if(sizeIn>maxTableSize){
        sizeIn=maxTableSize;
    } 
    tableSize=sizeIn;
    Resize(tableSize);

}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const TraversableContainer<Data>& traversableCon){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    Resize(tableSize);
    traversableCon.Traverse(
            [this](const Data & data){
                Insert(data);
            }
        );

}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIn,const TraversableContainer<Data>& traversableCon ){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    if(sizeIn>maxTableSize){
        sizeIn=maxTableSize;
    } 
    tableSize=sizeIn;
    //Table=new Vector<List<Data>>(tableSize);
    Resize(tableSize);
    traversableCon.Traverse(
            [this](const Data & data){
                Insert(data);
            }
        );

}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MappableContainer<Data>&& mappableCon){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    Resize(tableSize);
    mappableCon.Map(
            [this]( Data & data){
                Insert(std::move(data));
            }
        );

}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long sizeIn,MappableContainer<Data>&& mappableCon ){
    size=0;
    a=dista(gen)*2+1;
    b=distb(gen);
    if(sizeIn>maxTableSize){
        sizeIn=maxTableSize;
    }  
    tableSize=sizeIn;
    Resize(tableSize);
    mappableCon.Map(
            [this](Data & data){
                Insert(std::move(data));
            }
        );

}

//copy e move constructors

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data> & hashTable){ 
    a=hashTable.a;
    b=hashTable.b;
    size=hashTable.size; 
    tableSize=hashTable.tableSize;
    Table=hashTable.Table;
    
    
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& hashTable) noexcept{
   
    std::swap(size,hashTable.size);
    std::swap(a,hashTable.a);
    std::swap(b,hashTable.b);
    std::swap(tableSize,hashTable.tableSize);
    Vector<List<Data>> newTable(tableSize);
    Table=newTable;
    std::swap(Table,hashTable.Table);
}

template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr(){
    a=1;
    b=0;
    for(unsigned long i=0;i<tableSize;i++){
        Table[i].Clear();
    }
    Table.Clear();
    tableSize=128;
    size=0;

}

template <typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& hashTable){
    //Clear();
    a=hashTable.a;
    b=hashTable.b;
    size=hashTable.size; 
    tableSize=hashTable.tableSize;
    Table=hashTable.Table;
    return *this;
}

template <typename Data>
HashTableClsAdr<Data> & HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& hashTable)noexcept{
    //Clear();
    std::swap(size,hashTable.size);
    std::swap(a,hashTable.a);
    std::swap(b,hashTable.b);
    std::swap(tableSize,hashTable.tableSize);
    std::swap(Table,hashTable.Table);
    return *this;
}


//operator == e !=

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& hashTableCmp) const noexcept{
    bool val=true;
    if(size==hashTableCmp.size){
        unsigned long i=0;
        while(i<tableSize && val){
            unsigned long j=0;
            while(j<Table[i].size && val){
                if(hashTableCmp.Exists(Table[i].operator[](j))){
                    
                    val=true;
                }else{
                    val=false;
                }
                j++;
            }
            i++;
        }
    }else{
        return false;
    }
    return val;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& hashTableCmp) const noexcept{
    return !(*this==hashTableCmp);
}
// FUNZIONI DI INSERT E REMOVE

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& data){
    if(Table[HashKey(data)].Insert(data)){
        size++;
        return true;
    }else{
        return false;
    }
}


template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& data){
    if(Table[HashKey(data)].Insert(std::move(data))){
        size++;
        return true;
    }else{
        return false;
    }
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& data){
    if(Table[HashKey(data)].Remove(data)){
        size--;
        return true;
    }else{
        return false;
    }
}

//EXISTS

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& data)const noexcept{
    return (Table[HashKey(data)].Exists(data));
}
//RESIZE
template <typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long newSize ){
    if(newSize==0){
        Clear();
    }
    else{
        if(newSize>maxTableSize){
            newSize=maxTableSize;
        }    
        Vector<List<Data>> oldTable;
        oldTable=Table;
        Vector<List<Data>> newTable(newSize);
        Table=newTable;
        tableSize=newSize;
        size=0; //dato che inserisco i vecchi elementi la size verrà nuovamente incrementata, se non la azzero risulterà essere il doppio
        for(unsigned long i=0;i<oldTable.Size();i++){
            for(unsigned long j=0;j<oldTable[i].size;j++){
                Insert(oldTable[i].operator[](j));
            }
        }
    }
    //oldTable.Clear();
}

//CLEAR
template <typename Data>
void HashTableClsAdr<Data>::Clear(){
    if(size>0){
        for(unsigned long i=0;i<tableSize;i++){
            Table[i].Clear();
        }
        
        tableSize=128;
        Vector<List<Data>> newTable(tableSize);
        Table=newTable;
        size=0;
    }
}
/* ************************************************************************** */

}
