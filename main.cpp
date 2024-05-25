
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2024" << std::endl;
  int choice;
  std::cout<<"1) lasdtest \n2) mytest"<<std::endl;
  std::cout<<"Inserisci un valore: ";
  std::cin>>choice;
  if(choice==1){
    lasdtest();
  }else if(choice==2)
  {
    mytest();
  }
  
  
  return 0;
}
