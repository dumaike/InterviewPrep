#ifndef BITMANIPULATION_NEXTNUMBER_H_
#define BITMANIPULATION_NEXTNUMBER_H_

#include "testableproblem.h"

namespace bitmanipulation{

  //Chapter 5 Question 4
  class NextNumber: public com::TestableProblem {
    pair<int,int> nextLargestNumber(int input);
      
    pair<int,int> nextLargestNumberBruteForce(int input);
  
    int getTotalBitCount(int input);

    void singleTest(int input);

    public:

    const int NOT_FOUND = -1;

    void runTestCases();
  };
}

#endif
