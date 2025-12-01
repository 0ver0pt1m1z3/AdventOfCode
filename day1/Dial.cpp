#include "Dial.hpp"
#include <iostream>

Dial::Dial() : mCurrent(50)
             , mPassThruZero(0)
{
}

// aDir 0 = left, 1 = right
int Dial::GetNext(std::string aInput)
{
   std::string dir = aInput.substr(0, 1);
   int num = std::stoi(aInput.substr(1));
   mPassThruZero += num / mCurrent;
   if (dir == "L")
   {
      mCurrent -= num;
   }
   else if (dir == "R")
   {
      mCurrent += num;
   }
   else 
   {
      std::cout << "Param 1 can only be 0(left) or 1(right)" << std::endl;
   }

   return (mCurrent % 100 + 100) % 100;;
}
