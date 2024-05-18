
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~Iterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual Iterator& operator=(const Iterator&)=delete; // Copy assignment of abstract is not possible.

  // Move assignment
  virtual Iterator& operator=(Iterator&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Iterator&)const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const Iterator&)const noexcept=delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual const Data& operator*() const=0; // (non-mutable version; concrete function must throw std::out_of_range when terminated)

  virtual bool Terminated() const noexcept=0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class MutableIterator: virtual public Iterator<Data> {
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~MutableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual MutableIterator& operator=(const MutableIterator&)=delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual MutableIterator& operator=(MutableIterator&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const MutableIterator&)const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const MutableIterator&)const noexcept=delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual Data& operator*()=0; // (mutable version; concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data> {
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ForwardIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual ForwardIterator& operator=(const ForwardIterator&)=delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual ForwardIterator& operator=(ForwardIterator&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const ForwardIterator&)const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ForwardIterator&)const noexcept=delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual ForwardIterator& operator++()=0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class ResettableIterator : virtual public Iterator<Data> {
  // Must extend Iterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Destructor
  ~ResettableIterator()=default;

  /* ************************************************************************ */

  // Copy assignment
  virtual ResettableIterator& operator=(const ResettableIterator&)=delete; // Copy assignment of abstract types is not possible.

  // Move assignment
  virtual ResettableIterator& operator=(ResettableIterator&&)=delete; // Move assignment of abstract types is not possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const ResettableIterator&)const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(ResettableIterator&&)const noexcept=delete; // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Reset() noexcept=0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

}

#endif
