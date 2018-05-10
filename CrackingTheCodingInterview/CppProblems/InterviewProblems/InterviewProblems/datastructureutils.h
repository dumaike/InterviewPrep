#ifndef GRAPHSANDTREES_EXAMPLEGRAPHS_H_
#define GRAPHSANDTREES_EXAMPLEGRAPHS_H_

#include <iostream>
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

      /* Creates and returns this graph (DOT notation)
      / 0 -> 1 -> 2
      / 0 -> 3 -> 4 -> 5
      / 4 -> 1
      */
      static vector<com::graph::Node> createGraph1();

      /* Creates and returns this binary tree
      /            0
      /          /   \
      /         /     \
      /        1       2
      /       / \       \
      /      3   4       5
      /     /
      /    6
      /     \
      /      7
      */
      static com::binarytree::Node* createTree1();

      /* Creates and returns this binary tree
      /               0
      /              /  \
      /             /    \
      /            /      \
      /           /        \
      /          /          \
      /         1            2
      /        / \          / \
      /       /   \        /   \
      /      3     4      5     6
      /     / \   / \    / \   / \
      /    7   8 9   10 11 12 13 14
      */
      static com::binarytree::Node* createTree2();

      /*
      Creates and returns this binary search tree
      /            0
      /           /
      /          1
      /         /
      /        2
      /       /
      /      3
      /     /
      /    4
      */
      static com::binarytree::Node* createTree3();

      /*
      / Creates and returns a binary tree with just a single root node
      */
      static com::binarytree::Node* createTree4();

      /* Creates and returns this binary tree
      /             0
      /           /  \
      /          /    \
      /         0      0
      /        / \    / \
      /       0   1  1   0
      */
      static com::binarytree::Node* createTree5();

      /* Creates and returns this binary tree
      /             0
      /           /  \
      /          /    \
      /         0      0
      /        / \    / \
      /       1   0  0   1
      */
      static com::binarytree::Node* createTree6();

      /* Creates and returns this binary tree
      /               0
      /                 \
      /                  \
      /                   1
      /                  / \
      /                 /   \
      /                2     3
      */
      static com::binarytree::Node* createTree7();

      /* Creates and returns this binary tree
      /               0
      /                 \
      /                  \
      /                   1
      /                  / \
      /                 /   \
      /                -1     3
      */
      static com::binarytree::Node* createTree8();

      /* Creates and returns this binary tree
      /               0
      /              /
      /             /
      /            -1
      /           / \
      /          /   \
      /        -2     3
      */
      static com::binarytree::Node* createTree9();

      /* Creates and returns this binary search tree
      /               10
      /              /  \
      /             /    \
      /            /      \
      /           /        \
      /          /          \
      /         5            15
      /        / \          / \
      /       /   \        /   \
      /      3     7      12    17
      /     / \   / \    / \  
      /    1   4 6   8  11  13 
      */
      static com::binarytree::Node* createTree10();


      /* Creates and returns this binary search tree
      /               8
      /              /  \
      /             /    \
      /            /      \
      /           /        \
      /          /          \
      /         4            12
      /        / \          / \
      /       /   \        /   \
      /      2     6      10   14
      /     / \   / \    / \   / \
      /    1   3 5   7  9  11 13  15
      */
      static com::binarytree::Node* createTree11();


      /* Creates and returns this binary search tree
      /            12
      /           /  \
      /          /    \
      /         10      14
      /        / 
      /      93
      */
      static com::binarytree::Node* createTree12();


      /* Creates and returns this binary search tree
      /               8
      /              /  \
      /             /    \
      /            /      \
      /           /        \
      /          /          \
      /         4            12
      /        / \          / \
      /       /   \        /   \
      /      2     6      10   14
      */
      static com::binarytree::Node* createTree13();

      static string toString(const vector<int> &values);
      static string toString(const vector<char> &values);
      static string toString(binarytree::Node* root);
  };
}

#endif