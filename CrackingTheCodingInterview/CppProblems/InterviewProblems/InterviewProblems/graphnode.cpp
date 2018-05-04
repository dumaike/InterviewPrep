#include "graphnode.h"

using namespace com::graph;
using namespace std;

Node::Node() {
  data = 0;
}

Node::Node(int nodeData) {
  data = nodeData;
}

Node::~Node() {
}

void Node::addChild(Node* node) {
  childNodes.push_back(node);
}

//In production this should be a pair of function begin and end iterators
vector<Node*> Node::getChildren() const {
  return childNodes;
}

int Node::getValue() const {
  return data;
}

int Node::numConnections() {
  return childNodes.size();
}

bool Node::operator==(const Node &node)
{
  //We're assuming, for all these example problems, that there are no duplicate nodes
  //in a graph with the same value to avoid the exercises becoming about refernece
  return this->getValue() == node.getValue();
}



