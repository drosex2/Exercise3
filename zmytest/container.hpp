#ifndef TESTCONTAINER_HPP
#define TESTCONTAINER_HPP

namespace miotest{
  template <typename Data>
void MapPreOrder(lasd::PreOrderMappableContainer<Data> & con, typename lasd::MappableContainer<Data>::MapFun fun) {
  try {
    con.PreOrderMap(fun);
  } catch(std::exception& exc) {
    //std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << exc.what()<< std::endl;
  }
}
template <typename Data>
void MapInOrder(lasd::InOrderMappableContainer<Data> & con, typename lasd::MappableContainer<Data>::MapFun fun) {
  try {
    con.InOrderMap(fun);
  } catch(std::exception& exc) {
    //std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << exc.what()<< std::endl;
  }
}
template <typename Data>
void MapPostOrder(lasd::PostOrderMappableContainer<Data> & con, typename lasd::MappableContainer<Data>::MapFun fun) {
  try {
    con.PostOrderMap(fun);
  } catch(std::exception& exc) {
    //std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << exc.what()<< std::endl;
  }
}
template <typename Data>
void MapBreadth(lasd::BreadthMappableContainer<Data> & con, typename lasd::MappableContainer<Data>::MapFun fun) {
  try {
    con.BreadthMap(fun);
  } catch(std::exception& exc) {
    //std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
    std::cout << exc.what()<< std::endl;
  }
}

template <typename Data>
void MapPrint(const Data& dat) {
  std::cout << dat << " ";
}


template <typename Data, typename Value>
void FoldPostOrder( const lasd::PostOrderTraversableContainer<Data> & con, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival) {
  
  try {
    std::cout << "Executing fold in post order - ";
    Value val = con.PostOrderFold(fun, inival);
    std::cout << "obtained value is " << val << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << exc.what()<< std::endl;
  }
  
}
template <typename Data, typename Value>
void FoldPreOrder( const lasd::PreOrderTraversableContainer<Data> & con, typename lasd::TraversableContainer<Data>::FoldFun<Value> fun, const Value & inival) {
  
  try {
    std::cout << "Executing fold in pre order - ";
    Value val = con.PreOrderFold(fun, inival);
    std::cout << "obtained value is " << val << std::endl;
  }
  catch (std::exception & exc) {
    std::cout << exc.what()<< std::endl;
  }
  
}
}


#endif