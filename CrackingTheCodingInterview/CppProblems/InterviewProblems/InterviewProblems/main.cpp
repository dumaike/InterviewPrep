#include <iostream>

#include <stack>

//Include the example problem to make sure I remember
//to modify the header guard in new problems
#include "exampleproblemtemplate.h"

//Language
#include "printklastlines.h"

//Graphs and Trees
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

//Bit Manipulation
#include "insertion.h"
#include "binarytostring.h"
#include "flipbittowin.h"
#include "nextnumber.h"

//Sorting and Searching
#include "sortedmerge.h"
#include "groupanagrams.h"

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
    //new graphsandtrees::PathsWithSum();

    //BIT MANIPULATION
    //new bitmanipulation::Insertion();
    //new bitmanipulation::BinaryToString();
    //new bitmanipulation::FlipBitToWin();
    //new bitmanipulation::NextNumber();

    //SORTINGANDSEARCHING
    //new sortingandsearching::SortedMerge();
    new sortingandsearching::GroupAnagrams();

  testClass->runTestCases();

  return 0;
}
