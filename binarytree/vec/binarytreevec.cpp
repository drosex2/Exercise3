
namespace lasd {

/* ************************************************************************** */

// NODE VEC

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& data){
    element=data;  
}
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(Data&& data) noexcept{
    element=std::move(data);
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
    return element;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element()const noexcept{
    return element;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept
{
  return ((2*index+1)<tree->Size());

}


template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept
{
    return ((2*index+2)<tree->Size());
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(HasLeftChild()){
        return *((*tree)[2*index+1]);
    }else{
        throw std::out_of_range("There isn't a left child!");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()){
        return *((*tree)[2*index+1]);
    }else{
        throw std::out_of_range("There isn't a left child!");
    }
}

template <typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(HasRightChild()){
        return *((*tree)[2*index+2]);
    }else{
        throw std::out_of_range("There isn't a right child!");
    }
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()){
        return *((*tree)[2*index+2]);
    }else{
        throw std::out_of_range("There isn't a right child!");
    }
}

//BINARY TREE VEC

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const TraversableContainer<Data>& traversableCon){
    vector.Resize(traversableCon.Size());
    unsigned long index=0;
    traversableCon.Traverse(
        [this, &index](const Data &data)
        {
            vector[index] = new NodeVec(data);
            vector[index]->index = index;
            vector[index]->tree = &vector;
            index++;
        }
    );
    size=traversableCon.Size();
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MappableContainer<Data>&& mappableCon){
    vector.Resize(mappableCon.Size());
    unsigned long index=0;
    mappableCon.Map(
        [this,&index](Data & data){
            vector[index]=new NodeVec();
                vector[index]->element=(std::move(data));
                vector[index]->index=index;
                vector[index]->tree=&vector;
                index++;
        }
    );
    size=mappableCon.Size();
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& binTree){
    vector.Resize(binTree.size);
    size=binTree.size;
    for(unsigned long i=0;i<binTree.size;i++){
        vector[i]=new NodeVec(binTree.vector[i]->Element());
        vector[i]->index=binTree.vector[i]->index;
        vector[i]->tree=&vector;
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& binTree)noexcept{
    std::swap(size,binTree.size);
    std::swap(vector,binTree.vector);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    for (unsigned long i = 0; i < vector.Size(); i++)
        {
            delete vector[i];
        }
    vector.Clear();
    size = 0;
}
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& binTree){
    Clear();
    vector.Resize(binTree.size);
    size=binTree.size;
    for(unsigned long i=0;i<binTree.size;i++){
        vector[i]=new NodeVec(binTree.vector[i]->Element());
        vector[i]->index=binTree.vector[i]->index;
        vector[i]->tree=&vector;
    }
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& binTree)noexcept{
    
    std::swap(size,binTree.size);
    std::swap(vector,binTree.vector);
    return *this;
}

template<typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& binTree)const noexcept{
    bool ret=true;
    if(vector.Size()==binTree.vector.Size()){
        unsigned long i=0;
        while(i<vector.Size() && ret){
            if(vector[i]->Element()==binTree.vector[i]->Element()){
                ret=true;
            }else{
                ret=false;
            }
            i++;
        }
    }else{
        ret=false;
    }
    return ret;
}

template<typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& binTree)const noexcept{
    return !(*this==binTree);
}

template<typename Data>
const typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() const{
    if(!vector.Empty()){
        return *vector[0];
    }else{
        throw std::length_error("The tree is empty!");
    }
}

template<typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root() {
    if(!vector.Empty()){
        return *(vector[0]);
    }else{
        throw std::length_error("The tree is empty!");
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    if (size > 0){      
        for (unsigned long i = 0; i < vector.Size(); i++)
        {
            delete vector[i];
        }
        vector.Clear();
        size = 0;
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthTraverse(TraverseFun fun) const{
    for(unsigned long i=0;i<vector.Size();i++){
        fun(vector[i]->element);
    }
}

template<typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFun fun){
    for(unsigned long i=0;i<vector.Size();i++){
        fun(vector[i]->element);
    }
}
/* ************************************************************************** */

}
