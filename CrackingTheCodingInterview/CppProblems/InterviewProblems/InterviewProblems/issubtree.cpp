#include "issubtree.h"

#include "datastructureutils.h"

#include <iostream>

using namespace graphsandtrees;
using namespace com::binarytree;


void IsSubtree::runTestCases(){
  singleTest(com::DataStructureUtils::createTree10(), com::DataStructureUtils::createTree12());
}

void IsSubtree::singleTest(Node* root1, Node* root2){
  cout << "First Tree: " << endl << com::DataStructureUtils::toString(root1) << endl;
  cout << "Second Tree: " << endl << com::DataStructureUtils::toString(root2) << endl;

  cout << "Second tree " << (isSubtree(root1, root2) ? "is" : "is NOT") << " a subtree of first tree" << endl;
  cout << "------------------------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 10 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
bool IsSubtree::isSubtree(Node* root1, Node* root2) {
  if (root1 == NULL && root2 != NULL) {
     return false;
  } else if (root2 == NULL) {
    return true;
  }

  if (root1->data == root2->data) {
    bool subtreeMatch = treeCompare(root1, root2);
    if (subtreeMatch)
      return true;
  }

  return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}

bool IsSubtree::treeCompare(Node* root1, Node* root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  else if ((root1 == NULL && root2 != NULL) ||
           (root1 != NULL && root2 == NULL))
    return false;
  else if (root1->data != root2->data)
    return false;
  else
    return treeCompare(root1->left, root2->left) && treeCompare(root1->right, root2->right);
}