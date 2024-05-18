
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include "../iterator/iterator.hpp"

//#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"
//#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public PreOrderTraversableContainer<Data>,
                   virtual public PostOrderTraversableContainer<Data>,
                   virtual public InOrderTraversableContainer<Data>,
                   virtual public BreadthTraversableContainer<Data> {
  // Must extend PreOrderTraversableContainer<Data>,
  //             PostOrderTraversableContainer<Data>,
  //             InOrderTraversableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...
  using Container::size;
public:
  using Container::Size;
  using Container::Empty;

  struct Node {
  
    protected:

      // Comparison operators
      bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but is not visible.
      bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but is not visible.

    public:

      friend class BinaryTree<Data>;

      /* ********************************************************************** */

      // Destructor
      virtual ~Node()=default;

      /* ********************************************************************** */

      // Copy assignment
      Node& operator=(const Node&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      Node& operator=(Node&&)=delete; // Move assignment of abstract types is not possible.

      /* ********************************************************************** */

      // Specific member functions

      virtual const Data& Element() const noexcept=0; // Immutable access to the element (concrete function should not throw exceptions)

      virtual bool IsLeaf() const noexcept; // (concrete function should not throw exceptions)
      virtual bool HasLeftChild() const noexcept=0; // (concrete function should not throw exceptions)
      virtual bool HasRightChild() const noexcept=0; // (concrete function should not throw exceptions)

      virtual const Node& LeftChild() const=0; // (concrete function must throw std::out_of_range when not existent)
      virtual const Node& RightChild() const=0; // (concrete function must throw std::out_of_range when not existent)

    };

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTree()=default;

  /* ************************************************************************ */

  // Copy assignment
  BinaryTree<Data>& operator=(const BinaryTree<Data>&)=delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  BinaryTree<Data>& operator=(BinaryTree<Data>&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTree<Data>&) const noexcept; // Comparison of abstract binary tree is possible.
  bool operator!=(const BinaryTree<Data>&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Node& Root() const=0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;

  inline void Traverse(TraverseFun) const override; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)

  inline void PreOrderTraverse(TraverseFun) const override; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)

  inline void PostOrderTraverse(TraverseFun) const override; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderTraversableContainer)

  inline void InOrderTraverse(TraverseFun) const override; // Override InOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)

  inline void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member

protected:

  // Auxiliary functions, if necessary!
  

  void PreOrderTraverse(TraverseFun,const Node&) const;
  void InOrderTraverse(TraverseFun,const Node&) const;
  void PostOrderTraverse(TraverseFun,const Node&) const;
  void BreadthTraverse(TraverseFun,const Node*) const;

};

/* ************************************************************************** */

