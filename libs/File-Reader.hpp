#pragma once

#include <iostream>
#include <fstream>

#include <string>

std::string getFileContents (std::ifstream&);            //Gets file contents

int FileReader()
{
    std::string fileName = "Bexcel-Save-File.txt";

    //std::cout << "FileName: ";
    // std::cin >> fileName;

    std::ifstream Reader (fileName);             //Open file

    std::string Art = getFileContents (Reader);       //Get file
    
    std::cout << Art << std::endl;               //Print it to the screen

    Reader.close ();                           //Close file

    return 0;
}

std::string getFileContents (std::ifstream& File){
std::string Lines = "";        //All lines
    
  if (File){  
    while (File.good ()){
	    std::string TempLine;                  //Temp line
	    std::getline (File , TempLine);        //Get temp line
	    TempLine += "\n";                      //Add newline character
	    
	    Lines += TempLine;                     //Add newline
    }
    return Lines;
  }else{
    return "ERROR File does not exist.";
  }

    return 0;
}