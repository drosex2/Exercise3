
namespace lasd {
#include <string>
/* ************************************************************************** */

template <>
class Hashable<int>{
    public:
    unsigned long operator()(const int & dat) const noexcept{
        return (dat*dat);
    }
};

template <>
class Hashable<double>{
    public:
    unsigned long operator()(const double & dat) const noexcept{
        long intpart=floor(dat);
        long fracpart=pow(2,24)*(dat-intpart);
        return(intpart*fracpart);
        
    }
};

template <>
class Hashable<std::string>{
    public:
    unsigned long operator()(const std::string & dat) const noexcept{
        unsigned long hash=5381; //magic key
        for(unsigned long i=0;i<dat.length();++i){
            hash=(hash<<5)+dat[i];
        }
        return hash;
        
    }
};

//HASHTABLE

template <typename Data>
unsigned long HashTable<Data>::HashKey(const Data & dat)const noexcept{
    return HashKey(enchash(dat));
}

template <typename Data>
unsigned long HashTable<Data>::HashKey(unsigned long key)const noexcept{
    return ((a*key+b)%tableSize);
}

/* ************************************************************************** */

}
