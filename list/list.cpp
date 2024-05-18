
 namespace lasd {

    // /* ************************************************************************** */

    // NODE
    //specific constructor
    template<typename Data>
    List<Data>::Node::Node(Data&& data) noexcept{
        std::swap(element,data);
    }

    //move constructor
    template<typename Data>
    List<Data>::Node::Node(Node&& node) noexcept{
        std::swap(element,node.element);
        std::swap(next,node.next);
    }

    //destructor
    template <typename Data>
    List<Data>::Node::~Node(){
        delete this->next;
    }

    //comparison operators
    template<typename Data>
    bool List<Data>::Node::operator==(const Node& node) const noexcept{
        return (element==node.element);
    }
    template<typename Data>
    inline bool List<Data>::Node::operator!=(const Node& node) const noexcept{
        return !(*this==node);
    }

    //clone function
    template<typename Data>
    List<Data>::Node* List<Data>::Node::Clone(Node* tail){
        if(next==nullptr){
            return tail;
        } else {
            Node* node=new Node(element);
            node-> next =next ->Clone(tail);
            return node;
        }

    }

    /********************LIST********************************/
    //costructors
    //from traversableContainer
    template<typename Data>
    List<Data>::List(const TraversableContainer<Data>& traversableCon) {
        traversableCon.Traverse(
            [this](const Data& data){
                InsertAtBack(data);
            }
        );
    }

    //from mappableContainer
    template<typename Data>
    List<Data>::List(MappableContainer<Data>&& mappableCon) {
        mappableCon.Map(
            [this](Data& data){
                InsertAtBack(std::move(data));
            }
        );
        //std::swap(size,mappableCon.size);
    }

    //copy constructor
    template <typename Data>
    List<Data>::List(const List<Data>& listCopy){
        
        if(this != &listCopy){                                
            if(listCopy.tail==nullptr){
            head=nullptr;
            tail=nullptr;
            size=0;
            }
            else{
                struct Node* curr;
                curr=listCopy.head;
                struct Node* node=new Node(curr->element);
                head=node;
                tail=head;
                curr=curr->next;
                while(curr != nullptr){
                    struct Node* newnode=new Node(curr->element);
                    tail->next=newnode;
                    tail=newnode;
                    curr=curr->next;
                }
                size=listCopy.size;
                }
         }
                
    }

    template <typename Data>
    List<Data>::List(List<Data>&& listMove) noexcept{
        std::swap(size,listMove.size);
        std::swap(head,listMove.head);
        std::swap(tail,listMove.tail);
        
        
    }


    //destructor
    template <typename Data>
    List<Data>::~List(){
        delete head;
    }

    //copy assignment //da rivedere
    template<typename Data> 
    List<Data>& List<Data>::operator=(const List<Data>& listCopy){
        // List<Data> *tmpList = new List<Data>(listCopy);
        // std::swap(*tmpList, *this);
        // delete tmpList;
        // return *this;
        if(size<=listCopy.size){
            if(tail==nullptr){
                List<Data> * tmpList= new List<Data>(listCopy);
                std::swap(*tmpList,*this);
                delete tmpList;
            }else{
                Node * headCopy=listCopy.head;
                for(Node * current=head; current!=nullptr;current=current->next, headCopy=headCopy->next){
                    current->element=headCopy->element;
                }
                if(headCopy!=nullptr){
                    Node * tmp= new Node(*listCopy.tail);
                    tail->next=headCopy->Clone(tmp);
                    tail=tmp;
                }
            }
        }else{
            if(listCopy.tail== nullptr){
                delete head;
                tail=head=nullptr;
            }else{
                Node * current = head;
                for(Node * copy=listCopy.head; copy!=nullptr; copy=copy->next, tail = current, current=current->next){
                    current->element=copy->element;
                }
                delete current;
                tail->next= nullptr;
            }
        }
        size=listCopy.size;
        return *this;
    }

    // Move assignment 
    template<typename Data>
    List<Data>& List<Data>::operator=(List<Data>&& listMove) noexcept{
    std::swap(head, listMove.head);
    std::swap(tail, listMove.tail);
    std::swap(size, listMove.size);
    return *this;
    }

    template<typename Data>
    bool List<Data>::operator==(const List<Data>& list) const noexcept{
      if(size == list.size){
         struct Node* current = head;
         struct Node* tmp = list.head;
         unsigned long index=1;
         while(index < size){
            if(current->element != tmp->element){
                return false;
            }
            current = current->next;
            tmp = tmp->next;
            index++;
         }
         current->next=nullptr;
         tmp->next=nullptr;
        
         return true;
      }
      else{
         return false;
      }
        
    }
    template<typename Data>
    bool List<Data>::operator!=(const List<Data>& list) const noexcept{
        return !(*this==list);
    }
    //insert at front (copy)
   template<typename Data>
    void List<Data>::InsertAtFront(const Data& data){
        Node * node=new Node(data);
        node->next=head;
        head=node;
        if(tail== nullptr)
            tail=head;
        size++;
    }

    //insert at front(move)
    template<typename Data>
    void List<Data>::InsertAtFront(Data&& data){
        Node * node=new Node(std::move(data));
        node->next=head;
        head=node;
        if(tail== nullptr)
            tail=head;
        size++;
    }
    //remove front
    template <typename Data>
    void List<Data>::RemoveFromFront(){
        if(head!=nullptr){
            Node * front=head;
            if(tail==head){
                head=tail=nullptr;
            }else{
                head=head->next;
            }
            size--;
            front->next=nullptr;
            delete front;
            
        }else{
            throw std::length_error("Access to an empty list container");
        }
    }
    // remove front and return element of front
    template <typename Data>
    Data List<Data>::FrontNRemove(){
        if (head!=nullptr){
            Node* front=head;
            if(tail==head){
                head=tail=nullptr;
            }else{
                head=head->next;
            }
            size--;
            front->next=nullptr;
            Data ret=std::move(front->element);
            delete front;
            return ret;
        }else{
            throw std::length_error("Access to an empty list!");
        }
    }

    //insert at back(copy)
    template<typename Data>
    void List<Data>::InsertAtBack(const Data& data){
        Node * newTail=new Node(data);
        if(tail==nullptr){
            head=newTail;
        }else{
            tail->next=newTail;
        }
        tail=newTail;
        size++;
    }
    //insert at back (move)
    template<typename Data>
    void List<Data>::InsertAtBack(Data&& data){
        Node * newTail=new Node(std::move(data));
        if(tail==nullptr){
            head=newTail;
        }else{
            tail->next=newTail;
        }
        tail=newTail;
        size++;
    }

    //clear function
    template<typename Data>
    void List<Data>::Clear(){
        struct Node* tmp;
        tmp=head;
        delete tmp; //cancella tutti i nodi (implementazione distruttore nodo)
        tail = nullptr;
        size = 0;
        head = nullptr;
    }

    //insert function
    template<typename Data>
    bool List<Data>::Insert(const Data& data){
        for(Node* currentNode=head;currentNode!= nullptr;currentNode=currentNode->next)
        {
            if(currentNode->element==data){
                return false;
            }
                
        }
        InsertAtBack(data);
        return true;
    }
    template<typename Data>
    bool List<Data>::Insert( Data&& data){
        for(Node* currentNode=head;currentNode!= nullptr; currentNode=currentNode->next)
        {
            if(currentNode->element==data){
                return false;
            }
                
        }
        InsertAtBack(std::move(data));
        return true;
    }

    //remove
    template <typename Data>
    bool List<Data>::Remove(const Data &data){
        Node * tmp =nullptr;
        Node ** currentNode=&head; //puntatore a puntatore , inizialmente punta al puntatore di head
         while(*currentNode!=nullptr)
         {
            if((*currentNode)->element==data){
                Node * node= *currentNode;
                *currentNode= node->next;
                node->next=nullptr;
                delete node;
                size--;
                if(tail==node){
                    tail=tmp;
                }
                return true;
            }
            tmp=*currentNode;
            currentNode=&((*currentNode)->next); // aggiorno il valore puntando il puntatore a next
        }
        return false;
    }
    //operator []
    template <typename Data>
    const Data& List<Data>::operator[](const unsigned long index)const{
        if(index<size){
            Node* currentNode=head;
            for(unsigned long j=0;j<index;++j,currentNode=currentNode->next){}
            return currentNode->element;
         
        }else{
            throw std::length_error("Access to an index of the list out of range!");
        }
    }

    template <typename Data>
     Data& List<Data>::operator[](const unsigned long index){
        if(index<size){
            Node* currentNode=head;
            for(unsigned long j=0;j<index;++j,currentNode=currentNode->next){}
            return currentNode->element;
         
        }else{
            throw std::length_error("Access to an index out of range!");
        }
    }

    //front
    template <typename Data>
    const Data& List<Data>::Front()const{
        if(head!=nullptr){
            return head->element;
        }else{
            throw std::length_error("Access to an empty list!");
        }
    }

    template <typename Data>
    Data& List<Data>::Front(){
        if(head!=nullptr){
           
            return head->element;
         
        }else{
            throw std::length_error("Access to an empty list");
        }
    }
    //back
    template <typename Data>
    const Data& List<Data>::Back()const{
        if(tail!=nullptr){
           
            return tail->element;
         
        }else{
            throw std::length_error("Access to an empty list");
        }
    }

    template <typename Data>
     Data& List<Data>::Back(){
        if(tail!=nullptr){
           
            return tail->element;
         
        }else{
            throw std::length_error("Access to an empty list");
        }
    }

    //traverse

    template <typename Data>
    inline void List<Data>::Traverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun, head);
    }
    template <typename Data>
    inline void List<Data>::PreOrderTraverse(TraverseFun traverseFun) const{
        PreOrderTraverse(traverseFun, head);
    }
    template <typename Data>
    inline void List<Data>::PostOrderTraverse(TraverseFun traverseFun) const{
        PostOrderTraverse(traverseFun, head);
    }
    template <typename Data>
    inline void List<Data>::PreOrderTraverse(TraverseFun traverseFun,const Node* current) const{
        for(;current!=nullptr;current=current->next){
            traverseFun(current->element);
        }
    }

    template <typename Data>
    inline void List<Data>::PostOrderTraverse(TraverseFun traverseFun,const Node* current) const{//obbligatoriamente ricorsiva
       if(current!=nullptr){
        PostOrderTraverse(traverseFun,current->next);
        traverseFun(current->element);
       } 
    }

    template<typename Data>
    inline void List<Data>::Map(MapFun mapFun){
        PreOrderMap(mapFun,head);
    }

    template<typename Data>
    inline void List<Data>::PreOrderMap(MapFun mapFun){
        PreOrderMap(mapFun,head);
    }

    template<typename Data>
    inline void List<Data>::PostOrderMap(MapFun mapFun){
        PostOrderMap(mapFun,head);
    }


    template<typename Data>
    void List<Data>::PreOrderMap(MapFun mapFun,Node* currentNode){
        for(;currentNode!=nullptr;currentNode=currentNode->next){
            mapFun(currentNode->element);
        }
    }
    template<typename Data>
    void List<Data>::PostOrderMap(MapFun mapFun, Node* currentNode){
        if(currentNode!=nullptr){
            PostOrderMap(mapFun,currentNode->next);
            mapFun(currentNode->element);
        }
    }

 }

