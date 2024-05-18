
namespace lasd {

/* ************************************************************************** */
//default constructor
template <typename Data>
QueueVec<Data>::QueueVec():Vector<Data>(4){};

//specific constructors
template <typename Data>
QueueVec<Data>::QueueVec(const TraversableContainer<Data>& container):Vector<Data>(container), tail(size){
    Vector<Data>::Resize(size*2);
};

template <typename Data>
QueueVec<Data>::QueueVec(MappableContainer<Data>&& container):Vector<Data>(container),tail(size){
    Vector<Data>::Resize(size*2);
};

//copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec<Data>& queueVecCopy):Vector<Data>(queueVecCopy),head(queueVecCopy.head),tail(queueVecCopy.tail){};

//move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec<Data>&& queueVecMove) noexcept :Vector<Data>(std::move(queueVecMove)){
    std::swap(head,queueVecMove.head);
    std::swap(tail,queueVecMove.tail);

    
}

//copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec<Data>& queueVecCopy){
    Vector<Data>::operator=(queueVecCopy);
    head=queueVecCopy.head;
    tail=queueVecCopy.tail;
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec<Data>&& queueVecMove) noexcept{
    Vector<Data>::operator=(std::move(queueVecMove));
    std::swap(head,queueVecMove.head);
    std::swap(tail,queueVecMove.tail);
    return *this;
}

//comparison operators
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec<Data>& queueVec)const noexcept{
    if(Size()==queueVec.Size()){
            if(size==queueVec.size){
            unsigned long i=head;
            unsigned long j=queueVec.head;
            while(i!=tail){
                if(Elements[i]!=queueVec.Elements[j]){
                    return false;
                }
                i=(i+1)%size; //incremento dell'indice in modulo size
                j=(j+1)%queueVec.size;//incremento dell'indice in modulo size
            }
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
    
}

template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec<Data>& queueVec) const noexcept{
    return !(*this==queueVec);
}

//member functions
template <typename Data>
const Data& QueueVec<Data>::Head() const{
    if(!(Empty())){
        return Elements[head];
    }else{
        throw std::length_error("Access to an empty queue vector");
    }
}
template <typename Data>
Data& QueueVec<Data>::Head() {
    if(!(Empty())){
        return Elements[head];
    }else{
        throw std::length_error("Access to an empty queue vector");
    }
}
template <typename Data>
void QueueVec<Data>::Dequeue(){
    if(!(Empty())){
        Reduce();
        head=(head+1)%size;//incremento circolare di head
    }else{
        throw std::length_error("Access to an empty queue vector!");
    }
}
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
    if(!(Empty())){
        Reduce();
        Data ret(std::move(Elements[head]));
        head=(head+1)%size;//incremento circolare di head
        return ret;
    }else{
        throw std::length_error("Accesso to an empty queue vector");
    }
}

template <typename Data>
void QueueVec<Data>::Enqueue(const Data& dato){
    Expand();
    Elements[tail]=dato;
    tail= (tail+1)%size;//incremento circolare di tail
}
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& dato){
    Expand();
    Elements[tail]=std::move(dato);
    tail= (tail+1)%size;//incremento circolare di tail
}


//empty function
template<typename Data>
bool QueueVec<Data>::Empty()const noexcept{
    return (head==tail);
}

//size function
template <typename Data>
unsigned long QueueVec<Data>::Size()const noexcept{
    return (((size+tail)-head)%size);
}

//clear function
template <typename Data>
void QueueVec<Data>::Clear(){
    Vector<Data>::Resize(4);
    head=tail=0;
}

//expand function
template <typename Data>
void QueueVec<Data>::Expand(){
    unsigned long dim=Size();
    if(size==dim+1){
        Resize(size*2,dim);
    }
}

template <typename Data>
void QueueVec<Data>::Reduce(){
    unsigned long dim=Size();
    if((size/4)==dim+1){
        Resize(size/2,dim);
    }
}

template <typename Data>
void QueueVec<Data>::Resize(unsigned long newsize, unsigned long n){
    Data * tmp=new Data[newsize];
    unsigned long max;
    if(n<=newsize){
        max=n;
    }else{
        max=newsize;
    }
    unsigned long i=head;
    unsigned long j=0;
    while(j<max){
        std::swap(Elements[i],tmp[j]);
        i=(i+1)%size;
        j=(j+1)%size;
    }
    std::swap(Elements,tmp);
    delete[] tmp;
    head=0;
    tail=n;
    size=newsize;
}
/* ************************************************************************** */

}
