
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST:  virtual public DictionaryContainer<Data>,
            virtual public BinaryTree<Data>,
            virtual protected BinaryTreeLnk<Data>{
  // Must extend ClearableContainer,
  //             DictionaryContainer<Data>,
  //             BinaryTree<Data>,
  //             BinaryTreeLnk<Data>

private:

  // ...

protected:

  using typename BinaryTreeLnk<Data>::NodeLnk;
  using BinaryTreeLnk<Data>::size;
  using BinaryTreeLnk<Data>::root;
  

  // ...

public:

  // Default constructor
  BST();

  /* ************************************************************************ */

  // Specific constructors
  BST(const TraversableContainer<Data>&); // A bst obtained from a TraversableContainer
  BST(MappableContainer<Data>&&); // A bst obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BST(const BST<Data>&);

  // Move constructor
  BST(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BST()=default;

  /* ************************************************************************ */

  // Copy assignment
  BST<Data>& operator=(const BST<Data>&);

  // Move assignment
  BST<Data>& operator=(BST<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BST<Data>&) const noexcept;
  bool operator!=(const BST<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& Min() const; // (concrete function must throw std::length_error when empty)
  virtual Data MinNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMin(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Max() const; // (concrete function must throw std::length_error when empty)
  virtual Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
  virtual void RemoveMax(); // (concrete function must throw std::length_error when empty)

  virtual const Data& Predecessor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data PredecessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemovePredecessor(const Data&); // (concrete function must throw std::length_error when not found)

  virtual const Data& Successor(const Data&) const; // (concrete function must throw std::length_error when not found)
  virtual Data SuccessorNRemove(const Data&); // (concrete function must throw std::length_error when not found)
  virtual void RemoveSuccessor(const Data&); // (concrete function must throw std::length_error when not found)

  /* ************************************************************************ */

  // Specific member function (inherited from BinaryTree)

  virtual const typename BinaryTreeLnk<Data>::NodeLnk& Root() const override; // Override BinaryTree member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  //Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using BinaryTreeLnk<Data>::Clear; // Override ClearableContainer member
  
protected:
  
  // Auxiliary functions, if necessary!

  virtual Data DataNDelete(NodeLnk *);

  virtual NodeLnk* Detach(NodeLnk *&) noexcept;

  virtual NodeLnk* DetachMin(NodeLnk *&) noexcept;
  virtual NodeLnk* DetachMax(NodeLnk *&) noexcept;

  virtual NodeLnk* Skip2Left(NodeLnk *&) noexcept;
  virtual NodeLnk* Skip2Right(NodeLnk *&) noexcept;

  virtual NodeLnk*& FindPointerToMin(NodeLnk*&) noexcept;
  virtual const NodeLnk* const & FindPointerToMin(const NodeLnk* const &) const noexcept; // Both mutable & unmutable versions

  virtual NodeLnk*& FindPointerToMax(NodeLnk*&) noexcept;
  virtual const NodeLnk* const & FindPointerToMax(const NodeLnk* const &) const noexcept; // Both mutable & unmutable versions

  virtual NodeLnk*& FindPointerTo(NodeLnk*&,const Data&) noexcept; // Both mutable & unmutable versions
  virtual const NodeLnk* const & FindPointerTo(const NodeLnk* const&, const Data&) const noexcept;

  virtual NodeLnk*& FindPointerToPredecessor(NodeLnk*&, const Data&) noexcept;
  virtual const NodeLnk* const & FindPointerToPredecessor(const NodeLnk* const &, const Data&) const noexcept; // Both mutable & unmutable versions
  
  virtual NodeLnk*& FindPointerToSuccessor(NodeLnk*&, const Data&) noexcept;
  virtual const NodeLnk* const & FindPointerToSuccessor(const NodeLnk* const &, const Data&) const noexcept; // Both mutable & unmutable versions

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
