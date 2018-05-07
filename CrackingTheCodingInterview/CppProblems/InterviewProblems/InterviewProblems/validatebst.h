#ifndef GRAPHSANDTREES_VALIDATEBST_H_
#define GRAPHSANDTREES_VALIDATEBST_H_

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees{

  //Chapter 4 Question 5
  class ClassName: public com::TestableProblem {

    void singleTest();

    bool isBstValid(com::binarytree::Node *root);

    public:

    void runTestCases();
  };
}

#endif