#include "listofdepths.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>

#include "binarytreenode.h"
#include "linkedlistnode.h"
#include "datastructureutils.h"

using namespace com;
using namespace graphsandtrees;
using namespace std;

void ListOfDepths::runTestCases() {

  singleTest(DataStructureUtils::createTree1());
  singleTest(DataStructureUtils::createTree2());
  singleTest(DataStructureUtils::createTree3());
  singleTest(DataStructureUtils::createTree4());
}

void ListOfDepths::singleTest(binarytree::Node* root) {

  cout << "Binary tree: " << endl << DataStructureUtils::toString(root) << "becomes: " << endl;
  vector<linkedlist::Node*> nodeLists = listOfDepths(root);
  for (unsigned int i = 0; i < nodeLists.size(); ++i) {
    linkedlist::Node* cur = nodeLists[i];
    cout << i << ": ";
    while (cur != NULL) {
      cout << cur->getValue();
      cur = cur->getNext();

      if (cur != NULL) {
        cout << "->";
      }
    }
    cout << endl;
  }

  cout << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 3 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/

vector<linkedlist::Node*> ListOfDepths::listOfDepths(binarytree::Node* root) {
  
  if (root == NULL) {
    return vector<linkedlist::Node*>();
  }

  stack<binarytree::Node*> thisDepth = stack<binarytree::Node*>();
  stack<binarytree::Node*> nextDepth = stack<binarytree::Node*>();

  vector<linkedlist::Node*> returnList = vector<linkedlist::Node*>();

  if (root->getLeftChild() != NULL) {
    thisDepth.push(root->getLeftChild());
  }
  if (root->getRightChild() != NULL) {
    thisDepth.push(root->getRightChild());
  }

  unsigned int depth = 1;

  returnList.push_back(new linkedlist::Node(root->getValue()));
  
  while (!thisDepth.empty()) {
    binarytree::Node* cur = thisDepth.top();
    thisDepth.pop();
    if (cur->getLeftChild() != NULL) {
      nextDepth.push(cur->getLeftChild());
    }
    if (cur->getRightChild() != NULL) {
      nextDepth.push(cur->getRightChild());
    }

    if (returnList.size() <= depth) {
      returnList.push_back(new linkedlist::Node(cur->getValue()));
    } else {
      linkedlist::Node* head = returnList[depth];
      linkedlist::Node* newHead = new linkedlist::Node(cur->getValue(), head);
      returnList[depth] = newHead;
    }

    if (thisDepth.empty()) {
      thisDepth = move(nextDepth);
      nextDepth = stack<binarytree::Node*>();
      depth++;
    }
  }

  return returnList;

}