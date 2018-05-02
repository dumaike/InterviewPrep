#ifndef INTERVIEWPREP_DATASTRUCTURES_GRAPHNODE_H
#define INTERVIEWPREP_DATASTRUCTURES_GRAPHNODE_H

//-----------------------------------------------------------------------------

#include <vector>

using namespace std;

namespace com
{
  class GraphNode {

  public:
    int data;
    vector<GraphNode*> childNodes;

    GraphNode();
    GraphNode(int data);
    ~GraphNode();

    void addChild(GraphNode* node); 
    vector<GraphNode*> GraphNode::getChildren() const;
    int getValue() const;
    int numConnections();
    bool operator==(const GraphNode &node);

  };
}

#endif