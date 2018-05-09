#ifndef GRAPHSANDTREES_FIRSTCOMMON_ANCESTOR_H_
#define GRAPHSANDTREES_FIRSTCOMMON_ANCESTOR_H_

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees{

  //Chapter 4 Question 7
  class FirstCommonAncestor: public com::TestableProblem {

    com::binarytree::Node* firstCommonAncestor(com::binarytree::Node* first, com::binarytree::Node* second);
    int getDepth(com::binarytree::Node* input);

    void singleTest(com::binarytree::Node* first, com::binarytree::Node* second, int result);

    public:

    void runTestCases();
  };
}

#endif
