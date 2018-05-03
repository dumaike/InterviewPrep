#ifndef GRAPHSANDTREES_MINIMALTREE_H_
#define GRAPHSANDTREES_MINIMALTREE_H_

#include "binarytreenode.h"
#include "testableproblem.h"

using namespace com;

namespace graphsandtrees{
  //Chapter 4 Question 2
  class MinimalTree : public TestableProblem {

    BinaryTreeNode minimalTree(const vector<int> &values);

    BinaryTreeNode* makeTreeHelper(const vector<int> &values, int left, int right);

    void singleTest(const vector<int> &inputVector);

    public:

      void runTestCases();
  };
}

#endif