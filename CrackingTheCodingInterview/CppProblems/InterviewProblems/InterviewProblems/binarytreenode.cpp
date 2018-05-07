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
  left = node;
}

void Node::setRightChild(Node* node) {
  right = node;
}

Node* Node::getLeftChild() const {
  return left;
}

Node* Node::getRightChild() const {
  return right;
}

int Node::getValue() const {
  return data;
}

int Node::getHeight() const{

  int leftHeight = left == NULL ? 1 : left->getHeight() + 1;
  int rightHeight = right == NULL ? 1 : right->getHeight() + 1;

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



