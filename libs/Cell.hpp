/*
We can make a array that represent a cell and and each cell can contain a value, to tell if a cell is empty we have 0 represent a empty cell.

TODO
  :: We check if a save file is there if their is not then we allow the user to put in data else we can load the file
  :: try to enable a feature that we can delete cells
BUG
  :: It won't save the file after putting in values.

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
#include <strings.h>
#include <vector>

// Header Files
#include "File-Reader.hpp"

#define FULL_CELLS 101
#define INVALID_INPUT 404
#define FILE_NOT_THERE 991
#define MAX_BUFFER 202

// This is used to pass a function, so we know it was ran succesfully
#define COMPLETED_FUNCTION 456

bool saveCells;
bool fileThere;

void autofill(std::vector<int> vect){
  
  for (int i = 0; i < 5; i++) { 
    vect.assign(5, 1);
  }

}

int LengthChecker(int input){

  if (std::to_string(input).length() >= 9){
    throw std::length_error("You reached maxed length in this buffer");
    return MAX_BUFFER;
  }else{
    
  }  
  return COMPLETED_FUNCTION;
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
    
    std::vector<int> cellsBoxes = {};// this is valid c++
    //int CellsSize = sizeof(cellsBoxes) / sizeof(int);
    //int CellsSize(cellsBoxes.size());
    
    if(!FileChecker){
      std::ofstream MakeFile("Bexcel-Save-File.txt");
      MakeFile.close();

      throw std::runtime_error("File is not there, please restart the program so the file can be made.");
      fileThere = false;
      return FILE_NOT_THERE;
    }else{
      FileChecker >> cellsBoxes.at(0);
      FileChecker >> cellsBoxes.at(1);
      FileChecker >> cellsBoxes.at(2);
      FileChecker >> cellsBoxes.at(3);
      FileChecker >> cellsBoxes.at(4);
      fileThere = true;
    }
    std::string input;
        
    
    Start:
    
    if(cellsBoxes.empty()){
      std::cout << "The Cells are empty \n";
        
      std::cout << "Do you wish to auto fill them with test data: ";
      std::cin >> input;

      if(input == "yes"){
        
        autofill(cellsBoxes);

        std::cout << "Successfuly Auto Filled the Cells with data: \n";
        
        for(int i = 0; i < cellsBoxes.size(); i++){
          std::cout << cellsBoxes[i] << '\n';
        } 

        
        std::fstream file;
        file.open("Bexcel-Save-File.txt", std::ios::out);
        file << cellsBoxes.at(0) << '\n';
        file << cellsBoxes.at(1) << '\n';
        file << cellsBoxes.at(2) << '\n';
        file << cellsBoxes.at(3) << '\n';
        file << cellsBoxes.at(4) << '\n';
        file << "Total Cells: " << cellsBoxes.size() << '\n';
        file.close();      
        
      }else if (input == "no"){
        //EditCells();                    
        std::cout << "Cell 0: ";
        std::wcin >> cell0;
        
        LengthChecker(cell0);

        cellsBoxes.push_back(cell0);
        
        std::cout << "Cell 1: ";
        std::wcin >> cell1;
        
        LengthChecker(cell1);         
        
        std::cin.ignore();
        cellsBoxes.push_back(cell1);
        
        std::cout << "Cell 2: ";
        std::wcin >> cell2;
        LengthChecker(cell2);
        
        std::cin.ignore();
        cellsBoxes.push_back(cell2);
        
        std::cout << "Index 3: ";
        std::wcin >> cell3;

        LengthChecker(cell3);
        
        std::cin.ignore();
        cellsBoxes.push_back(cell3);

        std::cout << "Index 4: ";
        std::wcin >> cell4;
        
        LengthChecker(cell4);

        std::cin.ignore();
        cellsBoxes.push_back(cell4);
                
        
        std::cout << "Save: ";
        std::cin >> save;

        if (save == "yes"){
          std::fstream file;
          file.open("Bexcel-Save-File.txt", std::ios::out);
          file << cellsBoxes.at(0) << '\n';
          file << cellsBoxes.at(1) << '\n';
          file << cellsBoxes.at(2) << '\n';
          file << cellsBoxes.at(3) << '\n';
          file << cellsBoxes.at(4) << '\n';
          file << "Total Cells: " << cellsBoxes.size() << '\n';
          file.close();
          save = true;
              
        }else if (save == "no"){
          saveCells = false;
        }
      }else{
        throw std::invalid_argument("Invalid Input Error!");
      
      }
           
    }else{
            
      std::cout << "Do you wish to edit the cells(type C), or read the data in the Cells(Type R) or Delete cells(Type D) : ";
      std::cin >> CellsRE;

      if(CellsRE == 'C' || CellsRE == 'c'){
 
        
        std::cout << "Cell 0: ";
        std::wcin >> cell0;
        
        LengthChecker(cell0);

        cellsBoxes.push_back(cell0);
        
        std::cout << "Cell 1: ";
        std::wcin >> cell1;
        
        LengthChecker(cell1);         
        
        std::cin.ignore();
        cellsBoxes.push_back(cell1);
        
        std::cout << "Cell 2: ";
        std::wcin >> cell2;
        LengthChecker(cell2);
        
        std::cin.ignore();
        cellsBoxes.push_back(cell2);
        
        std::cout << "Cell 3: ";
        std::wcin >> cell3;

        LengthChecker(cell3);
        
        std::cin.ignore();
        cellsBoxes.push_back(cell3);

        std::cout << "Cell 4: ";
        std::wcin >> cell4;
        
        LengthChecker(cell4);

        std::cin.ignore();
        cellsBoxes.push_back(cell4);
                
        
        std::cout << "Save: ";
        std::cin >> save;

        if (save == "yes"){
          std::fstream file;
          file.open("Bexcel-Save-File.txt", std::ios::out);
          file << cellsBoxes.at(0) << '\n';
          file << cellsBoxes.at(1) << '\n';
          file << cellsBoxes.at(2) << '\n';
          file << cellsBoxes.at(3) << '\n';
          file << cellsBoxes.at(4) << '\n';
          file << "Total Cells: " << cellsBoxes.size() << '\n';
          file.close();
          save = true;
              
        }else if (save == "no"){
          saveCells = false;
        }
               
      }else if (CellsRE == 'R' || CellsRE == 'r'){
        FileReader();          
      }else if (CellsRE == 'D' || CellsRE == 'd'){
        
      }
              
      
      return FULL_CELLS;
    }
     
    std::cout << "Total Cells: " << cellsBoxes.size() << '\n';    
    
        
    return 0;  
  }  
}
