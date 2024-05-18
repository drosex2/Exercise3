
namespace lasd {

/* ************************************************************************** */
//specific constructors
template <typename Data>
StackVec<Data>::StackVec():Vector<Data>(0){};
template <typename Data>
StackVec<Data>::StackVec(const TraversableContainer<Data>& container):Vector<Data>(container),index(size){};

template <typename Data>
StackVec<Data>::StackVec(MappableContainer<Data>&& container):Vector<Data>(std::move(container)),index(size){};


//copy constructor
template <typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackVecCopy):Vector<Data>(stackVecCopy),index(stackVecCopy.index){};

//move constructor
template <typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackVecMove) noexcept :Vector<Data>(std::move(stackVecMove)){
    std::swap(index,stackVecMove.index);
}


//copy assignment
template <typename Data>
const StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackVecCopy){
    StackVec<Data> *tmpStack= new StackVec<Data>(stackVecCopy);
        std::swap(*tmpStack,*this);
        delete tmpStack;
        return *this;
}

//move assignment
template <typename Data>
const StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackVecMove) noexcept {
    Vector<Data>::operator=(std::move(stackVecMove));
    std::swap(index,stackVecMove.index);
    return *this;
}

//comparison operators (identico a quello di vector con la differenza di index invece di size)
template <typename Data>
bool StackVec<Data>::operator==(const StackVec<Data>& stackVec) const noexcept{
    if (index==stackVec.index){ 
            for(unsigned long i=0;i<index;++i){
                if (Elements[i]!= stackVec.Elements[i]){
                    return false; // se uno degli elementi è diverso → return false
                }
            }
            return true; // se tutti gli elementi sono uguali → return true
        } else {
            return false;// se le dimensioni non coincidono → return false
        }
}
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec<Data>& stackVec) const noexcept{
    return !(*this==stackVec);
}

//member functions
template <typename Data>
const Data& StackVec<Data>::Top() const{
    if (index!=0){
        return Elements[index-1];
        
    }
    else{
        throw std::length_error("Access to an empty stack vector!");
    }
}
template <typename Data>
Data& StackVec<Data>::Top() {
    if (index!=0){
       
        return Elements[index-1];
        
    }
    else{
        throw std::length_error("Access to an empty stack vector!");
    }
}

template <typename Data>
void StackVec<Data>::Pop(){
    if(index!=0){
        Reduce();
        --index;
       
    }
    else{
        throw std::length_error("Access to an empty stack vector!");
    }
}

template <typename Data>
Data StackVec<Data>::TopNPop(){
    if(index!=0){
        Reduce();
        index--;
        return std::move(Elements[index]);
        
    }
    else{
        throw std::length_error("Access to an empty stack vector!");
    }
}

template <typename Data>
void StackVec<Data>::Push(const Data& dato){
   
    Expand();
    Elements[index]=dato;
    index++;
    //std::cout<<index<<" ";
    
}

template <typename Data>
void StackVec<Data>::Push(Data&& dato){
    Expand();
    Elements[index]=std::move(dato);
    index++;
    //std::cout<<index<<" ";
    
}

//empty function
template <typename Data>
bool StackVec<Data>::Empty() const noexcept{
    return (index==0);
}

//size function
template <typename Data>
unsigned long StackVec<Data>::Size()const noexcept{
    return index;
}

//clear function
template <typename Data>
void StackVec<Data>::Clear(){
    index=0;
    Vector<Data>::Resize(1);
}

//expand
template <typename Data>
void StackVec<Data>::Expand(){
    if(index==size){
        if(size!=0){
            Vector<Data>::Resize(size * 2);
        }
        else{
            Vector<Data>::Resize(2);
        }
                
    }
}

//reduce
template <typename Data>
void StackVec<Data>::Reduce(){
    if(index==(size/4)){
        Vector<Data>::Resize((size/2));
    }
}
/* ************************************************************************** */

}
