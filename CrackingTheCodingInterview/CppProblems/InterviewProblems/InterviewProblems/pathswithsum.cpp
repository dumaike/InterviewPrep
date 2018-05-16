#include "pathswithsum.h"

#include <iostream>

#include "datastructureutils.h"
#include "binarytreenode.h"

using namespace graphsandtrees;
using namespace com::binarytree;

void PathsWithSum::runTestCases(){
  singleTest(com::DataStructureUtils::createTree6(), 1);
  singleTest(com::DataStructureUtils::createTree1(), 4);
}

void PathsWithSum::singleTest(Node* root, int sum){
  cout << "The following tree has " << pathsWithSum(root, sum) << " that sum to " << sum << endl;
  cout << com::DataStructureUtils::toString(root);
  cout << "-------------------------------------------------------------------------------" << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 12 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
int PathsWithSum::pathsWithSum(Node* root, int sum) {
    return pathsWithSum(root, sum, 0, true);
}

int PathsWithSum::pathsWithSum(Node* root, int sum, int progress, bool mainPath) {
  if (root == NULL)
    return 0;

  int sumFound = 0;
  int progressToHere = root->data + progress;
  if (progressToHere == sum)
    sumFound = 1;
  
  int leftProgress = pathsWithSum(root->left, sum, progressToHere, mainPath);
  int leftRestart = (mainPath ? pathsWithSum(root->left, sum, 0, false) : 0);
  int rightProgress = pathsWithSum(root->right, sum, progressToHere, mainPath);
  int rightRestart = (mainPath ? pathsWithSum(root->right, sum, 0, false) : 0);
  int returnPaths = leftProgress + leftRestart +
         rightProgress + rightRestart +
         sumFound;
  return returnPaths;
}
