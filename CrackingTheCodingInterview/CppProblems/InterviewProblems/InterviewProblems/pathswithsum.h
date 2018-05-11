#ifndef GRAPHSANDTREES_PATHSWITHSUM_H_
#define GRAPHSANDTREES_PATHSWITHSUM_H_

#include "binarytreenode.h"
#include "testableproblem.h"

namespace graphsandtrees{

  //Chapter 4 Question 12
  class PathsWithSum: public com::TestableProblem {

    int pathsWithSum(com::binarytree::Node* root, int sum);
    int pathsWithSum(com::binarytree::Node* root, int sum, int progress);

    void singleTest(com::binarytree::Node* root, int sum);

    public:

    void runTestCases();
  };
}

#endif
