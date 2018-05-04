#include "examplegraphs.h"

/* Creates and returns this graph
    0 -> 1 -> 2
    0 -> 3 -> 4 -> 5
    4 -> 1
*/
vector<com::graph::Node> com::ExampleDataStructures::createGraph1() {
  vector<com::graph::Node> returnNodes = vector<com::graph::Node>({
    com::graph::Node(0), com::graph::Node(1), 
    com::graph::Node(2), com::graph::Node(3),
    com::graph::Node(4), com::graph::Node(5)
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
string com::ExampleDataStructures::printIntVector(const vector<int> &values) {
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
