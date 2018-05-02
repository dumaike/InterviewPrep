#ifndef GRAPHSANDTREES_EXAMPLEGRAPHS_H_
#define GRAPHSANDTREES_EXAMPLEGRAPHS_H_

#include <iostream>
#include <unordered_set>
#include <queue>

#include "com/graphnode.h"

using namespace std;
using namespace com;

//An example set of 
namespace graphsandtrees {
  
  /* Creates and returns this graph
      0 -> 1 -> 2
      ?    ?
      3 -> 4 -> 5
  */
  vector<GraphNode> createGraph1() {
    vector<GraphNode> returnNodes = vector<GraphNode>({
      GraphNode(0), GraphNode(1), GraphNode(2), GraphNode(3), GraphNode(4), GraphNode(5)
    });

    returnNodes[0].addConnection(&returnNodes[1]);
    returnNodes[0].addConnection(&returnNodes[3]);
    returnNodes[1].addConnection(&returnNodes[2]);
    returnNodes[3].addConnection(&returnNodes[4]);
    returnNodes[4].addConnection(&returnNodes[5]);
    returnNodes[4].addConnection(&returnNodes[1]);

    return returnNodes;
  }
  


}

#endif