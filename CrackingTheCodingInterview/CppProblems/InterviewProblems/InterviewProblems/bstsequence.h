#ifndef CHAPTERNAME_PROBLEMNAME_H_
#define CHAPTERNAME_PROBLEMNAME_H_

#include <stack>
#include <vector>

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees {

  //Chapter 4 Question 9
  class BstSequence: public com::TestableProblem {

    vector<vector<int>> bstSequence(com::binarytree::Node* root);

    vector<vector<int>> bstSequence(vector<int> intputPerm, stack<com::binarytree::Node*> options);

    vector<stack<com::binarytree::Node*>> getStackPerms(
      com::binarytree::Node* next, stack<com::binarytree::Node*> options);

    stack<com::binarytree::Node*> pushInOrder(stack<com::binarytree::Node*> stack,
      com::binarytree::Node* first, com::binarytree::Node* second, com::binarytree::Node* third);

    int numNulls(
      com::binarytree::Node* first, com::binarytree::Node* second, com::binarytree::Node* third);

    void singleTest(com::binarytree::Node* root);

    public:

    void runTestCases();
  };
}

#endif
