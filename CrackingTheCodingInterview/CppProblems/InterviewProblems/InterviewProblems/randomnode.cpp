#include "randomnode.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "datastructureutils.h"


using namespace graphsandtrees;
using namespace com::binarytree;

void RandomNode::runTestCases(){
  /* initialize random seed: */
  srand (time(NULL));

  cout << "From the following tree, we got the following nodes: " << endl;

  Node* root = com::DataStructureUtils::createTree1();
  cout << com::DataStructureUtils::toString(root) << endl << endl;

  int valueCounts[8] = {0,0,0,0,0,0,0,0};
  for (int i = 0; i < 10000; ++i){
    valueCounts[randomNode(root)->data]++;
  }

  for (int i = 0; i < 8; ++i) {
    cout << i << ": " << valueCounts[i] << endl;
  }
  cout << "---------------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 11 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
Node* RandomNode::randomNode(Node* root) {
  int numNodes = getNodeCount(root);
  return randomNode(root, numNodes);
}
    
Node* RandomNode::randomNode(Node* root, int &numNodes) {
  if (root == NULL)
    return NULL;

  int rand = std::rand() % numNodes;
  numNodes--;
  if (rand == 0)
    return root;

  Node* leftChosen = randomNode(root->left, numNodes);
  if (leftChosen != NULL)
    return leftChosen;

  Node* rightChosen = randomNode(root->right, numNodes);
  if (rightChosen != NULL)
    return rightChosen;

  return NULL;
}

int RandomNode::getNodeCount(Node* root) {
  if (root == NULL)
    return 0;

  return getNodeCount(root->left) + getNodeCount(root->right) + 1;
}