#ifndef DIAL_HPP
#define DIAL_HPP
#include <string>

class Dial {

public:
   Dial();
   int GetNext(std::string aInput);
   int GetPassThru() { return mPassThruZero; }
private:
   int mCurrent;
   int mPassThruZero;
};

#endif // DIAL_HPP