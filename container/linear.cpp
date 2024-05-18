
namespace lasd {
#include <iostream>

/* ************************************************************************** */

template <typename Data>
const Data& LinearContainer<Data>::Front() const{
    if (size>0){
        return operator[](0);
    }
    else
    {
        throw std::length_error("The container is empty!");
    }
}

template <typename Data>
Data& LinearContainer<Data>::Front() {
    if (size>0){
        return operator[](0);
    }
    else
    {
        throw std::length_error("The container is empty!");
    }
}

template <typename Data>
const Data& LinearContainer<Data>::Back() const{
    if (size>0){
        return operator[](size-1);
    }
    else
    {
        throw std::length_error("The container is empty!");
    }
}

template <typename Data>
Data& LinearContainer<Data>::Back() {
    if (size>0){
        return operator[](size-1);
    }
    else
    {
        throw std::length_error("The container is empty!");
    }
}

template <typename Data>
inline void LinearContainer<Data>::Traverse(TraverseFun function) const{
    PreOrderTraverse(function);
}

template <typename Data>
void LinearContainer<Data>::PreOrderTraverse(TraverseFun function) const{
    for(unsigned long i=0;i<size;++i){
        function(operator[](i));
    }    
}

template <typename Data>
void LinearContainer<Data>::PostOrderTraverse(TraverseFun function) const{
    
    if(size>0){
        unsigned long i=size;
        do{
            i--;
            function(operator[](i));
            
        }while(i>0);
            
    }
    
}

template <typename Data>
inline void LinearContainer<Data>::Map(MapFun function) {
    PreOrderMap(function);
}
template <typename Data>
void LinearContainer<Data>::PreOrderMap(MapFun function){
    for(unsigned long i=0;i<size;++i){
        function(operator[](i));
    }
}

template <typename Data>
void LinearContainer<Data>::PostOrderMap(MapFun function){
    if(size>0){
        unsigned long i=size;
        do{
            i--;
            function(operator[](i));
            
        }while(i>0);
            
    }
}
template <typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer& linearContainer)const noexcept{
    if(size==linearContainer.size)
    {
        for(unsigned long i=0;i<size;++i)
        {
            if(operator[](i)!=linearContainer.operator[](i)){
                return false;
            }
                
        }
        return true;
    }else{
        return false;
    }
}

template <typename Data>
inline bool LinearContainer<Data>::operator!=(const LinearContainer& linearContainer)const noexcept{
    return !(*this==linearContainer);
}
/* ************************************************************************** */
template <typename Data>
inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer<Data>& con) const noexcept{
    return LinearContainer<Data>::operator==(con);
}

template <typename Data>
inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer<Data>& con) const noexcept{
    return LinearContainer<Data>::operator!=(con);
}

template <typename Data>
void SortableLinearContainer<Data>::Sort() noexcept {
    QuickSort(0,size-1);
}

template <typename Data>
void SortableLinearContainer<Data>::QuickSort(unsigned long p, unsigned long r) noexcept{
    if (p<r){
        unsigned long q =Partition(p,r);
        QuickSort(p,q);
        QuickSort(q+1,r);
    }
}
template <typename Data>
unsigned long SortableLinearContainer<Data>::Partition(unsigned long p, unsigned long r) noexcept{

    Data pivot=operator[](p);
    unsigned long i=p-1;
    unsigned long j=r+1;

    do{
        do{
            j--;
        }while(pivot < operator[](j));
        do{
            i++;
        }while(pivot > operator[](i));

        if(i<j)
        {
            std::swap(operator[](i),operator[](j));
        }
    }while(i<j);
    return j;
}
}
