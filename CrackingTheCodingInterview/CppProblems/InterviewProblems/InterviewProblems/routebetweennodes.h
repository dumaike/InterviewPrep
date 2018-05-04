#ifndef GRAPHSANDTREES_ROUTEBETWEENNODES_H_
#define GRAPHSANDTREES_ROUTEBETWEENNODES_H_

#include <queue>
#include <unordered_set>

#include "graphnode.h"
#include "testableproblem.h"

using namespace com;
using namespace com::graph;

namespace graphsandtrees{

  //Chapter 4 Question 1
  class RouteBetweenNodes : public TestableProblem {

      void addChildrenOfNodeToQueue(const Node &node, queue<Node> &visitQueue,
                                    unordered_set<int> &visitedQueue);

      bool isVisitingNodeAMatch(queue<Node> &visitQueue, const Node &goalNode,
                                unordered_set<int> &visitedQueue);

      bool routeBetweenNodes(const Node &fNode, const Node &sNode);

      void singleTest(const vector<Node> &graph, int leftNodeIndex,
                      int rightNodeIndex, bool expectedResult);

    public:

      void runTestCases();
  };
}

#endif