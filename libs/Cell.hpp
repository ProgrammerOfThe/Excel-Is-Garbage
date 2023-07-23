/*
We can make a array that represent a cell and and each cell can contain a value, to tell if a cell is empty we have 0 represent a empty cell.

*/

//#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>

#define FULL_CELLS 101

void autofill(int (&array)[5]){
  
  for (int i = 0; i < 5; i++) { 
    array[i] = 1;
  } 
}
namespace Cell{
  int main(){
    
    int index0;
    int index1;
    int index2;
    int index3;
    int index4;
    std::string input;
    
    int cellsBoxes[5] = {0,0,0,0,0,};
    
    int CellsSize = sizeof(cellsBoxes) / sizeof(int);
    
    if(cellsBoxes[0] == 0 && cellsBoxes[1] == 0 && cellsBoxes[2] == 0 && cellsBoxes[3] == 0 && cellsBoxes[4] == 0){
        std::cout << "Do you wish to auto fill them with test data: ";
        std::cin >> input;

      if(input == "yes"){
        
        autofill(cellsBoxes);

        std::cout << "Successfuly Auto Filled the Cells with data: \n";
        
        for(int i = 0; i < CellsSize; i++){
          std::cout << cellsBoxes[i] << '\n';
            
        } 

        
        std::fstream file;
        file.open("SaveFile.txt", std::ios::out);
        file << cellsBoxes[0] << '\n';
        file << cellsBoxes[1] << '\n';
        file << cellsBoxes[2] << '\n';
        file << cellsBoxes[3] << '\n';
        file << cellsBoxes[4] << '\n';
        file << "Total Cells: " << CellsSize << '\n';
        file.close();      
        
      }else if (input == "no"){
        std::cout << "Index 0: ";
        std::cin >> index0;

        cellsBoxes[0] = index0;

        std::cout << "Index 1: ";
        std::cin >> index1;

        cellsBoxes[1] = index1;

        std::cout << "Index 2: ";
        std::cin >> index2;

        cellsBoxes[2] = index2;

        std::cout << "Index 3: ";
        std::cin >> index3;

        cellsBoxes[3] = index3;

        std::cout << "Index 4: ";
        std::cin >> index4;

        cellsBoxes[4] = index4;

        std::fstream file;
        file.open("SaveFile.txt", std::ios::out);
        file << cellsBoxes[0] << '\n';
        file << cellsBoxes[1] << '\n';
        file << cellsBoxes[2] << '\n';
        file << cellsBoxes[3] << '\n';
        file << cellsBoxes[4] << '\n';
        file << "Total Cells: " << CellsSize << '\n';
        file.close();       
      
      }else{
        throw std::invalid_argument("Invalid Input Error!");
      }
           
    }else{

      for(int i = 0; i < CellsSize; i++){
        std::cout << cellsBoxes[i] << '\n';
      }
      std::cout << "Cells Boxes are not empty \n";
    }
     
    std::cout << "Total Cells: " << CellsSize << '\n';    
    
        
    return 0;  
  }  
}
