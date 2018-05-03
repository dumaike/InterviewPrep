#include "binarytreenode.h"

#include <queue>
#include <cmath>

using namespace com;
using namespace std;


BinaryTreeNode::BinaryTreeNode() {
  data = 0;
}

BinaryTreeNode::BinaryTreeNode(int nodeData) {
  data = nodeData;
}

BinaryTreeNode::~BinaryTreeNode() {
}

void BinaryTreeNode::setLeftChild(BinaryTreeNode* node) {
  leftChild = node;
}

void BinaryTreeNode::setRightChild(BinaryTreeNode* node) {
  rightChild = node;
}

BinaryTreeNode* BinaryTreeNode::getLeftChild() const {
  return leftChild;
}

BinaryTreeNode* BinaryTreeNode::getRightChild() const {
  return rightChild;
}

int BinaryTreeNode::getValue() const {
  return data;
}

int BinaryTreeNode::getHeight() const{

  int leftHeight = leftChild == NULL ? 1 : leftChild->getHeight() + 1;
  int rightHeight = rightChild == NULL ? 1 : rightChild->getHeight() + 1;

  if (leftHeight > rightHeight)
  {
    return leftHeight;
  }

  return rightHeight;
}

string BinaryTreeNode::toString() const {
  int height = getHeight();

  queue<BinaryTreeNode*> nodesToPrintThisLevel = queue<BinaryTreeNode*>();
  queue<BinaryTreeNode*> nodesToPrintNextLevel = queue<BinaryTreeNode*>();

  if (this->getLeftChild() != NULL) {
    nodesToPrintThisLevel.push(this->getLeftChild());
  }
  if (this->getRightChild() != NULL) {
    nodesToPrintThisLevel.push(this->getRightChild());
  }

  string returnString = spacesPerTreeDepth(0, height) + to_string(getValue()) + "\n";

  int depth = 1;
  string spaces = spacesPerTreeDepth(1, height);
  while (!nodesToPrintThisLevel.empty()) {
    const BinaryTreeNode* curNode = nodesToPrintThisLevel.front();
    nodesToPrintThisLevel.pop();
    returnString += spaces + to_string(curNode->getValue());

    if (curNode->getLeftChild() != NULL) {
      nodesToPrintNextLevel.push(curNode->getLeftChild());
    }
    if (curNode->getRightChild() != NULL) {
      nodesToPrintNextLevel.push(curNode->getRightChild());
    }

    if (nodesToPrintThisLevel.empty() && !nodesToPrintNextLevel.empty()){
      nodesToPrintThisLevel = move(nodesToPrintNextLevel);
      nodesToPrintNextLevel = queue<BinaryTreeNode*>();
      returnString += "\n";
      depth++;
      spaces = spacesPerTreeDepth(depth, height);
    }
  }

  return returnString;
}

string BinaryTreeNode::spacesPerTreeDepth(int depth, int height) const {
  string returnString = "";

  int numSpaces = pow(2, height - depth - 1);
  for (int i = 0; i < numSpaces; ++i)
  {
    returnString += " ";
  }

  return returnString;
}

//We're assuming, for all these example problems, that there are no duplicate nodes
//in a graph with the same value to avoid the exercises becoming about refernece
bool BinaryTreeNode::operator==(const BinaryTreeNode &node) const{
  return this->getValue() == node.getValue();
}



