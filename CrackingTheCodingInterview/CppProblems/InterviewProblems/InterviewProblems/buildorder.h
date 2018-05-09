#ifndef GRAPHSANDTREES_BUILDORDER_H_
#define GRAPHSANDTREES_BUILDORDER_H_

#include "testableproblem.h"

namespace graphsandtrees{

  //Chapter 4 Question 7
  class BuildOrder: public com::TestableProblem {

    void singleTest();

    vector<char> BuildOrder::buildOrder(const vector<char> &projList, const vector<pair<char, char>> &depList);

    public:

    void runTestCases();
  };
}

#endif