#include "rankfromstream.h"

#include <iostream>
#include <utility>

using namespace sortingandsearching;
using namespace com::binarytree;
using namespace std;

void RankFromStream::runTestCases(){
  singleTest();
}

void RankFromStream::singleTest(){
  resetStream();
  
  track(5);
  track(1);
  track(4);
  track(4);
  track(5);
  track(9);
  track(7);
  track(13);
  track(3);
  
  cout << getRankOfNumber(1) << endl;
  cout << getRankOfNumber(3) << endl;
  cout << getRankOfNumber(4) << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 10 Question 9 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/
void RankFromStream::track(int x){
  if (bstRoot == NULL){
    bstRoot = new StreamNode(x);
    nodeMap.insert(pair<int,Node*>(x, bstRoot));
  } else {
    insertIntoTree(bstRoot, x);
  }
}

void RankFromStream::insertIntoTree(Node* root, int x){

  if (x < root->data){

    ((StreamNode*)(root))->leftChildrenCount++;

    if (root->left == NULL){
      Node* insertedNode = new StreamNode(x);
      root->setLeftChild(insertedNode);

      nodeMap[x] = insertedNode;
    } else {
      insertIntoTree(root->left, x);
    }
  } else {
    if (root->right == NULL){
      Node* insertedNode = new StreamNode(x);
      root->setRightChild(insertedNode);

      nodeMap[x] = insertedNode;

    } else {      
      StreamNode* streamNode = (StreamNode*)root->right;
      insertIntoTree(root->right, x);
    }
  }
}

int RankFromStream::getRankOfNumber(int x){
  StreamNode* streamNode = (StreamNode*)nodeMap.find(x)->second;
  return getRankOfNumber(streamNode, NULL) + streamNode->leftChildrenCount;
}

int RankFromStream::getRankOfNumber(StreamNode* curNode, StreamNode* prevNode){
  if (curNode == NULL || curNode->parent == NULL){
    return 0;
  }

  int returnCount = 0;
  if (curNode->right == prevNode && prevNode != NULL){
    returnCount += curNode->leftChildrenCount + 1;
  }

  return returnCount + getRankOfNumber((StreamNode*)curNode->parent, curNode);
}

void RankFromStream::resetStream(){
  delete bstRoot;
  bstRoot = NULL;

  nodeMap.clear();
}