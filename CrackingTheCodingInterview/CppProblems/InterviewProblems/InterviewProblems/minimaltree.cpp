#include "minimaltree.h"

#include <iostream>
#include <string>

#include "examplegraphs.h"

using namespace graphsandtrees;
using namespace com;
using namespace com::binarytree;

void MinimalTree::runTestCases()
{
  singleTest(vector<int>{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15});
  singleTest(vector<int>{0});
  singleTest(vector<int>{0,0,0,0,0});
  singleTest(vector<int>{0,1,1,2});
}

void MinimalTree::singleTest(const vector<int> &inputVector) {
  cout << "Vector: " << ExampleDataStructures::printIntVector(inputVector) << " becomes:" << endl;
  Node root = minimalTree(inputVector);
  cout << root.toString(&root) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview
// Chapter 4 Question 2 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/

Node MinimalTree::minimalTree(const vector<int> &values) {
  if (values.size() == 0) {
    throw invalid_argument("Array size 0");
    return NULL;
  }

  int middle = values.size() / 2;
  Node root = Node(values[middle]);

  if (middle - 1 >= 0) {
    root.setLeftChild(makeTreeHelper(values, 0, middle - 1));
  }
  if (middle + 1 < values.size()) {
    root.setRightChild(makeTreeHelper(values, middle + 1, values.size() - 1));
  }

  return root;
}

Node* MinimalTree::makeTreeHelper(const vector<int> &values, int left, int right){

  int middle = ((right - left + 1) / 2) + left;
  Node* returnNode = new Node(values[middle]);

  if (middle - 1 >= left) {
    returnNode->setLeftChild(makeTreeHelper(values, left, middle - 1));
  }
  if (middle + 1 <= right) {
    returnNode->setRightChild(makeTreeHelper(values, middle + 1, right));
  }

  return returnNode;
}