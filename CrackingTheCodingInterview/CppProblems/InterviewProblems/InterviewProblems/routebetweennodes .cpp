#include "routebetweennodes.h"

#include <iostream>
#include <string>

#include "datastructureutils.h"

using namespace graphsandtrees;

void RouteBetweenNodes::runTestCases()
{
  vector<Node> sampleGraph = DataStructureUtils::createGraph1();

  singleTest(sampleGraph, 1, 5, false);
  singleTest(sampleGraph, 1, 3, true);
  singleTest(sampleGraph, 0, 5, true);
  singleTest(sampleGraph, 2, 5, false);
  singleTest(sampleGraph, 2, 3, true);
  
}

void RouteBetweenNodes::singleTest(
    const vector<Node> &graph, int leftNodeIndex, 
    int rightNodeIndex, bool expectedResult)
{
  bool isRoute = routeBetweenNodes(graph[leftNodeIndex], graph[rightNodeIndex]);
  string routeAsString = isRoute ? "true" : "false";
  string testPassedAsString = isRoute == expectedResult ? "Test Passed" : "Test Failed";

  cout << "Route between Node " << leftNodeIndex << " and Node " << rightNodeIndex <<
    ": " << routeAsString << " - " << testPassedAsString << endl;
}

//*-----------------------------------------------------------------------------------------*/
// The below code is a solution to a problem from Cracking The Coding Interview 6th Edition
// Chapter 4 Question 1 transcribed as closely as possible from from my whiteboard solution. 
// Uses some techniques for the sake of time savings and brevity that I wouldn't endorse in 
// a production environment.
//*-----------------------------------------------------------------------------------------*/

bool RouteBetweenNodes::routeBetweenNodes(const Node &fNode, const Node &sNode) {
  unordered_set<int> fNodesVisited = unordered_set<int>();
  unordered_set<int> sNodesVisited = unordered_set<int>();

  queue<Node> fToVisit = queue<Node>();
  queue<Node> sToVisit = queue<Node>();

  addChildrenOfNodeToQueue(fNode, fToVisit, fNodesVisited);

  addChildrenOfNodeToQueue(sNode, sToVisit, sNodesVisited);

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

void RouteBetweenNodes::addChildrenOfNodeToQueue(const Node &node, queue<Node> &toVisitQueue,
  unordered_set<int> &visitedQueue) {

  const vector<Node*> children = node.getChildren();
  for (Node* node : children) {
    unordered_set<int>::const_iterator got = visitedQueue.find(node->getValue());

    if (got == visitedQueue.end()) {
      toVisitQueue.push(*node);
      visitedQueue.insert(node->getValue());
    }
  }
}

bool RouteBetweenNodes::isVisitingNodeAMatch(queue<Node> &toVisitQueue, const Node &goalNode,
  unordered_set<int> &visitedQueue) {
  if (toVisitQueue.size() > 0) {
    Node visitingNode = toVisitQueue.back();

    if (visitingNode == goalNode) {
      return true;
    }

    toVisitQueue.pop();

    addChildrenOfNodeToQueue(visitingNode, toVisitQueue, visitedQueue);
  }

  return false;
}