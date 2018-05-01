#include "graphnode.h"

//C and C++ standard libraries

//Custom external and internal libraries

using namespace com;

GraphNode::GraphNode() {
  data = 0;
}

GraphNode::GraphNode(int nodeData) {
  data = nodeData;
}

GraphNode::~GraphNode() {
}

void GraphNode::addConnection(GraphNode* node) {
  adjacentNodes.push_back(node);
}

//In production this should be a pair of function begin and end iterators
vector<GraphNode*> GraphNode::getChildren() const {
  return adjacentNodes;
}

int GraphNode::getValue() const {
  return data;
}

int GraphNode::numConnections() {
  return adjacentNodes.size();
}

bool GraphNode::operator==(const GraphNode &node)
{
  return this == &node;
}

// custom specialization of std::hash can be injected in namespace std
namespace std
{
  template<> struct hash<GraphNode>
  {
    typedef GraphNode argument_type;
    typedef std::size_t result_type;
    result_type operator()(argument_type const &node) const noexcept
    {
      return std::hash<int>{}(node.getValue());
    }
  };
}



