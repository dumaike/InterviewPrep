#include "isbalanced.h"

#include <iostream>
#include <string>

#include "datastructureutils.h"

using namespace graphsandtrees;
using namespace com;
using namespace com::binarytree;

void IsBalanced::runTestCases() {
  singleTest(DataStructureUtils::createTree1());
  singleTest(DataStructureUtils::createTree2());
  singleTest(DataStructureUtils::createTree3());
  singleTest(DataStructureUtils::createTree4());
}

void IsBalanced::singleTest(Node* root) {
  cout << "The following binary tree is ";

  bool balanced = isBalanced(root);

  if (balanced) {
    cout << "balanced";
  } else {
    cout << "not balanced";
  }

  cout << endl << DataStructureUtils::toString(root) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 4 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/

bool IsBalanced::isBalanced(com::binarytree::Node* root) {
  return isBalancedHelper(root) != NOT_BALANCED;
}

int IsBalanced::isBalancedHelper(com::binarytree::Node* root) {
  if (root == NULL) {
    return 0;
  }

  int leftDepth = isBalancedHelper(root->getLeftChild());
  if (leftDepth == NOT_BALANCED) {
    return NOT_BALANCED;
  }

  int rightDepth = isBalancedHelper(root->getRightChild());
  if (rightDepth == NOT_BALANCED) {
    return NOT_BALANCED;
  }

  if (rightDepth - leftDepth > 1 || rightDepth - leftDepth < -1) {
    return NOT_BALANCED;
  }

  return max(rightDepth + 1, leftDepth + 1);
}