
// #include "..."

/* ************************************************************************** */

#include <iostream>

#include "tests/htclsadr.hpp"
#include "tests/htopnadr.hpp"
#include "../container/container.hpp"
#include "../container/mappable.hpp"

#include <random>

using namespace std;
using namespace miotest;

/* ************************************************************************** */

void mytest() {
  cout<<"WELCOME TO MY TEST!"<<endl;
  cout << "--------------TEST Hash Table Closed Addressing--------------" << endl;
  testHashTableClosedAddressing();
  cout << "--------------TEST Hash Table Open Addressing--------------" << endl;
  testHashTableOpenAddressing();
}
