
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector : virtual public ResizableContainer,virtual public LinearContainer<Data> {
  // Must extend ResizableContainer,
  //             LinearContainer<Data>

private:

  // ...

protected:

  using Container::size;

  Data* Elements=nullptr;

public:

  // Default constructor
   Vector()=default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const unsigned long); // A vector with a given initial dimension
  Vector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  Vector(MappableContainer<Data>&&); // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector<Data>&);

  // Move constructor
  Vector(Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector<Data>&);

  // Move assignment
  Vector& operator=(Vector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector<Data>&) const noexcept;
  inline bool operator!=(const Vector<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  virtual void Resize(unsigned long) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  virtual const Data& operator[](unsigned long) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  virtual Data& operator[](unsigned long)  override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  virtual const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Front()  override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  virtual const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  virtual Data& Back()  override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

template <typename Data>
class SortableVector:  virtual public Vector<Data>,
  virtual public SortableLinearContainer<Data> {
  // Must extend Vector<Data>,
  //             SortableLinearContainer<Data>

private:

  // ...

protected:

  // using Container::???;

  // ...

public:

  // Default constructor
  SortableVector()=default;

  /* ************************************************************************ */

  // Specific constructors
  SortableVector(const unsigned long); // A vector with a given initial dimension
  SortableVector(const TraversableContainer<Data>&); // A vector obtained from a TraversableContainer
  SortableVector(MappableContainer<Data>&&) ; // A vector obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  SortableVector(const SortableVector<Data>&);

  // Move constructor
  SortableVector(SortableVector<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~SortableVector()=default;

  /* ************************************************************************ */

  // Copy assignment
  SortableVector<Data>& operator=(const SortableVector<Data>&);

  // Move assignment
  SortableVector<Data>& operator=(SortableVector<Data>&&);

  virtual const Data& operator[](unsigned long) const override;
  virtual  Data& operator[](unsigned long) override;

protected:

  // Auxiliary functions, if necessary!

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
