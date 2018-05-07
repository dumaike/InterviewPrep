#include "validatebst.h"

#include <iostream>

#include "datastructureutils.h"

using namespace graphsandtrees;
using namespace com;
using namespace com::binarytree;

void ValidateBst::runTestCases()
{
  singleTest(DataStructureUtils::createTree1());
  singleTest(DataStructureUtils::createTree2());
  singleTest(DataStructureUtils::createTree3());
  singleTest(DataStructureUtils::createTree4());
  singleTest(DataStructureUtils::createTree5());
  singleTest(DataStructureUtils::createTree6());
  singleTest(DataStructureUtils::createTree7());
  singleTest(DataStructureUtils::createTree8());
}

void ValidateBst::singleTest(Node* root)
{
  cout << "The following binary tree is ";

  bool balanced = validateBst(root);

  if (balanced) {
    cout << "a BST";
  } else {
    cout << "not a BST";
  }

  cout << endl << DataStructureUtils::toString(root) << endl;
  cout << "-----------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 5 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
bool ValidateBst::validateBst(Node* root) {
  int direction = 0;
  return validateBst(root, direction);
}

bool ValidateBst::validateBst(Node* root, int &direction) {
  if (direction == 0) {
    if (root->left!= NULL) {
      int leftVal = root->left->data;
      if (leftVal < root->data)
        direction = 1;
      else if (leftVal > root->data)
        direction = -1;
    }

    if (root->right != NULL && direction == 0) {
      int rightVal = root->right->data;
      if (rightVal > root->data)
        direction = 1;
      else if (rightVal < root->data)
        direction = -1;
    }
  }

  if (direction != 0) {
    if (root->left != NULL &&
      (root->left->data - root->data)*direction > 0) {
        return false;
    }
    if (root->right != NULL &&
      (root->right->data - root->data)*direction < 0) {
        return false;
    }
  }

  if (root->left != NULL && !validateBst(root->left, direction)) {
    return false;
  }if (root->right != NULL && !validateBst(root->right, direction)) {
    return false;
  }

  return true;
}
