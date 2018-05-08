#ifndef COM_BINARYTREENODE_H_
#define COM_BINARYTREENODE_H_

#include <iostream>
#include <string>

namespace com {
  namespace binarytree {

//*-----------------------------------------------------------------------------------------*/
//A node class for binay tree problems. It's somewhat ambigously named "Node" with
//a nested namespace to help with transcribing from a whiteboard with as little
//editing as possible
//*-----------------------------------------------------------------------------------------*/
    class Node {

    public:

      //These three members (data, left, right) would normally be private, and only accessable 
      //through getters and setters, but for the pupose of whiteboarding, it's much easier
      //to access them directly

      //The data held in the node
      int data;
      //The left child of the node, NULL if this node has no left child
      Node* left;
      //The right child of the node, NULL if this node has no right child
      Node* right;
      //The parent of the node. Dont use this if the example doesn't explicitly say that
      //it's available for use. Most binary trees don't store this
      Node* parent;

      Node();
      Node(int data);
      ~Node();

      void setLeftChild(Node* node);
      void setRightChild(Node* node);
      Node* getLeftChild() const;
      Node* getRightChild() const;
      int getValue() const;
      int getHeight() const;
      bool operator==(const Node &node) const;

    };
  }
}

#endif