#ifndef GRAPHSANDTREES_EXAMPLEGRAPHS_H_
#define GRAPHSANDTREES_EXAMPLEGRAPHS_H_

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

#include "graphnode.h"

using namespace std;

//An example set of data structures to use in testing problems
namespace com {
  class ExampleDataStructures {
    public:
      /* Creates and returns this graph
          0 -> 1 -> 2
          0 -> 3 -> 4 -> 5
          4 -> 1
      */
      static vector<com::graph::Node> createGraph1();

      static string printIntVector(const vector<int> &values);
  };
}

#endif