#ifndef GRAPHSANDTREES_EXAMPLEGRAPHS_H_
#define GRAPHSANDTREES_EXAMPLEGRAPHS_H_

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

#include "graphnode.h"

using namespace std;
using namespace com;

//An example set of data structures to use in testing problems
namespace com {
  class ExampleDataStructures {
    public:
      /* Creates and returns this graph
          0 -> 1 -> 2
          ?    ?
          3 -> 4 -> 5
      */
      static vector<GraphNode> createGraph1();

      static string printIntVector(const vector<int> &values);
  };
}

#endif