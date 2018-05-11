#include <iostream>

#include <stack>

//Include the example problem to make sure I remember
//to modify the header guard in new problems
#include "exampleproblemtemplate.h"

#include "printklastlines.h"
#include "routebetweennodes.h"
#include "minimaltree.h"
#include "listofdepths.h"
#include "isbalanced.h"
#include "validatebst.h"
#include "successor.h"
#include "buildorder.h"
#include "firstcommonancestor.h"
#include "bstsequence.h"
#include "issubtree.h"
#include "randomnode.h"
#include "pathswithsum.h"

int main() {
  
  com::TestableProblem* testClass =
    //GRAPHS AND TREES
    //new graphsandtrees::RouteBetweenNodes();
    //new graphsandtrees::MinimalTree();
    //new graphsandtrees::ListOfDepths();
    //new graphsandtrees::IsBalanced();
    //new graphsandtrees::ValidateBst();
    //new graphsandtrees::Successor();
    //new graphsandtrees::BuildOrder();
    //new graphsandtrees::FirstCommonAncestor();
    //new graphsandtrees::BstSequence();
    //new graphsandtrees::IsSubtree();
    //new graphsandtrees::RandomNode();
    new graphsandtrees::PathsWithSum();

  testClass->runTestCases();

  return 0;
}
