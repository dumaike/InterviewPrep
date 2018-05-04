#ifndef GRAPHSANDTREES_MINIMALTREE_H_
#define GRAPHSANDTREES_MINIMALTREE_H_

#include "binarytreenode.h"
#include "testableproblem.h"

namespace graphsandtrees{
  //Chapter 4 Question 2
  class MinimalTree : public com::TestableProblem {

    com::binarytree::Node minimalTree(const vector<int> &values);

    com::binarytree::Node* makeTreeHelper(const vector<int> &values, int left, int right);

    void singleTest(const vector<int> &inputVector);

    public:

      void runTestCases();
  };
}

#endif
