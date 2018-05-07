#include <iostream>

#include <stack>

#include "printklastlines.h"
#include "routebetweennodes.h"
#include "minimaltree.h"
#include "listofdepths.h"
#include "isbalanced.h"
#include "validatebst.h"

int main() {
  
  com::TestableProblem* testClass =
    //GRAPHS AND TREES
    //new graphsandtrees::RouteBetweenNodes();
    //new graphsandtrees::MinimalTree();
    //new graphsandtrees::ListOfDepths();
    //new graphsandtrees::IsBalanced();
    new graphsandtrees::ValidateBst();

  testClass->runTestCases();

  return 0;
}
