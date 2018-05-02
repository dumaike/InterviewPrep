#ifndef GRAPHSANDTREES_ROUTEBETWEENNODES_H_
#define GRAPHSANDTREES_ROUTEBETWEENNODES_H_

#include <iostream>
#include <unordered_set>
#include <queue>

#include "com/graphnode.h"

using namespace std;
using namespace com;

//An solution to a problem from Cracking The Coding Interview, transcribed directly
//from my whiteboard solution. Uses some techniques for time saving that I wouldn't
//use in a production environment, for the sake of time savings and brevity.

namespace graphsandtrees{

  //Some forward declarations that we wouldn't use in production
  void addChildrenOfNodeToQueue(const GraphNode &node, queue<GraphNode> &visitQueue,
                                unordered_set<int> &visitedQueue);
  bool isVisitingNodeAMatch(queue<GraphNode> &visitQueue, const GraphNode &goalNode,
                            unordered_set<int> &visitedQueue);
  bool routeBetweenNodes(const GraphNode &fNode, const GraphNode &sNode);

  bool routeBetweenNodes(const GraphNode &fNode, const GraphNode &sNode) {
    unordered_set<int> fNodesVisited = unordered_set<int>();
    unordered_set<int> sNodesVisited = unordered_set<int>();

    queue<GraphNode> fToVisit = queue<GraphNode>();
    queue<GraphNode> sToVisit = queue<GraphNode>();

    //Check for first generation children of f that could be s
    addChildrenOfNodeToQueue(fNode, fToVisit, fNodesVisited);

    //Check for first generation children of s that could be f
    addChildrenOfNodeToQueue(sNode, sToVisit, sNodesVisited);

    //Look through all the nodes left to visit in our search
    while (fToVisit.size() > 0 || sToVisit.size() > 0){
      if (isVisitingNodeAMatch(fToVisit, sNode, fNodesVisited)){
        return true;
      }

      if (isVisitingNodeAMatch(sToVisit, fNode, sNodesVisited)){
        return true;
      }
    }

    return false;
  }

  void addChildrenOfNodeToQueue(const GraphNode &node, queue<GraphNode> &toVisitQueue,
                                unordered_set<int> &visitedQueue){
    
    const vector<GraphNode*> children = node.getChildren();
    for (GraphNode* node : children) {
      unordered_set<int>::const_iterator got = visitedQueue.find(node->getValue());

      //If we haven't visited this node already, plan to visit it
      if (got == visitedQueue.end()){
        toVisitQueue.push(*node);
        visitedQueue.insert(node->getValue());
      }
    }
  }

  bool isVisitingNodeAMatch(queue<GraphNode> &toVisitQueue, const GraphNode &goalNode,
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

}

#endif