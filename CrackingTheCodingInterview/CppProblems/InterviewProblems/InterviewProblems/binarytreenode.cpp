#include "binarytreenode.h"

#include <queue>
#include <cmath>
#include <list>

using namespace com::binarytree;
using namespace std;


Node::Node() {
  data = 0;
}

Node::Node(int nodeData) {
  data = nodeData;
}

Node::~Node() {
}

void Node::setLeftChild(Node* node) {
  leftChild = node;
}

void Node::setRightChild(Node* node) {
  rightChild = node;
}

Node* Node::getLeftChild() const {
  return leftChild;
}

Node* Node::getRightChild() const {
  return rightChild;
}

int Node::getValue() const {
  return data;
}

int Node::getHeight() const{

  int leftHeight = leftChild == NULL ? 1 : leftChild->getHeight() + 1;
  int rightHeight = rightChild == NULL ? 1 : rightChild->getHeight() + 1;

  if (leftHeight > rightHeight)
  {
    return leftHeight;
  }

  return rightHeight;
}

//We're assuming, for all these example problems, that there are no duplicate nodes
//in a graph with the same value to avoid the exercises becoming about refernece
bool Node::operator==(const Node &node) const{
  return this->getValue() == node.getValue();
}



