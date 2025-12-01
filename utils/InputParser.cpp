#include "InputParser.hpp"
#include <filesystem>
InputParser::InputParser(std::string aFile)
{
   std::fstream inputFile(aFile);

   if (!inputFile.is_open()) {
      throw std::runtime_error("File not found: " + aFile);
   }

   std::string line;
   while (std::getline(inputFile, line)) {
      mData.push_back(line);
   }

   inputFile.close();
}
