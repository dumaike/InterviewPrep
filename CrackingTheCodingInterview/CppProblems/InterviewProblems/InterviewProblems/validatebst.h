#ifndef GRAPHSANDTREES_VALIDATEBST_H_
#define GRAPHSANDTREES_VALIDATEBST_H_

#include "testableproblem.h"
#include "binarytreenode.h"

namespace graphsandtrees{

  //Chapter 4 Question 5
  class ValidateBst: public com::TestableProblem {

    void singleTest(com::binarytree::Node* root);

    bool validateBst(com::binarytree::Node* root);
    bool validateBst(com::binarytree::Node* root, int &direction, int minParent, int maxParent);

    public:

    void runTestCases();
  };
}

#endif