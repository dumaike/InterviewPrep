#include "linkedlistnode.h"

using namespace com::linkedlist;
using namespace std;

Node::Node() {
  data = 0;
  next = NULL;
}

Node::Node(int nodeData) {
  data = nodeData;
  next = NULL;
}

Node::Node(int nodeData, Node* nextNode) {
  data = nodeData;
  next = nextNode;
}

Node::~Node() {
}

void Node::setNext(Node* node) {
  next = node;
}

//In production this should be a pair of function begin and end iterators
Node* Node::getNext() const {
  return next;
}

int Node::getValue() const {
  return data;
}

bool Node::operator==(const Node &node)
{
  //We're assuming, for all these example problems, that there are no duplicate nodes
  //in a graph with the same value to avoid the exercises becoming about refernece
  return this->getValue() == node.getValue();
}



