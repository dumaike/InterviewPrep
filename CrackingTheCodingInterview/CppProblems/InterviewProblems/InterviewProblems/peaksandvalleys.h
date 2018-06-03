#ifndef SORTINGANDSEARCHING_PEAKSANDVALLEYS_H_
#define SORTINGANDSEARCHING_PEAKSANDVALLEYS_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 11
  class PeaksAndValleys: public com::TestableProblem {

    vector<int> *cachedValues;
    
    void swapElements(int firstIndex, int secondIndex);

    void peaksAndValleys(vector<int> &values);

    void singleTest();

    public:

    void runTestCases();
  };
}

#endif
