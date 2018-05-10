#ifndef GRAPHSANDTREES_RANDOMNODE_H_
#define GRAPHSANDTREES_RANDOMNODE_H_

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees{

  //Chapter 4 Question 11
  class RandomNode: public com::TestableProblem {
    
    com::binarytree::Node* randomNode(com::binarytree::Node* root);
    
    com::binarytree::Node* randomNode(com::binarytree::Node* root, int &numNodes);

    int getNodeCount(com::binarytree::Node* root);

    public:

    void runTestCases();
  };
}

#endif
