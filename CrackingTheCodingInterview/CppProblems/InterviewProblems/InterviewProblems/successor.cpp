#include "successor.h"

#include <iostream>

#include "datastructureutils.h"

using namespace graphsandtrees;
using namespace com::binarytree;
using namespace com;

void Successor::runTestCases()
{
  singleTest(DataStructureUtils::createTree1());
  singleTest(DataStructureUtils::createTree2());
  singleTest(DataStructureUtils::createTree3());
  singleTest(DataStructureUtils::createTree4());
  singleTest(DataStructureUtils::createTree5());
  singleTest(DataStructureUtils::createTree6());
  singleTest(DataStructureUtils::createTree7());
  singleTest(DataStructureUtils::createTree8());
  singleTest(DataStructureUtils::createTree9());
  singleTest(DataStructureUtils::createTree10());
  singleTest(DataStructureUtils::createTree11());
}

void Successor::singleTest(Node* root){

  //First get to the "first" node in inorder traversal
  Node* nextNode = root;
  while (nextNode->left != NULL) {
    nextNode = nextNode->left;
  }

  cout << "In the following binary tree, the nodes in order are: " << nextNode->data ;

  nextNode = successor(nextNode);
  while (nextNode != NULL) {
    cout << ", " << nextNode->data;
    nextNode = successor(nextNode);
  }

  cout << endl << DataStructureUtils::toString(root) << endl;
  cout << "-----------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 6 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
Node* Successor::successor(Node* cur){
  if (cur->right != NULL) {
    cur = cur->right;
    while (cur->left != NULL) {
      cur = cur->left;
    }
    return cur;
  } else {
    Node* tmpCur = cur;
    while (tmpCur->parent != NULL && tmpCur->parent->right == tmpCur) {
      tmpCur = tmpCur->parent;
    }
    if (tmpCur->parent != NULL && tmpCur->parent->left == tmpCur) {
      return tmpCur->parent;
    }
    if (cur->parent != NULL && cur->parent->left == cur) {
      return cur->parent;
    }
  }

  return NULL;
}