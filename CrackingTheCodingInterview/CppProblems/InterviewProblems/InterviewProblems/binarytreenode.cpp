#include "binarytreenode.h"

using namespace com;

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

BinaryTreeNode* BinaryTreeNode::getLeftChild() {
  return leftChild;
}

BinaryTreeNode* BinaryTreeNode::getRightChild() {
  return rightChild;
}

int BinaryTreeNode::getValue() const {
  return data;
}

bool BinaryTreeNode::operator==(const BinaryTreeNode &node)
{
  //We're assuming, for all these example problems, that there are no duplicate nodes
  //in a graph with the same value to avoid the exercises becoming about refernece
  return this->getValue() == node.getValue();
}



