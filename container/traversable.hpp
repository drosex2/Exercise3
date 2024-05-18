
#ifndef TRAVERSABLE_HPP
#define TRAVERSABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class TraversableContainer: virtual public TestableContainer<Data> {
  // Must extend TestableContainer<Data>

private:

  // ...

protected:

  
public:

  
  ~TraversableContainer()=default; //default destructor

  /* ************************************************************************ */

  // Copy assignment
  virtual TraversableContainer& operator=(const TraversableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual TraversableContainer& operator=(TraversableContainer&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
   virtual bool operator==(const TraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.
   virtual bool operator!=(const TraversableContainer<Data>&) const noexcept=delete;// Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function

    using TraverseFun= std::function<void(const Data &)>;

    virtual void Traverse(TraverseFun) const=0;

    template <typename Accumulator>
    using FoldFun = std::function<Accumulator(const Data&,const Accumulator &)>;
    
    
    template <typename Accumulator>
    Accumulator Fold(FoldFun<Accumulator>,const Accumulator&) const;


  
  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

    inline bool Exists(const Data&)  const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~PreOrderTraversableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PreOrderTraversableContainer& operator=(const PreOrderTraversableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual PreOrderTraversableContainer& operator=(PreOrderTraversableContainer&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PreOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.
  virtual bool operator!=(const PreOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function
  
  using typename TraversableContainer<Data>::TraverseFun;

  virtual void PreOrderTraverse(TraverseFun) const=0;

  template <typename Accumulator>
  using FoldFun=typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
   Accumulator PreOrderFold(FoldFun<Accumulator>,const Accumulator&) const;

  

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~PostOrderTraversableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PostOrderTraversableContainer& operator=(const PostOrderTraversableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual PostOrderTraversableContainer& operator=(PostOrderTraversableContainer&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const PostOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.
  virtual bool operator!=(const PostOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function
   using typename TraversableContainer<Data>::TraverseFun;

  virtual void PostOrderTraverse(TraverseFun) const=0;

  template <typename Accumulator>
   using FoldFun= typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator PostOrderFold(FoldFun<Accumulator>,const Accumulator&) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~InOrderTraversableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual InOrderTraversableContainer& operator=(const InOrderTraversableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual InOrderTraversableContainer& operator=(InOrderTraversableContainer&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const InOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.
  virtual bool operator!=(const InOrderTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function
   using typename TraversableContainer<Data>::TraverseFun;

  virtual void InOrderTraverse(TraverseFun) const=0;

  template <typename Accumulator>
   using FoldFun=typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
  Accumulator InOrderFold(FoldFun<Accumulator>,const Accumulator&) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthTraversableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~BreadthTraversableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BreadthTraversableContainer& operator=(const BreadthTraversableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual BreadthTraversableContainer& operator=(BreadthTraversableContainer&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const BreadthTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.
  virtual bool operator!=(const BreadthTraversableContainer<Data>&) const noexcept=delete; // Comparison of abstract types might be possible.

  /* ************************************************************************ */

  // Specific member function
  using typename TraversableContainer<Data>::TraverseFun;

  virtual void BreadthTraverse(TraverseFun) const=0;

  template <typename Accumulator>
   using FoldFun=typename TraversableContainer<Data>::FoldFun<Accumulator>;

  template <typename Accumulator>
   inline Accumulator BreadthFold(FoldFun<Accumulator>,const Accumulator&) const;

  /* ************************************************************************ */

  // Specific member function (inherited from TraversableContainer)

  inline void Traverse(TraverseFun) const override; // Override TraversableContainer member

};

/* ************************************************************************** */

}

#include "traversable.cpp"

#endif
