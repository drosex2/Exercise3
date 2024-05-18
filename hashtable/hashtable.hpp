
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

/* ************************************************************************** */

#include <random>

/* ************************************************************************** */

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Hashable {

public:

  unsigned long operator()(const Data&) const noexcept=0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class HashTable: virtual public ResizableContainer, virtual public DictionaryContainer<Data> {
                  // Must extend ResizableContainer,
                  //             DictionaryContainer<Data>

private:

  // ...

protected:

  using DictionaryContainer<Data>::size;
  unsigned long a=1;
  unsigned long b=0;
  static const unsigned long prime=1000000016531;
  std::default_random_engine gen=std::default_random_engine(std::random_device{}());
  std::uniform_int_distribution<unsigned long> dista= std::uniform_int_distribution<unsigned long>(1,prime-1);
  std::uniform_int_distribution<unsigned long> distb= std::uniform_int_distribution<unsigned long>(0,prime-1);

  static const Hashable<Data> enchash;

  unsigned long tableSize=128; //

  // ...

public:

  // Destructor
  ~HashTable()=default;

  /* ************************************************************************ */

  // Copy assignment
  HashTable<Data>& operator=(const HashTable<Data>&)=delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  HashTable<Data>& operator=(HashTable<Data>&&)noexcept=delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTable<Data>&) const noexcept=delete; // Comparison of abstract hashtable is possible but not required.
  bool operator!=(const HashTable<Data>&) const noexcept=delete; // Comparison of abstract hashtable is possible but not required.

protected:

  // Auxiliary member functions

  virtual unsigned long HashKey(const Data&) const noexcept;

  virtual unsigned long HashKey(unsigned long key) const noexcept;

};

/* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
