#include "graphnode.h"

//C and C++ standard libraries

//Custom external and internal libraries

using namespace com;

GraphNode::GraphNode(int data) {
}

GraphNode::~GraphNode() {
}

void GraphNode::addConnection(GraphNode* node) {

}

vector<GraphNode*> GraphNode::getConnections() {
  return {};
}

int GraphNode::getValue() {
  return data;
}

int GraphNode::numConnections() {
  return adjacentNodes.size();
}


