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

      int data;
      Node* leftChild;
      Node* rightChild;

    public:

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
      std::string static toString(Node* root);

    };
  }
}

#endif