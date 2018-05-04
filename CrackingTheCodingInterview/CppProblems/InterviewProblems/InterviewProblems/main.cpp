#include <iostream>

#include "printklastlines.h"
#include "routebetweennodes.h"
#include "minimaltree.h"

int main() {
  
  com::TestableProblem* testClass =
    //GRAPHS AND TREES
    new graphsandtrees::RouteBetweenNodes();
    //new graphsandtrees::MinimalTree();

  testClass->runTestCases();
  
  return 0;

}
