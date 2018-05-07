#include "validatebst.h"

#include <iostream>
#include <climits>

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
  singleTest(DataStructureUtils::createTree9());
  singleTest(DataStructureUtils::createTree10());
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
  return validateBst(root, direction, INT_MIN, INT_MAX);
}

bool ValidateBst::validateBst(Node* root, int &direction, int minParent, int maxParent) {
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

    if (root->left != NULL){
      if ((root->left->data - root->data)*direction > 0 ||
          root->left->data < minParent ||
          root->left->data > maxParent) {
        return false; 
      }
    }
    if (root->right != NULL) {
      if ((root->right->data - root->data)*direction < 0 ||
          root->right->data < minParent ||
          root->right->data > maxParent) {
        return false;
      }
    }
  }

  if (root->left != NULL) {
    int tmpMax = maxParent;
    int tmpMin = minParent;
    if (direction > 0) {
      tmpMax = root->data;
    } else {
      tmpMin = root->data;
    }

    if (!validateBst(root->left, direction, tmpMin, tmpMax)) {
      return false;
    }
  }
  if (root->right != NULL){
    int tmpMax = maxParent;
    int tmpMin = minParent;
    if (direction > 0) {
      tmpMin = root->data;
    } else {
      tmpMax = root->data;
    }

    if (!validateBst(root->right, direction, tmpMin, tmpMax)) {
      return false;
    }
  }

  return true;
}
