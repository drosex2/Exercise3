
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>, virtual protected Vector<Data> {
  // Must extend Stack<Data>,
  //             Vector<Data>

private:

  // ...

protected:
  unsigned long index=0;
  using Vector<Data>::size;
  using Vector<Data>::Elements;

  

public:

  // Default constructor
  StackVec();//=default;

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const TraversableContainer<Data>&); // A stack obtained from a TraversableContainer
  StackVec(MappableContainer<Data>&&); // A stack obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec<Data>&);

  // Move constructor
  StackVec(StackVec<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~StackVec()=default;

  /* ************************************************************************ */

  // Copy assignment
  const StackVec<Data>& operator=(const StackVec<Data>&);

  // Move assignment
  const StackVec<Data>& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const StackVec<Data>&) const noexcept;
  bool operator!=(const StackVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  const Data& Top() const override  ; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  Data& Top() override ; // Override Stack member (non-mutable version; must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)
  void Push(const Data&) override; // Override Stack member (copy of the value)
  void Push(Data&&) override; // Override Stack member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override ; //override Override Container member

  unsigned long Size() const noexcept override ; //override Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override ; // Override ClearableContainer member

protected:

  void Expand();
  void Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
