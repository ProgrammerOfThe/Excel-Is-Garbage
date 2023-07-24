/*
We can make a array that represent a cell and and each cell can contain a value, to tell if a cell is empty we have 0 represent a empty cell.

*/

#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>

#define FULL_CELLS 101
bool saveCells;

void autofill(int (&array)[5]){
  
  for (int i = 0; i < 5; i++) { 
    array[i] = 1;
  } 
}

void EditCells(){
  
  int cell0; 
  int cell1; 
  int cell2; 
  int cell3; 
  int cell4; 
  int array[5]; 
  int CellsSize = sizeof(array) / sizeof(int);
  
  std::string save;  
    
  std::cout << "Cell 0: ";
  std::cin >> cell0;
          
  array[0] = cell0;

  std::cout << "Cell 1: ";
  std::cin >> cell1;

  array[1] = cell1;

  std::cout << "Index 2: ";
  std::cin >> cell2;

  array[2] = cell2;

  std::cout << "Index 3: ";
  std::cin >> cell3;

  array[3] = cell3;

  std::cout << "Index 4: ";
  std::cin >> cell4;

  array[4] = cell4;

  std::cout << "Save: ";
  std::cin >> save;

  if (save == "yes"){
    std::fstream file;
    file.open("Bexcel-Save-File.txt", std::ios::out);
    file << array[0] << '\n';
    file << array[1] << '\n';
    file << array[2] << '\n';
    file << array[3] << '\n';
    file << array[4] << '\n';
    file << "Total Cells: " << CellsSize << '\n';
    file.close();
    save = true;    
  }else if (save == "no"){
    saveCells = false;
  }
}
namespace Cell{
  int main(){
    std::ifstream FileChecker("Bexcel-Save-File");
        
    std::string input;
    std::string editCells;
    
    int cellsBoxes[5] = {11,1,1,1,1,};
    
    int CellsSize = sizeof(cellsBoxes) / sizeof(int);
    
    Start:
    
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
        file.open("Bexcel-Save-File.txt", std::ios::out);
        file << cellsBoxes[0] << '\n';
        file << cellsBoxes[1] << '\n';
        file << cellsBoxes[2] << '\n';
        file << cellsBoxes[3] << '\n';
        file << cellsBoxes[4] << '\n';
        file << "Total Cells: " << CellsSize << '\n';
        file.close();      
        
      }else if (input == "no"){
        EditCells();                    
      
      }else{
        throw std::invalid_argument("Invalid Input Error!");
      }
           
    }else{

      for(int i = 0; i < CellsSize; i++){
        std::cout << cellsBoxes[i] << '\n';
        
        std::cout << "Do you wish to edit the cells: ";
        std::cin >> editCells;

        if(editCells == "yes"){
          EditCells();
        }
              
      }
      return FULL_CELLS;
    }
     
    std::cout << "Total Cells: " << CellsSize << '\n';    
    
        
    return 0;  
  }  
}
