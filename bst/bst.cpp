
namespace lasd
{
    
    /* ************************************************************************** */
    //default constructor
    template <typename Data>
    BST<Data>::BST(){
        root=nullptr;
        size=0;
    }    

    // constructor from traversable container
    template <typename Data>
    BST<Data>::BST(const TraversableContainer<Data> &traversableCon)
    {     
        traversableCon.Traverse(
            [this](const Data &data)
            {
                Insert(data);
            });
    }

    // from mappableContainer
    template <typename Data>
    BST<Data>::BST(MappableContainer<Data> &&mappableCon)
    {
        mappableCon.Map(
            [this](Data &data)
            {
                Insert(std::move(data));
            });
    }

    template <typename Data>
    BST<Data>::BST(const BST<Data> &BST) : BinaryTreeLnk<Data>::BinaryTreeLnk(BST) {}

    template <typename Data>
    BST<Data>::BST(BST<Data> &&BST) noexcept : BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(BST)) {}

    template <typename Data>
    BST<Data> &BST<Data>::operator=(const BST<Data> &BST)
    {
        BinaryTreeLnk<Data>::operator=(BST);
        return *this;
    }
    template <typename Data>
    BST<Data> &BST<Data>::operator=(BST<Data> &&BST) noexcept
    {
        BinaryTreeLnk<Data>::operator=(std::move(BST));
        return *this;
    }

    template <typename Data>
    bool BST<Data>::operator==(const BST<Data> &BST) const noexcept
    {
        if (size != BST.size)
        {
            return false;
        }
        else
        {
            BTInOrderIterator<Data> it1(*this);
            BTInOrderIterator<Data> it2(BST);
            bool val = true;
            while (!it1.Terminated() && val == true)
            {
                if (*it1 != *it2)
                {
                    val = false;
                }
                ++it1;
                ++it2;
            }
            return val;
        }
    }
    template <typename Data>
    bool BST<Data>::operator!=(const BST<Data> &BST) const noexcept
    {
        return !(*this == BST);
    }

    template <typename Data>
    const Data &BST<Data>::Min() const
    {
        if (root != nullptr)
        {
            return FindPointerToMin(root)->Element();
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }

    template <typename Data>
    Data BST<Data>::MinNRemove()
    {
        if (root != nullptr)
        {
            NodeLnk *nodeMin = DetachMin(root);
            Data min = nodeMin->Element();
            delete nodeMin;
            return min;
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }
    template <typename Data>
    void BST<Data>::RemoveMin()
    {
        if (root != nullptr)
        {
            NodeLnk *nodeMin = DetachMin(root);
            delete nodeMin;
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }

    template <typename Data>
    const Data &BST<Data>::Max() const
    {
        if (root != nullptr)
        {
            return FindPointerToMax(root)->Element();
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }

    template <typename Data>
    Data BST<Data>::MaxNRemove()
    {
        if (root != nullptr)
        {
            NodeLnk *nodeMax = DetachMax(root);
            Data max = nodeMax->Element();
            delete nodeMax;
            return max;
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }
    template <typename Data>
    void BST<Data>::RemoveMax()
    {
        if (root != nullptr)
        {
            NodeLnk *nodeMax = DetachMax(root);
            delete nodeMax;
        }
        else
        {
            throw std::length_error("The tree is empty!");
        }
    }

    template <typename Data>
    const Data &BST<Data>::Predecessor(const Data &value) const
    {
        if (root != nullptr)
        {
            const NodeLnk *pred = FindPointerToPredecessor(root, value);
            if (pred == nullptr)
            {
                throw std::length_error("There isn't a predecessor");
            }

            else
            {
                return pred->Element();
            }
        }
        else
        {
            throw std::length_error("The tree is empty.");
        }
    }

    template <typename Data>
    Data BST<Data>::PredecessorNRemove(const Data &value)
    {
        Data pred = Predecessor(value);
        Remove(pred);
        return pred;
    }

    template <typename Data>
    void BST<Data>::RemovePredecessor(const Data &value)
    {
        const Data &pred = Predecessor(value);
        Remove(pred);
    }

    template <typename Data>
    const Data &BST<Data>::Successor(const Data &value) const
    {
        if (root != nullptr)
        {
            const NodeLnk *succ = FindPointerToSuccessor(root, value);
            if (succ == nullptr)
            {
                throw std::length_error("There isn't a successor");
            }

            else
            {
                return succ->Element();
            }
        }
        else
        {
            throw std::length_error("The tree is empty.");
        }
    }

    template <typename Data>
    Data BST<Data>::SuccessorNRemove(const Data &value)
    {
        Data succ = Successor(value);
        Remove(succ);
        return succ;
    }

    template <typename Data>
    void BST<Data>::RemoveSuccessor(const Data &value)
    {
        const Data &succ = Successor(value);
        Remove(succ);
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::NodeLnk &BST<Data>::Root() const
    {
        if (root == nullptr)
        {
            throw std::out_of_range("L'albero è vuoto!");
        }
        else
        {
            return *root;
        }
    }

    template <typename Data>
    bool BST<Data>::Exists(const Data &value) const noexcept
    {
        return (FindPointerTo(root, value) != nullptr);
    }

    template <typename Data>
    bool BST<Data>::Insert(const Data &value)
    {
        NodeLnk *&ptr = FindPointerTo(root, value);
        if (ptr == nullptr)
        {
            ptr = new NodeLnk(value);
            size++;
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Insert(Data &&value)
    {
        NodeLnk *&ptr = FindPointerTo(root, value);
        if (ptr == nullptr)
        {
            ptr = new NodeLnk(std::move(value));
            size++;
            return true;
        }
        else
        {
            return false;
        }
    }

    template <typename Data>
    bool BST<Data>::Remove(const Data &value)
    {
        NodeLnk* nodeToRemove=Detach(FindPointerTo(root, value));
        if(nodeToRemove!=nullptr){
            delete nodeToRemove;
            return true;
        }
        else{
            return false;
        }
         
    }
    // auxiliary functions

    template <typename Data>
    Data BST<Data>::DataNDelete(NodeLnk *node)
    {
        Data val = node->Element();
        node->left = nullptr;
        node->right = nullptr;
        delete node;
        return val;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Detach( NodeLnk *& node) noexcept
    {
        if (node != nullptr)
        {
            if (node->left == nullptr)
            {
                return Skip2Right(node);
            }
            else if (node->right == nullptr)
            {
                return Skip2Left(node);
            }
            else
            {
                NodeLnk* min = DetachMin(node->right);
                std::swap(node->element, min->element);
                return min;
            }
        }
        return nullptr;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk *& node) noexcept
    {
        return Skip2Right(FindPointerToMin(node));
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk *& node) noexcept
    {
        return Skip2Left(FindPointerToMax(node));
    }
    

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk *&node) noexcept
    {
        NodeLnk *left = nullptr;
        if (node != nullptr)
        {
            std::swap(left, node->left);
            std::swap(left, node);
            size--;
        }
        return left;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *BST<Data>::Skip2Right(NodeLnk *&node) noexcept
    {
        NodeLnk *right = nullptr;
        if (node != nullptr)
        {
            std::swap(right, node->right);
            std::swap(right, node);
            size--;
        }
        return right;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *&BST<Data>::FindPointerToMin(NodeLnk *&node) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMin(node));
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk *const &BST<Data>::FindPointerToMin(const NodeLnk *const &node) const noexcept
    {
        const NodeLnk *const *ptr = &node;
        const NodeLnk *curr = node;
        if (curr != nullptr)
        {
            while (curr->left != nullptr)
            {
                ptr = &curr->left;
                curr = curr->left;
            }
        }
        return *ptr;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *&BST<Data>::FindPointerToMax(NodeLnk *&node) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(node));
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk *const &BST<Data>::FindPointerToMax(const NodeLnk *const &node) const noexcept
    {
        const NodeLnk *const *ptr = &node;
        const NodeLnk *curr = node;
        if (curr != nullptr)
        {
            while (curr->right != nullptr)
            {
                ptr = &curr->right;
                curr = curr->right;
            }
        }
        return *ptr;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *&BST<Data>::FindPointerTo(NodeLnk *&node, const Data &data) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerTo(node, data));
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk *const &BST<Data>::FindPointerTo(const NodeLnk *const &node, const Data &data) const noexcept
    {
        const NodeLnk *const *ptr = &node;
        const NodeLnk *curr = node;
        while (curr != nullptr)
        {
            if (curr->element < data)
            {
                ptr = &curr->right;
                curr = curr->right;
            }
            else if (curr->element > data)
            {
                ptr = &curr->left;
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        return *ptr;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *&BST<Data>::FindPointerToSuccessor(NodeLnk *&node, const Data &data) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(node, data));
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk *const &BST<Data>::FindPointerToSuccessor(const NodeLnk *const &node, const Data &data) const noexcept
    {
        const NodeLnk *const *successor = nullptr;
        const NodeLnk *const *curr = &node;
        while (*curr != nullptr){
            if (data >= (*curr)->element){
                curr = &((*curr)->right);
            }
            else{
                successor = curr;
                curr = &((*curr)->left);
            }
        }
        if (successor == nullptr){
            return *curr;
        }

        return *successor;
    }

    template <typename Data>
    typename BinaryTreeLnk<Data>::NodeLnk *&BST<Data>::FindPointerToPredecessor(NodeLnk *&node, const Data &data) noexcept
    {
        return const_cast<NodeLnk *&>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(node, data));
    }

    template <typename Data>
    const typename BinaryTreeLnk<Data>::NodeLnk *const &BST<Data>::FindPointerToPredecessor(const NodeLnk *const &node, const Data &data) const noexcept
    {
        const NodeLnk *const *predecessor = nullptr;
        const NodeLnk *const *curr = &node;
        while (*curr != nullptr){
            if (data > (*curr)->element){
                predecessor = curr;
                curr = &((*curr)->right);
            }
            else{
                curr = &((*curr)->left);
            }
        }
        if (predecessor == nullptr){
            return *curr;
        }
        else{
            return *predecessor;
        }
    }
}
