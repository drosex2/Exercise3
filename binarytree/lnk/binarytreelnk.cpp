
namespace lasd {

/* ************************************************************************** */

// NODELNK

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& data) noexcept{
        std::swap(element,data);
    } 

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk::~NodeLnk(){
        if(left!=nullptr){
            delete this->left;
        }
        if(right!=nullptr){
            delete this->right;
        }
        
    }

    template <typename Data>
    Data& BinaryTreeLnk<Data>::NodeLnk::Element()noexcept{
        return element;
    }

    template <typename Data>
    const Data& BinaryTreeLnk<Data>::NodeLnk::Element()const noexcept{
        return element;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild()const noexcept{
        return left!=nullptr;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild()const noexcept{
        return right!=nullptr;
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
        if(this->HasLeftChild()){
            return *left;
        }else
        {
            throw std::out_of_range("Left child pointer is nullptr");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild(){
        if(this->HasLeftChild()){
            return *left;
        }else
        {
            throw std::out_of_range("Left child pointer is nullptr");
        }
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const {
        if(this->HasRightChild()){
            return *right;
        }else
        {
            throw std::out_of_range("Right child pointer is nullptr");
        }
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild(){
        if(this->HasRightChild()){
            return *right;
        }else
        {
            throw std::out_of_range("Right child pointer is nullptr");
        }
    }

    //BINARY TREE LNK
    //costruttori da traversable e mappable: costruzione per livelli (ampiezza)
    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const TraversableContainer<Data>& traversableCon) {
        size=traversableCon.size;
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        traversableCon.Traverse(
            [&que](const Data& data){
                NodeLnk *& cur=*que.HeadNDequeue();
                cur=new NodeLnk(data);
                que.Enqueue(&cur->left);
                que.Enqueue(&cur->right);
            }
        );
    }

    //from mappableContainer
    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(MappableContainer<Data>&& mappableCon) {
        size=mappableCon.size;
        QueueLst<NodeLnk**> que;
        que.Enqueue(&root);
        mappableCon.Map(
            [&que]( Data& data){
                NodeLnk *& cur=*que.HeadNDequeue();
                cur=new NodeLnk(std::move(data));
                que.Enqueue(&cur->left);
                que.Enqueue(&cur->right);
            }
        );
        
    }

    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& copTree){
        if(!copTree.Empty()){
            size=0;
            root=RecursiveBuild(&copTree.Root());
        }
        
                     
        
    }

    template<typename Data>
    BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::RecursiveBuild(const NodeLnk* root){

        NodeLnk* tmp=new NodeLnk();
        if(root!=nullptr){
            tmp->element= root->Element();
            size++;
            if(root->HasLeftChild()){
                tmp->left= RecursiveBuild(&root->LeftChild());
            }
            if(root->HasRightChild()){
                tmp->right=RecursiveBuild(&root->RightChild());
            }
        }
        
        return tmp;
    }

    template<typename Data>
    BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& moveTree) noexcept{
        std::swap(root,moveTree.root);
        std::swap(size,moveTree.size);
    }

    template<typename Data>
    BinaryTreeLnk<Data>::~BinaryTreeLnk(){
        if(root!=nullptr)
        {
            delete root;
        }
        
        root=nullptr;
        size=0;
    }

    template<typename Data>
    BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& copTree){

        Clear();
        if(!copTree.Empty()){
            size=0;
            root=RecursiveBuild(&copTree.Root());
            
        }
        return *this;
    }

    template <typename Data>
    BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& moveTree) noexcept{
        std::swap(root,moveTree.root);
        std::swap(size,moveTree.size);
        
        return *this;
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& cmpTree)const noexcept{
        return BinaryTree<Data>::operator==(cmpTree);
        
    }

    template <typename Data>
    bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& cmpTree)const noexcept{
        return !(*this==cmpTree);
    }

    template <typename Data>
    const BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root() const {
        if (root == nullptr){
            throw std::out_of_range("L'albero è vuoto!");
        }
        else{
            return *root;
        }    
    }

    template <typename Data>
    BinaryTreeLnk<Data>::NodeLnk & BinaryTreeLnk<Data>::Root() {
        if (root == nullptr){
            throw std::out_of_range("L'albero è vuoto!");
        }
        else{
            return *root;
        }   
    }

    template <typename Data>
    void BinaryTreeLnk<Data>::Clear(){
        if(size!=0){
            delete root;
            root=nullptr;
            size=0;
        }
    }
/* ************************************************************************** */

}
