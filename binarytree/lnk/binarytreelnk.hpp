
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk :virtual public MutableBinaryTree<Data> {
  // Must extend MutableBinaryTree<Data>

private:

  // ...
public:
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;
protected:
  using Container::size;
 

  // ...

  struct NodeLnk : virtual public MutableBinaryTree<Data>::MutableNode{ // Must extend MutableNode

  private:

    // ...

  protected:

    friend class BinaryTreeLnk<Data>;
    

    

  public:
    Data element;
    NodeLnk* left=nullptr;
    NodeLnk* right=nullptr;


    NodeLnk()=default;

    ~NodeLnk();

    NodeLnk(const Data& data) : element(data){};
    
    NodeLnk(Data&&) noexcept;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    virtual const NodeLnk& LeftChild() const override;
    virtual const NodeLnk& RightChild() const override;

    virtual NodeLnk& LeftChild() override;
    virtual NodeLnk& RightChild() override;
    // ...

  };

  NodeLnk * root=nullptr;
public:

  // Default constructor
  BinaryTreeLnk()=default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const TraversableContainer<Data>&) ; // A binary tree obtained from a TraversableContainer
  BinaryTreeLnk(MappableContainer<Data>&&); // A binary tree obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk &);

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&);

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeLnk&) const noexcept;
  bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  virtual const NodeLnk & Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  virtual NodeLnk & Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

protected:
  NodeLnk* RecursiveBuild(const NodeLnk*);  

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
