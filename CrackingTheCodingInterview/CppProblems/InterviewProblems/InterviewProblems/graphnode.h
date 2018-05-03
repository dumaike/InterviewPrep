#ifndef COM_GRAPHNODE_H_
#define COM_GRAPHNODE_H_

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