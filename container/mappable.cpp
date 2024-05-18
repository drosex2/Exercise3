
namespace lasd {

/* ************************************************************************** */

template <typename Data>
inline void PreOrderMappableContainer<Data>:: Map(MapFun function) {
    PreOrderMap(function);  //funzione di "rimbalzo"
};
// template <typename Data>
// inline void PreOrderMappableContainer<Data>:: PreOrderMap(MapFun function) {
//     //PreOrderMap(function);  //funzione di "rimbalzo"
// };
template <typename Data>
inline void PostOrderMappableContainer<Data>:: Map(MapFun function) {
    PostOrderMap(function);  //funzione di "rimbalzo"
};
// template <typename Data>
// inline void PostOrderMappableContainer<Data>:: PostOrderMap(MapFun function) {
//     //PostOrderMap(function);  //funzione di "rimbalzo"
// };
template <typename Data>
inline void InOrderMappableContainer<Data>:: Map(MapFun function) {
    InOrderMap(function);  //funzione di "rimbalzo"
};
// template <typename Data>
// inline void InOrderMappableContainer<Data>:: InOrderMap(MapFun function) {
//     //InOrderMap(function);  //funzione di "rimbalzo"
// };
template <typename Data>
inline void BreadthMappableContainer<Data>:: Map(MapFun function) {
    BreadthMap(function);  //funzione di "rimbalzo"
};
// template <typename Data>
// inline void BreadthMappableContainer<Data>:: BreadthMap(MapFun function) {
//     //BreadthMap(function);  //funzione di "rimbalzo"
// };
/* ************************************************************************** */

}
