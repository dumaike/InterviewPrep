#ifndef SORTINGANDSEARCHING_SORTEDMERGE_H_
#define SORTINGANDSEARCHING_SORTEDMERGE_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 1
  class SortedMerge: public com::TestableProblem {

    void sortedMerge(int a[], int aSize, const int b[], int bSize);

    void singleTest();

    public:

    void runTestCases();
  };
}

#endif
