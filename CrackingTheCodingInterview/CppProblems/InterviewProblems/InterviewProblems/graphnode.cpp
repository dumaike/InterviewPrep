#include "graphnode.h"

using namespace com;
using namespace std;

GraphNode::GraphNode() {
  data = 0;
}

GraphNode::GraphNode(int nodeData) {
  data = nodeData;
}

GraphNode::~GraphNode() {
}

void GraphNode::addChild(GraphNode* node) {
  childNodes.push_back(node);
}

//In production this should be a pair of function begin and end iterators
vector<GraphNode*> GraphNode::getChildren() const {
  return childNodes;
}

int GraphNode::getValue() const {
  return data;
}

int GraphNode::numConnections() {
  return childNodes.size();
}

bool GraphNode::operator==(const GraphNode &node)
{
  //We're assuming, for all these example problems, that there are no duplicate nodes
  //in a graph with the same value to avoid the exercises becoming about refernece
  return this->getValue() == node.getValue();
}



