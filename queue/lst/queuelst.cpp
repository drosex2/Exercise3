
namespace lasd {

/* ************************************************************************** */
//default constructor
template <typename Data>
QueueLst<Data>::QueueLst():List<Data>(){};

//specific constructor
template <typename Data>
QueueLst<Data>::QueueLst(const TraversableContainer<Data>& con):List<Data>(con){};

template <typename Data>
QueueLst<Data>::QueueLst(MappableContainer<Data>&& con):List<Data>(std::move(con)){};

//copy constructor
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst<Data>& queue ):List<Data>(queue){};

//move constructor
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst<Data>&& queue) noexcept :List<Data>(std::move(queue)){};

//copy assignment
template <typename Data>
const QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst<Data>& queue){
    List<Data>::operator=(queue);
    return *this;
}
//move assignment
template <typename Data>
const QueueLst<Data>& QueueLst<Data>::operator=(QueueLst<Data>&& queue) noexcept{
    List<Data>::operator=(std::move(queue));
    return *this;
}

//comparison operators
template <typename Data>
bool  QueueLst<Data>::operator==(const QueueLst<Data>& queue) const noexcept{
    return List<Data>::operator==(queue);
}
template <typename Data>
bool  QueueLst<Data>::operator!=(const QueueLst<Data>& queue) const noexcept{
    return List<Data>::operator!=(queue);
}

//member functions
template <typename Data>
const Data& QueueLst<Data>::Head() const{
    return List<Data>::Front();
}

template <typename Data>
Data& QueueLst<Data>::Head(){
    return List<Data>::Front();
}

template <typename Data>
void QueueLst<Data>::Dequeue(){
    List<Data>::RemoveFromFront();
}

template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
    return List<Data>::FrontNRemove();
}

template <typename Data>
void QueueLst<Data>::Enqueue(const Data& dato){
    List<Data>::InsertAtBack(dato);
}

template <typename Data>
void QueueLst<Data>::Enqueue(Data&& dato){
    List<Data>::InsertAtBack(std::move(dato));
}
/* ************************************************************************** */

}
