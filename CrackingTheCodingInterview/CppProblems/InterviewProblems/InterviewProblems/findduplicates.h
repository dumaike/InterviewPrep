#ifndef SORTINGANDSEARCHING_FINDDUPLICATES_H_
#define SORTINGANDSEARCHING_FINDDUPLICATES_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 8
  class FindDuplicates: public com::TestableProblem {
    
    void findDuplicates(const vector<int> &values);

    void singleTest(const vector<int> &values);

    public:

    void runTestCases();
  };
}

#endif
