#ifndef GRAPHSANDTREES_EXAMPLEGRAPHS_H_
#define GRAPHSANDTREES_EXAMPLEGRAPHS_H_

#include <iostream>
#include <unordered_set>
#include <queue>
#include <string>

#include "graphnode.h"
#include "binarytreenode.h"

using namespace std;

//An example set of data structures to use in testing problems
namespace com {
  class DataStructureUtils {
      //A class to help print out trees in the console
      struct NodeDepth
      {
        binarytree::Node* n;
        int lvl;
        NodeDepth(binarytree::Node* n_, int lvl_) : n(n_), lvl(lvl_) {}
      };

    public:

      /* Creates and returns this graph
      0 -> 1 -> 2
      0 -> 3 -> 4 -> 5
      4 -> 1
      */
      static vector<com::graph::Node> createGraph1();

      /* Creates and returns this binary tree
                   0
              1          2
          3      4          5
            6
      */
      static com::binarytree::Node* createTree1();

      /*
      Creates and returns this binary tree
                  0
                1
              2
            3
          4
      */
      static com::binarytree::Node* createTree2();

      /*
      Creates and returns a binary tree with just a single root node
      */
      static com::binarytree::Node* createTree3();

      static string toString(const vector<int> &values);
      static string toString(binarytree::Node* root);
  };
}

#endif