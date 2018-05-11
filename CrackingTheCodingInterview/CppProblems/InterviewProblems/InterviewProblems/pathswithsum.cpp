#include "pathswithsum.h"

#include <iostream>

#include "datastructureutils.h"
#include "binarytreenode.h"

using namespace graphsandtrees;
using namespace com::binarytree;

void PathsWithSum::runTestCases(){
  singleTest(com::DataStructureUtils::createTree6(), 1);
}

void PathsWithSum::singleTest(Node* root, int sum){
  cout << "The following tree has " << pathsWithSum(root, sum) << " that sum to " << sum << endl;
  cout << com::DataStructureUtils::toString(root);
  cout << "----------------------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 12 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int PathsWithSum::pathsWithSum(Node* root, int sum) {
    return pathsWithSum(root, sum, 0);
}

int PathsWithSum::pathsWithSum(Node* root, int sum, int progress) {
  if (root == NULL)
    return 0;

  int sumFound = 0;
  int progressToHere = root->data + progress;
  if (progressToHere == sum)
    sumFound = 1;

  return pathsWithSum(root->left, sum, progressToHere) + 
         pathsWithSum(root->right, sum, progressToHere) + 
         pathsWithSum(root->left, sum, 0) + 
         pathsWithSum(root->right, sum, 0) + 
         sumFound;
}