template <typename Data>
class MutableBinaryTree: virtual public ClearableContainer,
                         virtual public BinaryTree<Data>,
                         virtual public PreOrderMappableContainer<Data>,
                         virtual public PostOrderMappableContainer<Data>,
                         virtual public InOrderMappableContainer<Data>,
                         virtual public BreadthMappableContainer<Data> {
  // Must extend ClearableContainer,
  //             BinaryTree<Data>,
  //             PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>,
  //             InOrderMappableContainer<Data>,
  //             BreadthMappableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  struct MutableNode: virtual public BinaryTree<Data>::Node {
    // Must extend Node

    friend class MutableBinaryTree<Data>;

    /* ********************************************************************** */

    // Destructor
    virtual ~MutableNode()=default;

    /* ********************************************************************** */

    // Copy assignment
    MutableNode& operator=(const MutableNode&)=delete; // Copy assignment of abstract types is not possible.

    // Move assignment
    MutableNode& operator=(MutableNode&&)=delete; // Move assignment of abstract types is not possible.

    /* ********************************************************************** */

    // Specific member functions

    virtual Data& Element()=0; // Mutable access to the element (concrete function should not throw exceptions)

    virtual MutableNode& LeftChild()=0; // (concrete function must throw std::out_of_range when not existent)
    virtual MutableNode& RightChild()=0; // (concrete function must throw std::out_of_range when not existent)

  };

  /* ************************************************************************ */

  // Destructor
  virtual ~MutableBinaryTree()=default;

  /* ************************************************************************ */

  // Copy assignment
  MutableBinaryTree<Data>& operator=(const MutableBinaryTree<Data>&)=delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  MutableBinaryTree<Data>& operator=(MutableBinaryTree<Data>&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual MutableNode& Root()=0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  virtual void  Map(MapFun) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  virtual void PreOrderMap(MapFun) override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  virtual void PostOrderMap(MapFun) override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from InOrderMappableContainer)

  virtual void InOrderMap(MapFun) override; // Override InOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)

  virtual void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!
  
 

  void PreOrderMap(MapFun, MutableNode& node);
  void InOrderMap(MapFun, MutableNode& node);
  void PostOrderMap(MapFun, MutableNode& node);
  void BreadthMap(MapFun, MutableNode* node);

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data>{
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  //const typename BinaryTree<Data>::Node* current=nullptr;
  StackLst<const typename BinaryTree<Data>:: Node*> stack;

public:

  // Specific constructors
  BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderIterator(const BTPreOrderIterator<Data>&);

  // Move constructor
  BTPreOrderIterator(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPreOrderIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderIterator<Data>& operator=(const BTPreOrderIterator<Data>&);

  // Move assignment
  BTPreOrderIterator<Data>& operator=(BTPreOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderIterator<Data>&)const noexcept;
  bool operator!=(const BTPreOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual const Data& operator*() const override; // (throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  virtual BTPreOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderMutableIterator: virtual public MutableIterator<Data>,
                                 virtual public BTPreOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPreOrderIterator<Data>

private:

  // ...

protected:
  using BTPreOrderIterator<Data>::stack;
  using BTPreOrderIterator<Data>::root;
  

public:

  // Specific constructors
  BTPreOrderMutableIterator(MutableBinaryTree<Data>&); // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPreOrderMutableIterator(const BTPreOrderMutableIterator<Data>&);

  // Move constructor
  BTPreOrderMutableIterator(BTPreOrderMutableIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPreOrderMutableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTPreOrderMutableIterator& operator=(const BTPreOrderMutableIterator<Data>&);

  // Move assignment
  BTPreOrderMutableIterator& operator=(BTPreOrderMutableIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPreOrderMutableIterator<Data>&) const noexcept;
  bool operator!=(const BTPreOrderMutableIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  virtual Data& operator*() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data>,
                           virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  StackLst<const typename BinaryTree<Data>::Node*> stack;
  virtual void LeftMostLeaf(const typename BinaryTree<Data>::Node *);

public:

  // Specific constructors
  BTPostOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderIterator(const BTPostOrderIterator<Data>&);

  // Move constructor
  BTPostOrderIterator(BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderIterator<Data>& operator=(const BTPostOrderIterator<Data>&);

  // Move assignment
  BTPostOrderIterator<Data>& operator=(BTPostOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderIterator<Data>&) const noexcept;
  bool operator!=(const BTPostOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual const Data& operator*() const override; // (throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  virtual BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderMutableIterator: virtual public MutableIterator<Data>,
                                  virtual public BTPostOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTPostOrderIterator<Data>

private:

  // ...

protected:

  // ...
  using BTPostOrderIterator<Data>::stack;
  using BTPostOrderIterator<Data>::root;
public:

  // Specific constructors
  BTPostOrderMutableIterator(MutableBinaryTree<Data>&); // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTPostOrderMutableIterator(const BTPostOrderMutableIterator<Data>&);

  // Move constructor
  BTPostOrderMutableIterator(BTPostOrderMutableIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTPostOrderMutableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTPostOrderMutableIterator<Data>& operator=(const BTPostOrderMutableIterator<Data>& iterator){
    BTPostOrderIterator<Data>::operator=(iterator);
    return *this;
  };

  // Move assignment
  BTPostOrderMutableIterator<Data>& operator=(BTPostOrderMutableIterator<Data>&& iterator) noexcept{
    BTPostOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTPostOrderMutableIterator<Data>&) const noexcept;
  bool operator!=(const BTPostOrderMutableIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  virtual Data& operator*() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data>,
                         virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  StackLst<const typename BinaryTree<Data>::Node*> stack;
  virtual void PushLeftNodes(const typename BinaryTree<Data>::Node *);
public:

  // Specific constructors
  BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderIterator(const BTInOrderIterator<Data>&);

  // Move constructor
  BTInOrderIterator(BTInOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTInOrderIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderIterator<Data>& operator=(const BTInOrderIterator<Data>&);

  // Move assignment
  BTInOrderIterator<Data>& operator=(BTInOrderIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderIterator<Data>&) const noexcept;
  bool operator!=(const BTInOrderIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual const Data& operator*() const override; // (throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  virtual BTInOrderIterator<Data>& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderMutableIterator: virtual public MutableIterator<Data>,
                                virtual public BTInOrderIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTInOrderIterator<Data>

private:

  // ...

protected:

  // ...
  using BTInOrderIterator<Data>::stack;
  using BTInOrderIterator<Data>::root;
public:

  // Specific constructors
  BTInOrderMutableIterator(MutableBinaryTree<Data>&); // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTInOrderMutableIterator(const BTInOrderMutableIterator<Data>&);

  // Move constructor
  BTInOrderMutableIterator(BTInOrderMutableIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTInOrderMutableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTInOrderMutableIterator<Data> operator=(const BTInOrderMutableIterator<Data>& iterator){
    BTInOrderIterator<Data>::operator=(iterator);
    return *this;
  };

  // Move assignment
  BTInOrderMutableIterator<Data> operator=(BTInOrderMutableIterator<Data>&& iterator) noexcept{
    BTInOrderIterator<Data>::operator=(std::move(iterator));
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTInOrderMutableIterator<Data>&) const noexcept;
  bool operator!=(const BTInOrderMutableIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  virtual Data& operator*() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>,
                          virtual public ResettableIterator<Data> {
  // Must extend ForwardIterator<Data>,
  //             ResettableIterator<Data>

private:

  // ...

protected:

  const typename BinaryTree<Data>::Node* root=nullptr;
  QueueLst<const typename BinaryTree<Data>::Node*> queue;  

public:

  // Specific constructors
  BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthIterator(const BTBreadthIterator<Data>&);

  // Move constructor
  BTBreadthIterator(BTBreadthIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTBreadthIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  BTBreadthIterator& operator=(const BTBreadthIterator<Data>&);

  // Move assignment
  BTBreadthIterator& operator=(BTBreadthIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthIterator<Data>&) const noexcept;
  bool operator!=(const BTBreadthIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  virtual const Data& operator*() const override; // (throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  virtual BTBreadthIterator& operator++() override; // (throw std::out_of_range when terminated)

  /* ************************************************************************ */

  // Specific member functions (inherited from ResettableIterator)

  virtual void Reset() noexcept override; // (should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthMutableIterator : virtual public MutableIterator<Data>,
                                 virtual public BTBreadthIterator<Data> {
  // Must extend MutableIterator<Data>,
  //             BTBreadthIterator<Data>

private:

  // ...

protected:

  // ...
  using BTBreadthIterator<Data>::queue;
  using BTBreadthIterator<Data>::root;
public:

  // Specific constructors
  BTBreadthMutableIterator(MutableBinaryTree<Data>&); // An iterator over a given mutable binary tree

  /* ************************************************************************ */

  // Copy constructor
  BTBreadthMutableIterator(const BTBreadthMutableIterator<Data>&);

  // Move constructor
  BTBreadthMutableIterator(BTBreadthMutableIterator<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BTBreadthMutableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BTBreadthMutableIterator<Data> operator=(const BTBreadthMutableIterator<Data>& iterator){
    BTBreadthIterator<Data>::operator=(iterator);
    return *this;
  };

  // Move assignment
  virtual BTBreadthMutableIterator<Data> operator=(BTBreadthMutableIterator<Data>&& iterator) noexcept{
    BTBreadthIterator<Data>::operator=(std::move(iterator));
    return *this;
  };

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BTBreadthMutableIterator<Data>&) const noexcept;
  bool operator!=(const BTBreadthMutableIterator<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableIterator)

  virtual Data& operator*() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
