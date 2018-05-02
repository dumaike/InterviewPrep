#ifndef GRAPHSANDTREES_ROUTEBETWEENNODES_H_
#define GRAPHSANDTREES_ROUTEBETWEENNODES_H_

#include <queue>
#include <unordered_set>

#include "graphnode.h"
#include "testableproblem.h"

//An solution to a problem from Cracking The Coding Interview, transcribed directly
//from my whiteboard solution. Uses some techniques for time saving that I wouldn't
//use in a production environment, for the sake of time savings and brevity.
using namespace com;

namespace graphsandtrees{
  class RouteBetweenNodes : public TestableProblem {

      void addChildrenOfNodeToQueue(const GraphNode &node, queue<GraphNode> &visitQueue,
                                    unordered_set<int> &visitedQueue);

      bool isVisitingNodeAMatch(queue<GraphNode> &visitQueue, const GraphNode &goalNode,
                                unordered_set<int> &visitedQueue);

      bool routeBetweenNodes(const GraphNode &fNode, const GraphNode &sNode);

      void singleTest(const vector<GraphNode> &graph, int leftNodeIndex,
                      int rightNodeIndex, bool expectedResult);

    public:

      void RouteBetweenNodes::runTestCases();
  };
}

#endif