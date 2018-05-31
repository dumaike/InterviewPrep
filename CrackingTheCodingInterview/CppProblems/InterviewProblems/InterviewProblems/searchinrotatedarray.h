#ifndef SORTINGANDSEARCHING_SEARCHINROTATEDARRAY_H_
#define SORTINGANDSEARCHING_SEARCHINROTATEDARRAY_H_

#include "testableproblem.h"

namespace sortingandsearching{

  //Chapter 10 Question 3
  class SearchInRotatedArray: public com::TestableProblem {

    int arraySize;
    int wrapOffset;

    void singleTest(const vector<int> &values, int find);

    int getRotationIndex(const vector<int> &values);
    int getWrappedIndex(int baseIndex);
    int searchInRotatedArray(const vector<int> &values, int find);

    public:
    const int VALUE_NOT_FOUND = -1;

    void runTestCases();
  };
}

#endif
