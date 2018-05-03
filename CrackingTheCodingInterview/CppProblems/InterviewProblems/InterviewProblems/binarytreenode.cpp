#include "binarytreenode.h"

#include <queue>
#include <cmath>
#include <list>

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

//Algorithm adapted from: https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
string BinaryTreeNode::toString(BinaryTreeNode* root) {
  int depth = root->getHeight();

  char buf[1024];
  int last_lvl = 0;
  int offset = (1 << depth) - 1;

  // using a queue means we perform a breadth first iteration through the tree
  std::list<NodeDepth> q;

  q.push_back(NodeDepth(root, last_lvl));

  string returnString = "";

  while (q.size())
  {
    const NodeDepth& nd = *q.begin();

    // moving to a new level in the tree, output a new line and calculate new offset
    if (last_lvl != nd.lvl)
    {
      returnString += "\n";

      last_lvl = nd.lvl;
      offset = (1 << (depth - nd.lvl)) - 1;
    }

    // output <offset><data><offset>
    string strBuffer = "";
    if (nd.n) 
    sprintf_s(buf, " %*s%d%*s", offset, " ", nd.n->data, offset, " ");
    else
    sprintf_s(buf, " %*s", offset << 1, " ");
    returnString += buf;

    if (nd.n)
    {
      q.push_back(NodeDepth(nd.n->getLeftChild(), last_lvl + 1));
      q.push_back(NodeDepth(nd.n->getRightChild(), last_lvl + 1));
    }

    q.pop_front();
  }
  returnString += "\n";

  return returnString;
}

//We're assuming, for all these example problems, that there are no duplicate nodes
//in a graph with the same value to avoid the exercises becoming about refernece
bool BinaryTreeNode::operator==(const BinaryTreeNode &node) const{
  return this->getValue() == node.getValue();
}



