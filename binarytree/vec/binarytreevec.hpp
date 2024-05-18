
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec : virtual public MutableBinaryTree<Data>{
                      // virtual protected Vector<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...

protected:

 

  struct NodeVec : virtual MutableBinaryTree<Data>::MutableNode { // Must extend MutableNode

  private:

    // ...

  protected:

    // ...

  public:
    Data element;
    
    unsigned long index;
    Vector<NodeVec*> *tree;
    
    NodeVec()=default;

    ~NodeVec()=default;

    NodeVec(const Data& data);
    
    NodeVec(Data&&) noexcept;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual const NodeVec& LeftChild() const override;
    virtual const NodeVec& RightChild() const override;

    virtual NodeVec& LeftChild() override;
    virtual NodeVec& RightChild() override;

  };
  Vector<NodeVec*> vector;
public:
  using Container::size;
  // using typename BinaryTree<Data>::Node;
  // using typename MutableBinaryTree<Data>::MutableNode;

  // Default constructor
  BinaryTreeVec()=default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const TraversableContainer<Data>&); // A binary tree obtained from a TraversableContainer
  BinaryTreeVec(MappableContainer<Data>&&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec<Data>&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec<Data>& operator=(const BinaryTreeVec<Data>&);

  // Move assignment
  BinaryTreeVec<Data>& operator=(BinaryTreeVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec<Data>&)const noexcept;
  bool operator!=(const BinaryTreeVec<Data>&)const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual const NodeVec & Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  virtual NodeVec & Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthTraversableContainer)
  //using typename TraversableContainer<Data>::TraverseFun;
  using TraverseFun= std::function<void(const Data &)>;
  virtual void BreadthTraverse(TraverseFun) const override; // Override BreadthTraversableContainer member //implementabile con un semplice ciclo

  /* ************************************************************************ */

  // Specific member function (inherited from BreadthMappableContainer)
  //using typename MappableContainer<Data>::MapFun;
  using MapFun = std::function<void(Data &)>;
  virtual void BreadthMap(MapFun) override; // Override BreadthMappableContainer member

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
