#include "traversable.hpp"

namespace lasd {

/* ************************************************************************** */
template <typename Data>
inline bool TraversableContainer<Data>::Exists(const Data& value) const noexcept{
    bool exists=false;
    Traverse(
        [value, &exists](const Data& dato){
            exists= exists || (dato == value);
        }
    );
    return exists;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator TraversableContainer<Data>::Fold(FoldFun<Accumulator> fun, const Accumulator& acc) const{
    Accumulator accumulator=acc;
    Traverse(
        [fun,&accumulator](const Data& dato){
            accumulator=fun(dato,accumulator);
        }
        
    );
    return accumulator;
}

template <typename Data>
template <typename Accumulator>
inline Accumulator PreOrderTraversableContainer<Data>::PreOrderFold(FoldFun<Accumulator> fun,const Accumulator& acc) const{
    Accumulator accumulator=acc;
    PreOrderTraverse(
        [fun,&accumulator](const Data& dato){
            accumulator=fun(dato,accumulator);
        }
        
    );
    return accumulator;
}

template <typename Data>
inline void PreOrderTraversableContainer<Data>:: Traverse(TraverseFun fun) const {
    PreOrderTraverse(fun);  //funzione di "rimbalzo"
}
// template <typename Data>
// inline void PreOrderTraversableContainer<Data>:: PreOrderTraverse(TraverseFun fun) const {
//     //
// }
template <typename Data>
template <typename Accumulator>
inline Accumulator InOrderTraversableContainer<Data>::InOrderFold(FoldFun<Accumulator> fun,const Accumulator& acc) const{
    Accumulator accumulator=acc;
    InOrderTraverse(
        [fun,&accumulator](const Data& dato){
            accumulator=fun(dato,accumulator);
        }
        
    );
    return accumulator;
}

template <typename Data>
inline void InOrderTraversableContainer<Data>:: Traverse(TraverseFun fun) const {
    InOrderTraverse(fun);  //funzione di "rimbalzo"
}
// template <typename Data>
// inline void InOrderTraversableContainer<Data>:: InOrderTraverse(TraverseFun fun) const {
//     //InOrderTraverse(fun);  //funzione di "rimbalzo"
// }

template <typename Data>
template <typename Accumulator>
inline Accumulator PostOrderTraversableContainer<Data>::PostOrderFold(FoldFun<Accumulator> fun,const Accumulator& acc) const{
    Accumulator accumulator=acc;
    PostOrderTraverse(
        [fun,&accumulator](const Data& dato){
            accumulator=fun(dato,accumulator);
        }
        
    );
    return accumulator;
}

template <typename Data>
inline void PostOrderTraversableContainer<Data>:: Traverse(TraverseFun fun) const {
    PostOrderTraverse(fun);  //funzione di "rimbalzo"
}


template <typename Data>
template <typename Accumulator>
inline Accumulator BreadthTraversableContainer<Data>::BreadthFold(FoldFun<Accumulator> fun,const Accumulator& acc) const{
    Accumulator accumulator=acc;
    BreadthTraverse(
        [fun,&accumulator](const Data& dato){
            accumulator=fun(dato,accumulator);
        }
        
    );
    return accumulator;
}

template <typename Data>
inline void BreadthTraversableContainer<Data>:: Traverse(TraverseFun fun) const {
    BreadthTraverse(fun);  //funzione di "rimbalzo"
}
// template <typename Data>
// inline void BreadthTraversableContainer<Data>:: BreadthTraverse(TraverseFun fun) const {
//     //BreadthTraverse(fun);  //funzione di "rimbalzo"
// }

/* ************************************************************************** */

}
