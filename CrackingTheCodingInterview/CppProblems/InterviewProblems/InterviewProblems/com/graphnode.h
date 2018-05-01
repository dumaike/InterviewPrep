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
    vector<GraphNode*> adjacentNodes;

    GraphNode(int data);
    ~GraphNode();

    void addConnection(GraphNode* node);
    vector<GraphNode*> getConnections();
    int getValue();
    int numConnections();

  };
}

#endif