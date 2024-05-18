
namespace lasd {

/* ************************************************************************** */
//specific constructors
template <typename Data>
StackLst<Data>::StackLst(const TraversableContainer<Data>& container):List<Data>(container){};

template <typename Data>
StackLst<Data>::StackLst(MappableContainer<Data>&& container):List<Data>(std::move(container)){};

//copy constructor
template <typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& stackLstCopy):List<Data>(stackLstCopy){};

//move constructor
template <typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& stackLstMove) noexcept:List<Data>(std::move(stackLstMove)){};

//copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst<Data>& stackLstCopy){
    List<Data>::operator=(stackLstCopy);
    return *this;
}
//move assignment
template  <typename  Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst<Data>&& stackLstMove) noexcept{
    List<Data>::operator=(std::move(stackLstMove));
    return *this;
}

//comparison operators
template <typename Data>
bool StackLst<Data>::operator==(const StackLst<Data>& stackLst)const noexcept{
    return List<Data>::operator==(stackLst);
}
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst<Data>& stackLst)const noexcept{
    return List<Data>::operator!=(stackLst);
}

//member functions
template <typename Data>
const Data& StackLst<Data>::Top() const{
    return List<Data>::Front();
}

template <typename Data>
Data& StackLst<Data>::Top(){
    return List<Data>::Front();
}

template <typename Data>
void StackLst<Data>::Pop(){
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data StackLst<Data>::TopNPop(){
   return List<Data>::FrontNRemove();
}

template <typename Data>
void StackLst<Data>::Push(const Data& dato){
    List<Data>::InsertAtFront(dato);
}

template <typename Data>
void StackLst<Data>::Push(Data&& dato){
    List<Data>::InsertAtFront(std::move(dato));
}
/* ************************************************************************** */

}
