

namespace lasd {

/* ************************************************************************** */
    //VECTOR
    //constructors
    template <typename Data>
    Vector<Data>::Vector(const unsigned long n){
        size=n;
        Elements=new Data[size]{};
    }

    template <typename Data>
    Vector<Data>::Vector(const TraversableContainer<Data>& traversableCon): Vector(traversableCon.size){
        unsigned long index=0;
        traversableCon.Traverse(
            [this, &index](const Data & data){
                Elements[index++]=data;
            }
        );
    }

    template <typename Data>
    Vector<Data>::Vector(MappableContainer<Data>&& mappableCon) : Vector(mappableCon.size){
        unsigned long index=0;
        mappableCon.Map(
            [this, &index](Data & data){
                Elements[index++]=std::move(data);
            }
        );
        
    }

    //Copy constructor
    template <typename Data>
    Vector<Data>::Vector(const Vector<Data>& vectorCopy) {
        size=vectorCopy.size;
        Elements = new Data[size];
        std::copy(vectorCopy.Elements, vectorCopy.Elements+vectorCopy.size, Elements);
    }

    //Move constructor
    template <typename Data>
    Vector<Data>::Vector(Vector<Data>&& vectorMove) noexcept {
        std::swap(size,vectorMove.size);
        std::swap(Elements,vectorMove.Elements);
    }

    //Destructor
    template<typename Data>
    Vector<Data>::~Vector(){
        delete[] Elements;
    }

    //Copy assignment 
    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vectorCopy){
        // Vector<Data> *tmpVector= new Vector<Data>(vectorCopy);
        // std::swap(*tmpVector,*this);
        // delete tmpVector;
        // return *this;
        size=vectorCopy.size;
        delete[] Elements;
        Elements=new Data[size];
        std::copy(vectorCopy.Elements, vectorCopy.Elements+vectorCopy.size, Elements);
        return *this;
    }

    //Move assignment
    template<typename Data>
    Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vectorMove) noexcept{
        std::swap(size, vectorMove.size);
        std::swap(Elements, vectorMove.Elements);
        return *this;
    }

    //Comparison operators
    template <typename Data>
    bool Vector<Data>::operator==(const Vector<Data> & vectorComp)const noexcept{
        if (size==vectorComp.size){
            for(unsigned long index=0;index<size;++index){
                if (Elements[index]!= vectorComp.Elements[index]){
                    return false; // se uno degli elementi è diverso → return false
                }
            }
            return true; // se tutti gli elementi sono uguali → return true
        } else {
            return false;// se le dimensioni non coincidono → return false
        }
    }

    template<typename Data>
    inline bool Vector<Data>::operator!=(const Vector<Data>& vectorComp) const noexcept{
        return !(*this==vectorComp); //duale di ==
    }

    //clear function (inherited from ClearableContainer)

    template<typename Data>
    void Vector<Data>::Clear(){
        delete[] Elements;
        size=0;
        Elements=nullptr;
    }

    //resize function (inherited from ResizableContainer)
    template<typename Data>
    void Vector<Data>::Resize(const unsigned long newSize)  {
        if(newSize==0){
            Clear(); //se la nuova dimensione è 0 → applico la Clear()
        } else if(size!= newSize){
            Data * tmpElements= new Data[newSize] {}; //contenitore temporaneo riempito di valori di default
            unsigned long minSize;
            if (size<newSize){
                minSize=size;
            }else
            {
                minSize =newSize;
            }
            for(unsigned long index=0; index < minSize;index++){
                std:: swap(Elements[index], tmpElements[index]);
            }
            std::swap(Elements,tmpElements);
            size=newSize;
            delete[] tmpElements;
        }
        
    }

    //operator[] (non-mutable)
    template <typename Data>
    const Data& Vector<Data>::operator[](const unsigned long index) const {
        if(index<Size())
        {
            return Elements[index];
        }else
        {
            throw std::out_of_range("Access to the vector at index: "+ std::to_string(index)+" is out of range");
        }
    };
    //operator[] (mutable)
    template <typename Data>
    Data& Vector<Data>::operator[](const unsigned long index) {
        if(index<Size())
        {
            return Elements[index];
        }else
        {
            throw std::out_of_range("Access to the vector at index: "+ std::to_string(index)+" is out of range");
        }
    };
    

    //function front (non-mutable)
    template <typename Data>
    const Data& Vector<Data>::Front() const {
        if(size>0){
            return Elements[0];
        }else
        {
            
            throw std::length_error("Access to an empty vector");
        }
    };

    //function front (mutable)
    template <typename Data>
     Data& Vector<Data>::Front()  {
        if(size>0){
            return Elements[0];
        }else
        {
           
            throw std::length_error("Access to an empty vector");
        }
    };

    //function back (non-mutable)
    template <typename Data>
    const Data& Vector<Data>::Back() const {
        if(size>0)
        {
            return Elements[size-1];
        }else
        {
           
            throw std::length_error("Access to an empty vector");
        }
    };

    //function back (mutable)
    template <typename Data>
     Data& Vector<Data>::Back()  {
        if(size>0)
        {
            return Elements[size-1];
        }else
        {
            
            throw std::length_error("Access to an empty vector");
        }
    };

    /*******************************************************************/
    //SORTABLE VECTOR

    //constructors
    //specific
    template <typename Data>
    SortableVector<Data>::SortableVector(const unsigned long n) : Vector<Data>(n){};

    //from traversableContainer
    template <typename Data>
    SortableVector<Data>::SortableVector(const TraversableContainer<Data>& traversableContainer): Vector<Data>(traversableContainer){};

    //from mappable conainer
    template <typename Data>
    SortableVector<Data>::SortableVector( MappableContainer<Data>&& mappableContainer): Vector<Data>(std::move(mappableContainer)){};


    //copy constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(const SortableVector<Data>& sortableVectorCopy): Vector<Data>(sortableVectorCopy){};

    //move constructor
    template <typename Data>
    SortableVector<Data>::SortableVector(SortableVector<Data>&& sortableVectorMove) noexcept: Vector<Data>(std::move(sortableVectorMove)){};

    // template<typename Data>
    // SortableVector<Data>::~SortableVector(){
        
    // };

    //Copy assignment
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(const SortableVector<Data>& vectorCopy){
        Vector<Data>::operator=(vectorCopy);
        return *this;
    }

    //Move assignment
    template <typename Data>
    SortableVector<Data>& SortableVector<Data>::operator=(SortableVector<Data>&& vectorMove){
        Vector<Data>::operator=(std::move(vectorMove));
        return *this;
    }

    template <typename Data>
    const Data& SortableVector<Data>::operator[] (unsigned long i)const {
        return Vector<Data>::operator[](i);
    }
    template <typename Data>
     Data& SortableVector<Data>::operator[](unsigned long i){
        return Vector<Data>::operator[](i);
    }
}
