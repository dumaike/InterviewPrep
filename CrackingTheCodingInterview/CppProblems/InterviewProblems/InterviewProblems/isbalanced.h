#ifndef GRAPHSANDTREES_IS_BALANCED_H_
#define GRAPHSANDTREES_IS_BALANCED_H_

#include <queue>
#include <unordered_set>

#include "binarytreenode.h"
#include "testableproblem.h"


namespace graphsandtrees{

  //Chapter 4 Question 4
  class IsBalanced : public com::TestableProblem {

    const int NOT_BALANCED = -1;

    bool isBalanced(com::binarytree::Node* root);
    int isBalancedHelper(com::binarytree::Node* root);

    void singleTest(com::binarytree::Node* root);

    public:

    void runTestCases();
  };
}

#endif