#include "examplegraphs.h"

/* Creates and returns this graph
    0 -> 1 -> 2
    0 -> 3 -> 4 -> 5
    4 -> 1
*/
vector<GraphNode> ExampleDataStructures::createGraph1() {
  vector<GraphNode> returnNodes = vector<GraphNode>({
    GraphNode(0), GraphNode(1), GraphNode(2), GraphNode(3), GraphNode(4), GraphNode(5)
  });

  returnNodes[0].addChild(&returnNodes[1]);
  returnNodes[0].addChild(&returnNodes[3]);
  returnNodes[1].addChild(&returnNodes[2]);
  returnNodes[3].addChild(&returnNodes[4]);
  returnNodes[4].addChild(&returnNodes[5]);
  returnNodes[4].addChild(&returnNodes[1]);

  return returnNodes;
}

//A simple vector print for data testing
string ExampleDataStructures::printIntVector(const vector<int> &values) {
  string returnString = "{";

  for (int i = 0; i < values.size(); ++i) {
    returnString += to_string(values[i]);
    if (i < values.size() - 1){
      returnString += ", ";
    }
  }
  returnString += "}";

  return returnString;
}
