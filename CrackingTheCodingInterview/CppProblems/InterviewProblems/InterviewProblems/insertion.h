#ifndef BITMANIPULATION_INSERTION_H_
#define BITMANIPULATION_INSERTION_H_

#include "testableproblem.h"

namespace bitmanipulation{

  //Chapter 5 Question 1
  class Insertion: public com::TestableProblem {

    int insertion(int N, int M, int i, int j);

    void singleTest();

    public:

    void runTestCases();
  };
}

#endif
