#ifndef GRAPHSANDTREES_LISTOFDEPTHS_H_
#define GRAPHSANDTREES_LISTOFDEPTHS_H_

#include "binarytreenode.h"
#include "linkedlistnode.h"
#include "testableproblem.h"

namespace graphsandtrees{

  //Chapter 4 Question 1
  class ListOfDepths : public com::TestableProblem {

      vector<com::linkedlist::Node*> ListOfDepths::listOfDepths(com::binarytree::Node* root);

      void singleTest(com::binarytree::Node* root);

    public:

      void runTestCases();
  };
}

#endif