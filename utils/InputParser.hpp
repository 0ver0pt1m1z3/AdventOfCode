#ifndef INPUT_PARSER_HPP
#define INPUT_PARSER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class InputParser {

public:
   InputParser() = delete;
   InputParser(std::string);
   std::vector<std::string> GetData() { return mData; }
private:
   std::vector<std::string> mData;
};


#endif // INPUT_PARSER_HPP