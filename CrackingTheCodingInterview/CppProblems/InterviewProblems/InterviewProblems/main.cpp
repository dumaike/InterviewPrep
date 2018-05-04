#include <iostream>

#include <stack>

#include "printklastlines.h"
#include "routebetweennodes.h"
#include "minimaltree.h"
#include "listofdepths.h"

int main() {
  
  com::TestableProblem* testClass =
    //GRAPHS AND TREES
    //new graphsandtrees::RouteBetweenNodes();
    //new graphsandtrees::MinimalTree();
    new graphsandtrees::ListOfDepths();

  testClass->runTestCases();

  return 0;
}
