#include "bstsequence.h"

#include <iostream>

#include "datastructureutils.h"

using namespace graphsandtrees;
using namespace com::binarytree;

void BstSequence::runTestCases(){
  singleTest(com::DataStructureUtils::createTree3());
  singleTest(com::DataStructureUtils::createTree12());
  singleTest(com::DataStructureUtils::createTree13());
}

void BstSequence::singleTest(Node* root){
  vector<vector<int>> sequences = bstSequence(root);
  cout << sequences.size() << " possible sequences for the following tree: " << endl << 
    com::DataStructureUtils::toString(root) << endl;

  for (unsigned int i = 0; i < sequences.size(); ++i) {
    cout << com::DataStructureUtils::toString(sequences[i]) << endl;
  }

  cout << "-------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 9 transcribed as closely as possible from from my whiteboard solution.
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
vector<vector<int>> BstSequence::bstSequence(Node* root) {

  stack<Node*> optionsStack = stack<Node*>();
  if (root != NULL) {
    optionsStack.push(root);
  }

  return bstSequence({}, optionsStack);
}

vector<vector<int>> BstSequence::bstSequence(vector<int> inputPerm, stack<Node*> options) {
    Node* next = options.top();
    options.pop();

    if (options.size() == 0 && next->left == NULL && next->right == NULL) {
      inputPerm.push_back(next->data);
      return vector<vector<int>>({ {inputPerm} });
    }

    vector<vector<int>> returnPerms = vector<vector<int>>();
    inputPerm.push_back(next->data);
    vector<stack<Node*>> stackPerms = getStackPerms(next, options);

    for (unsigned int i = 0; i < stackPerms.size(); ++i) {
      vector<vector<int>> optionSet = bstSequence(inputPerm, stackPerms[i]);
        returnPerms.insert(returnPerms.end(), optionSet.begin(), optionSet.end());
    }

    return returnPerms;
}

vector<stack<Node*>> BstSequence::getStackPerms(
  com::binarytree::Node* next, stack<com::binarytree::Node*> options) {
  Node* topOption = NULL;
  if (options.size() != 0) {
    topOption = options.top();
    options.pop();
  }
  vector<stack<Node*>> returnVect = vector < stack<Node*>>();

  int nullCount = numNulls(topOption, next->right, next->left);

  if (nullCount == 1) {
    returnVect.push_back(pushInOrder(options, topOption, next->right, next->left));
  } else if (nullCount == 2) {
    returnVect.push_back(pushInOrder(options, topOption, next->right, next->left));
    returnVect.push_back(pushInOrder(options, next->left, next->right, topOption));
  } else if (nullCount = 3) {
    returnVect.push_back(pushInOrder(options, topOption, next->right, next->left));
    returnVect.push_back(pushInOrder(options, topOption, next->left, next->right));
    returnVect.push_back(pushInOrder(options, next->right, topOption, next->left));
    returnVect.push_back(pushInOrder(options, next->left, next->right, topOption));
    returnVect.push_back(pushInOrder(options, next->right, next->left, topOption));
    returnVect.push_back(pushInOrder(options, next->left, topOption, next->right));
  }

  return returnVect;
}

stack<Node*> BstSequence::pushInOrder(stack<Node*> stack, Node* first, Node* second, Node* third) {
  if (first != NULL)
    stack.push(first);
  if (second != NULL)
    stack.push(second);
  if (third != NULL)
    stack.push(third);
  return stack;
}

int BstSequence::numNulls(Node* first, Node* second, Node* third) {
  int count = 0;
  if (first != NULL)
    count++;
  if (second != NULL)
    count++;
  if (third != NULL)
    count++;
  return count;
}