/*
We can make a array that represent a cell and and each cell can contain a value, to tell if a cell is empty we have 0 represent a empty cell.

TODO
  :: We check if a save file is there if their is not then we allow the user to put in data else we can load the file
BUG
  :: 

Fixed:
  :: If i would give a large number in put to edit the cells it would crash(Fixed).
    - We used wcin, which can hold more values then the norm cin.
*/

#pragma once

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <stdexcept>

// Header Files
#include "File-Reader.hpp"

#define FULL_CELLS 101
#define INVALID_INPUT 404
#define FILE_NOT_THERE 991

bool saveCells;
bool fileThere;

void autofill(int (&array)[5]){
  
  for (int i = 0; i < 5; i++) { 
    array[i] = 1;
  } 
}

void LengthChecker(int input){

  if (std::to_string(input).length() >= 9){
    throw std::length_error("You reached maxed length in this buffer");
  }else{
    
  }  
  
}

namespace Cell{
  inline int main(){
    int cell0;
    int cell1; 
    int cell2; 
    int cell3; 
    int cell4;  
    
    std::string save;    
    char CellsRE;
    std::ifstream FileChecker("Bexcel-Save-File.txt");
    
    int cellsBoxes[5] = {0,0,0,0,0};
    int CellsSize = sizeof(cellsBoxes) / sizeof(int);
    
    if(!FileChecker){
      std::ofstream MakeFile("Bexcel-Save-File.txt");
      MakeFile.close();

      throw std::runtime_error("File is not there, please restart the program so the file can be made.");
      fileThere = false;
      return FILE_NOT_THERE;
    }else{
      FileChecker >> cellsBoxes[0];
      FileChecker >> cellsBoxes[1];
      FileChecker >> cellsBoxes[2];
      FileChecker >> cellsBoxes[3];
      FileChecker >> cellsBoxes[4];
      fileThere = true;
    }
    std::string input;
        
    
    Start:
    
    if(cellsBoxes[0] == 0 && cellsBoxes[1] == 0 && cellsBoxes[2] == 0 && cellsBoxes[3] == 0 && cellsBoxes[4] == 0){
      std::cout << "The Cells are empty \n";
        
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
        //EditCells();                    
        std::cout << "Cell 0: ";
        std::wcin >> cell0;
        
        LengthChecker(cell0);
        
        cellsBoxes[0] = cell0;

        std::cout << "Cell 1: ";
        std::wcin >> cell1;
        
        LengthChecker(cell1);         
        
        std::cin.ignore();
        cellsBoxes[1] = cell1;
                
        
        std::cout << "Cell 2: ";
        std::wcin >> cell2;
        LengthChecker(cell2);
        
        std::cin.ignore();
        cellsBoxes[2] = cell2;
        
        std::cout << "Index 3: ";
        std::wcin >> cell3;

        LengthChecker(cell3);
        
        std::cin.ignore();
        cellsBoxes[3] = cell3;

        std::cout << "Index 4: ";
        std::wcin >> cell4;
        
        LengthChecker(cell4);

        std::cin.ignore();
        cellsBoxes[4] = cell4;
        
                
        
        std::cout << "Save: ";
        std::cin >> save;

        if (save == "yes"){
          std::fstream file;
          file.open("Bexcel-Save-File.txt", std::ios::out);
          file << cellsBoxes[0] << '\n';
          file << cellsBoxes[1] << '\n';
          file << cellsBoxes[2] << '\n';
          file << cellsBoxes[3] << '\n';
          file << cellsBoxes[4] << '\n';
          file << "Total Cells: " << CellsSize << '\n';
          file.close();
          save = true;
              
        }else if (save == "no"){
          saveCells = false;
        }
      }else{
        throw std::invalid_argument("Invalid Input Error!");
      
      }
           
    }else{
            
      std::cout << "Do you wish to edit the cells(type C), or read the data in the Cells(Type R): ";
      std::cin >> CellsRE;

      if(CellsRE == 'C' || CellsRE == 'c'){
 
        
        std::cout << "Cell 0: ";
        std::wcin >> cell0;
        LengthChecker(cell0); 

        cellsBoxes[0] = cell0;

        std::cout << "Cell 1: ";
        std::wcin >> cell1;
        LengthChecker(cell1); 

        std::cin.ignore();
        cellsBoxes[1] = cell1;
          
        
        std::cout << "Cell 2: ";
        std::wcin >> cell2;
        LengthChecker(cell2);
        
        std::cin.ignore();
        cellsBoxes[2] = cell2;
        
        
        std::cout << "Index 3: ";
        std::wcin >> cell3;

        LengthChecker(cell3);
        
        std::cin.ignore();
        cellsBoxes[3] = cell3;

        std::cout << "Index 4: ";
        std::wcin >> cell4;

        LengthChecker(cell4);

        std::cin.ignore();
        cellsBoxes[4] = cell4;
        
                
        
        std::cout << "Save: ";
        std::cin >> save;

        if (save == "yes"){
          std::fstream file;
          file.open("Bexcel-Save-File.txt", std::ios::out);
          file << cellsBoxes[0] << '\n';
          file << cellsBoxes[1] << '\n';
          file << cellsBoxes[2] << '\n';
          file << cellsBoxes[3] << '\n';
          file << cellsBoxes[4] << '\n';
          file << "Total Cells: " << CellsSize << '\n';
          file.close();
          save = true;
              
        }else if (save == "no"){
          saveCells = false;
        }
               
        goto Start;
      }else if (CellsRE == 'R' || CellsRE == 'r'){
        FileReader();          
      }
              
      
      return FULL_CELLS;
    }
     
    std::cout << "Total Cells: " << CellsSize << '\n';    
    
        
    return 0;  
  }  
}
