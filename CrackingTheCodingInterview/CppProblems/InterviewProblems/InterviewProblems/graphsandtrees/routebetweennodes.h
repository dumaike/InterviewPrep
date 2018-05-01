#ifndef GRAPHSANDTREES_ROUTEBETWEENNODES_H_
#define GRAPHSANDTREES_ROUTEBETWEENNODES_H_

#include <iostream>
#include <unordered_set>
#include <queue>

#include "com/graphnode.h"

using namespace std;
using namespace com;

namespace graphsandtrees {
  
  GraphNode n1 = GraphNode(1);
  GraphNode n2 = GraphNode(2);
  GraphNode n3 = GraphNode(3);
  GraphNode n4 = GraphNode(4);
  GraphNode n5 = GraphNode(5);
  GraphNode n6 = GraphNode(6);
  GraphNode n7 = GraphNode(7);
  
  bool routeBetweenNodes(GraphNode fNode, GraphNode sNode) {
    unordered_set<GraphNode, GraphNode> fNodesVisited = unordered_set<GraphNode, GraphNode>();
    unordered_set<GraphNode, GraphNode> sNodesVisited = unordered_set<GraphNode, GraphNode>();

    queue<GraphNode> fToVisit = queue<GraphNode>();
    queue<GraphNode> sToVisit = queue<GraphNode>();

    //Check for first generation children of f that could be s
    vector<GraphNode*> fChildren = fNode.getChildren();
    for (GraphNode* node : fChildren) {      
      fToVisit.push(*node);
    }

    //Check for first generation children of s that could be f
    vector<GraphNode*> sChildren = sNode.getChildren();
    for (GraphNode* node : sChildren) {
      sToVisit.push(*node);
    }

    //Look through all the nodes in our bi-directional BFS left
    //to visit
    while (fToVisit.size() > 0 || sToVisit.size() > 0){
      //If we have a node to visit from f, check that one
      if (fToVisit.size() > 0){
        GraphNode visitingNode = fToVisit.back();

        //If it's s, and we're done
        if (visitingNode == sNode){
          return true;
        }

        //Otherwise 
        fToVisit.pop();
      }

    }

    return false;
  }

  void addChildrenOfNodeToQueue(GraphNode &node, queue<GraphNode> &visitQueue)
  {
    const vector<GraphNode*> children = node.getChildren();
    for (GraphNode* node : children) {
      visitQueue.push(*node);
    }
  }

}

#endif