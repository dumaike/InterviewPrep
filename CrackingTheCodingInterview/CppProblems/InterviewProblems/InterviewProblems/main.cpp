#include <iostream>

#include "language/printklastlines.h"
#include "graphsandtrees/routebetweennodes.h"
#include "graphsandtrees/examplegraphs.h"
#include "com/graphnode.h"

int main() {

  vector<GraphNode> sampleGraph = graphsandtrees::createGraph1();

  GraphNode* ptr = &sampleGraph[4];

  bool isRoute = graphsandtrees::routeBetweenNodes(sampleGraph[1], sampleGraph[5]);

  cout << "Route between 0 and 4: " << isRoute << endl;
  
  return 0;

}
