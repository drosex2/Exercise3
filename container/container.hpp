
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...

protected:

  
public:
    unsigned long size=0;

      Container()=default;
    
    // Destructor
      ~Container()=default;

      /* ************************************************************************ */

      // Copy assignment
      virtual Container& operator=(const Container&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      virtual Container& operator=(Container&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
      virtual bool operator==(const Container&) const noexcept=delete; // Comparison of abstract types is not possible.
      virtual bool operator!=(const Container&) const noexcept=delete; // Comparison of abstract types is not possible.

      /* ************************************************************************ */

      // Specific member functions

      virtual bool Empty() const noexcept{// (concrete function should not throw exceptions)
        if (size==0){
          return true;
        }
        else{
          return false;
        }
      } 

      virtual unsigned long Size() const noexcept{
        return size;
      } // (concrete function should not throw exceptions)
  

};

/* ************************************************************************** */

class ClearableContainer: virtual public Container {
  // Must extend Container

private:

  // ...

protected:

    
public:
  

  ~ClearableContainer()=default; //default destructor

  /* ************************************************************************ */

  // Copy assignment
      virtual ClearableContainer& operator=(const ClearableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
      virtual ClearableContainer& operator=(ClearableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
      virtual bool operator==(const ClearableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
      virtual bool operator!=(const ClearableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Clear()=0;
   
 

};

/* ************************************************************************** */

class ResizableContainer: virtual public ClearableContainer {
  

private:

  // ...

protected:

    
public:
  

  ~ResizableContainer()=default; //default destructor

  /* ************************************************************************ */

  // Copy assignment
  virtual ResizableContainer& operator=(const ResizableContainer&)=delete; // Copy assignment of abstract types is not possible.

      // Move assignment
  virtual ResizableContainer& operator=(ResizableContainer&&)=delete; // Move assignment of abstract types is not possible.

      /* ************************************************************************ */

      // Comparison operators
  virtual bool operator==(const ResizableContainer&) const noexcept=delete; // Comparison of abstract types is not possible.
  virtual bool operator!=(const ResizableContainer&) const noexcept=delete;  // Comparison of abstract types is not possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual void Resize(unsigned long newsize){
    if(newsize==0)
    {
      Clear();
    }
    else
    {
      size=newsize;
    }
  }

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  virtual void Clear() override{
    size=0;
  } // Override ClearableContainer member
  

};

/* ************************************************************************** */

}

#endif
