#include <iostream>

#include "printklastlines.h"
#include "routebetweennodes.h"

int main() {
  
  com::TestableProblem* testClass =
    new graphsandtrees::RouteBetweenNodes();

  testClass->runTestCases();
  
  return 0;

}
