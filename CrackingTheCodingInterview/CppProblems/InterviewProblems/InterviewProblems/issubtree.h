#ifndef GRAPHSANDTREES_ISSUBTREE_H_
#define GRAPHSANDTREES_ISSUBTREE_H_

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees{

  //Chapter 4 Question 10
  class IsSubtree: public com::TestableProblem {

    void singleTest(com::binarytree::Node* root1, com::binarytree::Node* root2);

    bool treeCompare(com::binarytree::Node* root1, com::binarytree::Node* root2);
    bool isSubtree(com::binarytree::Node* root1, com::binarytree::Node* root2);

    public:

    void runTestCases();
  };
}

#endif
