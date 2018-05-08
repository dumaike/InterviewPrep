#ifndef GRAPHSANDTREES_SUCCESSOR_H_
#define GRAPHSANDTREES_SUCCESSOR_H_

#include "binarytreenode.h"
#include "testableproblem.h"

namespace graphsandtrees{

  //Chapter 4 Question 6
  class Successor: public com::TestableProblem {

    com::binarytree::Node* successor(com::binarytree::Node* cur);

    void singleTest(com::binarytree::Node* node);

    public:

    void runTestCases();
  };
}

#endif