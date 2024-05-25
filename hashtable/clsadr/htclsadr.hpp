
#ifndef HTCLSADR_HPP
#define HTCLSADR_HPP

/* ************************************************************************** */

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"
#include "../../list/list.hpp"
/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class HashTableClsAdr: virtual public HashTable<Data> {
  // Must extend HashTable<Data>

private:

  // ...

protected:

  // using HashTable<Data>::???;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::gen;
  using HashTable<Data>::dista;
  using HashTable<Data>::distb;
  using HashTable<Data>::size;
  using HashTable<Data>::tableSize;
  using HashTable<Data>::maxTableSize;
  using HashTable<Data>::HashKey;
  Vector<List<Data>> Table;

public:

  // Default constructor
  HashTableClsAdr();

  /* ************************************************************************ */

  // Specific constructors
  HashTableClsAdr(unsigned long); // A hash table of a given size
  HashTableClsAdr(const TraversableContainer<Data>&); // A hash table obtained from a TraversableContainer
  HashTableClsAdr(unsigned long,const TraversableContainer<Data>&); // A hash table of a given size obtained from a TraversableContainer
  HashTableClsAdr(MappableContainer<Data>&&); // A hash table obtained from a MappableContainer
  HashTableClsAdr(unsigned long,MappableContainer<Data>&&); // A hash table of a given size obtained from a MappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableClsAdr(const HashTableClsAdr<Data>&);

  // Move constructor
  HashTableClsAdr(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~HashTableClsAdr();

  /* ************************************************************************ */

  // Copy assignment
  HashTableClsAdr<Data>& operator=(const HashTableClsAdr<Data>&);

  // Move assignment
  HashTableClsAdr<Data>& operator=(HashTableClsAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const HashTableClsAdr<Data>&) const noexcept;
  virtual bool operator!=(const HashTableClsAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  virtual bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  virtual bool Insert(Data&&) override; // Override DictionaryContainer member (Move of the value)
  virtual bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  virtual void Resize(unsigned long) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  virtual void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "htclsadr.cpp"

#endif
