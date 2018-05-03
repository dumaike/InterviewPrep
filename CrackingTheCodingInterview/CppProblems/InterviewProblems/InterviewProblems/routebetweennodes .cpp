#include "routebetweennodes.h"

#include <iostream>
#include <string>

#include "examplegraphs.h"

using namespace graphsandtrees;

void RouteBetweenNodes::runTestCases()
{
  vector<GraphNode> sampleGraph = createGraph1();

  singleTest(sampleGraph, 1, 5, false);
  singleTest(sampleGraph, 1, 3, true);
  singleTest(sampleGraph, 0, 5, true);
  singleTest(sampleGraph, 2, 5, false);
  singleTest(sampleGraph, 2, 3, true);
  
}

void RouteBetweenNodes::singleTest(
    const vector<GraphNode> &graph, int leftNodeIndex, 
    int rightNodeIndex, bool expectedResult)
{
  bool isRoute = routeBetweenNodes(graph[leftNodeIndex], graph[rightNodeIndex]);
  string routeAsString = isRoute ? "true" : "false";
  string testPassedAsString = isRoute == expectedResult ? "Test Passed" : "Test Failed";

  cout << "Route between Node " << leftNodeIndex << " and Node " << rightNodeIndex <<
    ": " << routeAsString << " - " << testPassedAsString << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview, transcribed as
// closely as possible from from my whiteboard solution. Uses some techniques for the sake of time
// savings and brevity that I wouldn't endorse in a production environment.
//*-----------------------------------------------------------------------------------------*/

bool RouteBetweenNodes::routeBetweenNodes(const GraphNode &fNode, const GraphNode &sNode) {
  unordered_set<int> fNodesVisited = unordered_set<int>();
  unordered_set<int> sNodesVisited = unordered_set<int>();

  queue<GraphNode> fToVisit = queue<GraphNode>();
  queue<GraphNode> sToVisit = queue<GraphNode>();

  //Check for first generation children of f that could be s
  addChildrenOfNodeToQueue(fNode, fToVisit, fNodesVisited);

  //Check for first generation children of s that could be f
  addChildrenOfNodeToQueue(sNode, sToVisit, sNodesVisited);

  //Look through all the nodes left to visit in our search
  while (fToVisit.size() > 0 || sToVisit.size() > 0) {
    if (isVisitingNodeAMatch(fToVisit, sNode, fNodesVisited)) {
      return true;
    }

    if (isVisitingNodeAMatch(sToVisit, fNode, sNodesVisited)) {
      return true;
    }
  }

  return false;
}

void RouteBetweenNodes::addChildrenOfNodeToQueue(const GraphNode &node, queue<GraphNode> &toVisitQueue,
  unordered_set<int> &visitedQueue) {

  const vector<GraphNode*> children = node.getChildren();
  for (GraphNode* node : children) {
    unordered_set<int>::const_iterator got = visitedQueue.find(node->getValue());

    //If we haven't visited this node already, plan to visit it
    if (got == visitedQueue.end()) {
      toVisitQueue.push(*node);
      visitedQueue.insert(node->getValue());
    }
  }
}

bool RouteBetweenNodes::isVisitingNodeAMatch(queue<GraphNode> &toVisitQueue, const GraphNode &goalNode,
  unordered_set<int> &visitedQueue) {
  //If we have a node to visit from f, check that one
  if (toVisitQueue.size() > 0) {
    GraphNode visitingNode = toVisitQueue.back();

    //If it's s, and we're done
    if (visitingNode == goalNode) {
      return true;
    }

    //Otherwise 
    toVisitQueue.pop();

    addChildrenOfNodeToQueue(visitingNode, toVisitQueue, visitedQueue);
  }

  return false;
}