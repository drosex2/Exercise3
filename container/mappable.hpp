
#ifndef MAPPABLE_HPP
#define MAPPABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "traversable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public TraversableContainer<Data> {
  // Must extend TraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~MappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual MappableContainer& operator=(const MappableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual MappableContainer& operator=(MappableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const MappableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const MappableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.


  /* ************************************************************************ */

  // Specific member function

   using MapFun = std::function<void(Data &)>;

  virtual void Map(MapFun)=0;

};

/* ************************************************************************** */

template <typename Data>
class PreOrderMappableContainer: virtual public MappableContainer<Data>,virtual public PreOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             PreOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~PreOrderMappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PreOrderMappableContainer& operator=(const PreOrderMappableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual PreOrderMappableContainer& operator=(PreOrderMappableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const PreOrderMappableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const PreOrderMappableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PreOrderMap(MapFun)=0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun) ; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderMappableContainer: virtual public MappableContainer<Data>,virtual public PostOrderTraversableContainer<Data> {
  // Must extend MappableContainer<Data>,
  //             PostOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~PostOrderMappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual PostOrderMappableContainer& operator=(const PostOrderMappableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual PostOrderMappableContainer& operator=(PostOrderMappableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const PostOrderMappableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const PostOrderMappableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void PostOrderMap(MapFun)=0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun) ; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer: virtual public MappableContainer<Data>,virtual public InOrderTraversableContainer<Data>{
  // Must extend MappableContainer<Data>,
  //             InOrderTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~InOrderMappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual InOrderMappableContainer& operator=(const InOrderMappableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual InOrderMappableContainer& operator=(InOrderMappableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const InOrderMappableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const InOrderMappableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void InOrderMap(MapFun)=0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun) ; // Override MappableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer: virtual public MappableContainer<Data>,virtual public BreadthTraversableContainer<Data> {
  // Must extend MappableContainer<Data>,
  //             BreadthTraversableContainer<Data>

private:

  // ...

protected:

  // ...

public:

  
  ~BreadthMappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BreadthMappableContainer& operator=(const BreadthMappableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual BreadthMappableContainer& operator=(BreadthMappableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const BreadthMappableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const BreadthMappableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member function

  using typename MappableContainer<Data>::MapFun;

  virtual void BreadthMap(MapFun)=0;

  /* ************************************************************************ */

  // Specific member function (inherited from MappableContainer)

  void Map(MapFun) ; // Override MappableContainer member

};

/* ************************************************************************** */

}

#include "mappable.cpp"

#endif
