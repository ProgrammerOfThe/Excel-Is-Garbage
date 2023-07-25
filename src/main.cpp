#include <iostream>
#include <unistd.h>

// Header Files
#include "../libs/Cell.hpp"

int main(){
  int input;
  std::cout << "Welcome to Bexcel \n";

  std::cout << "Loading Cells \n";
  sleep(1);

  system("clear");

  std::cout << "Pick From the following Options: ";
  std::cin >> input;

  switch(input){
    case 1:
      Cell::main();
  }
  
}