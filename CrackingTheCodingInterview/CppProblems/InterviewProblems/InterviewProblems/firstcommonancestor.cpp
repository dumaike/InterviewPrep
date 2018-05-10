#include "firstcommonancestor.h"

#include <iostream>

#include "datastructureutils.h"

using namespace graphsandtrees;
using namespace com::binarytree;
using namespace com;

void FirstCommonAncestor::runTestCases(){
  Node* root = DataStructureUtils::createTree2();
  Node* n1 = root->left;
  Node* n7 = root->left->left->left;
  Node* n5 = root->right->left;
  Node* n8 = root->left->left->right;
  Node* n4 = root->left->right;

  cout << "In the following binary tree: " << endl << DataStructureUtils::toString(root);
  singleTest(n1, n7, 1);
  singleTest(n8, n7, 3);
  singleTest(n7, n4, 1);
  singleTest(n8, n5, 0);
}

void FirstCommonAncestor::singleTest(Node* first, Node* second, int result){
  Node* resultNode = firstCommonAncestor(first, second);
  cout << "The first common ancestor of " << first->data << " and " << second->data << " is " <<
    resultNode->data << ", goal " << result;

  if (resultNode->data == result)
    cout << " PASSED ";
  else
    cout << " FAILED ";

  cout << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 7 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
Node* FirstCommonAncestor::firstCommonAncestor(Node* first, Node* second) {
  int firstDepth = getDepth(first);
  int secondDepth = getDepth(second);

  if (firstDepth > secondDepth) {
    int diff = firstDepth - secondDepth;
    for (int i = 0; i < diff; ++i) {
      first = first->parent;
    }
  } else {
    int diff = secondDepth - firstDepth;
    for (int i = 0; i < diff; ++i) {
      second = second->parent;
    }
  }

  while (first != second && first->parent != NULL && second->parent != NULL) {
    first = first->parent;
    second = second->parent;
  }

  if (first == second)
    return first;

  throw invalid_argument("Nodes not in same tree");
}

int FirstCommonAncestor::getDepth(Node* input) {
  int depth = 0;
  while (input->parent != NULL) {
    input = input->parent;
    depth++;
  }
  return depth;
}