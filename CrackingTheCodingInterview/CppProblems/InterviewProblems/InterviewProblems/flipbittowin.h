#ifndef BITMANIPULATION_FLIPBITTOWIN_H_
#define BITMANIPULATION_FLIPBITTOWIN_H_

#include "testableproblem.h"

namespace bitmanipulation{

  //Chapter 5 Question 3
  class FlipBitToWin: public com::TestableProblem {
    int flipBitToWin(int input);
    void singleTest(int input);

    public:

    void runTestCases();
  };
}

#endif
