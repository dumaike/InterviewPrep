#ifndef BITMANIUPLATION_BINARYTOSTRING_H_
#define BITMANIUPLATION_BINARYTOSTRING_H_

#include <string>

#include "testableproblem.h"

namespace bitmanipulation{

  //Chapter 5 Question 2
  class BinaryToString: public com::TestableProblem {

    string binaryToString(double binary);

    void singleTest(double input);

    public:

    void runTestCases();
  };
}

#endif
