
#ifndef LINEAR_HPP
#define LINEAR_HPP

/* ************************************************************************** */

#include "mappable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public PreOrderMappableContainer<Data>,virtual public PostOrderMappableContainer<Data> {
  // Must extend PreOrderMappableContainer<Data>,
  //             PostOrderMappableContainer<Data>

private:

  // ...

protected:

  using Container::size;

public:

  
  ~LinearContainer()=default;

  /* ************************************************************************ */

  // Copy assignment (not possible at this level of abstraction)
  virtual LinearContainer& operator=(const LinearContainer &)=delete; 

  // Move assignment (not possible at this level of abstraction)
  virtual LinearContainer& operator=(LinearContainer &&) noexcept =delete; 

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const LinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.
   bool operator!=(const LinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator[](unsigned long) const=0; // (non-mutable version; concrete function must throw std::out_of_range when out of range)
  virtual Data& operator[](unsigned long)=0; // (mutable version; concrete function must throw std::out_of_range when out of range)

  inline virtual const Data& Front() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data& Front(); // (mutable version; concrete function must throw std::length_error when empty)

  inline virtual const Data& Back() const; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data& Back(); // (mutable version; concrete function must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  using typename TraversableContainer<Data>::TraverseFun;
  
  void Traverse(TraverseFun) const  ; // Override TraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderTraversableContainer)
  //using void PreOrderTraversableContainer<Data>::TraverseFun;
  void PreOrderTraverse(TraverseFun) const  ; // Override PreOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderTraversableContainer)
  //using typename PostOrderTraversableContainer<Data>::TraverseFun;
  void PostOrderTraverse(TraverseFun) const  ; // Override PostOrderTraversableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFun;

  void Map(MapFun) ; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)
  //using typename PreOrderMappableContainer<Data>::MapFun;
  void PreOrderMap(MapFun)  ; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)
  //using typename PostOrderMappableContainer<Data>::MapFun;
  void PostOrderMap(MapFun)  ; // Override PostOrderMappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class SortableLinearContainer: virtual public LinearContainer<Data> {
  // Must extend LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;
  using LinearContainer<Data>::operator[];

public:

  
  ~SortableLinearContainer()=default;

  /* ************************************************************************ */

  // Copy assignment (not possible at this level of abstraction)
  virtual SortableLinearContainer& operator=(const SortableLinearContainer &)=delete; 

  // Move assignment (not possible at this level of abstraction)
  virtual SortableLinearContainer& operator=(SortableLinearContainer &&) noexcept =delete; 

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const SortableLinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.
  bool operator!=(const SortableLinearContainer<Data>&) const noexcept; // Comparison of abstract types is possible.

  /* ************************************************************************ */

  // Specific member function

  virtual void Sort() noexcept;

protected:

  // Auxiliary member functions

  inline void QuickSort(unsigned long p, unsigned long r) noexcept;
  unsigned long Partition(unsigned long p, unsigned long r) noexcept;

};

/* ************************************************************************** */

}

#include "linear.cpp"

#endif
