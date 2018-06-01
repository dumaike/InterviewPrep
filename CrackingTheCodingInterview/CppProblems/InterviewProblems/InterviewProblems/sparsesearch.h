#ifndef SORTINGANDSEARCHING_SPARSESEARCH_H_
#define SORTINGANDSEARCHING_SPARSESEARCH_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 5
  class SparseSearch: public com::TestableProblem {

    vector<string> storedVector;

    int sparseSearch(const vector<string> &values, string find);

    void singleTest(const vector<string> &values, string find);

    int trollToValid(int index, bool goLeft);

    public:

    void runTestCases();
  };
}

#endif
