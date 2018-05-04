#ifndef COM_LINKEDLISTNODE_H_
#define COM_LINKEDLISTNODE_H_

//-----------------------------------------------------------------------------

#include <vector>

using namespace std;

namespace com {
  namespace linkedlist {

//*-----------------------------------------------------------------------------------------*/
//A node class for graph problems. It's somewhat ambigously named "Node" with
//a nested namespace to help with transcribing from a whiteboard with as little
//editing as possible
//*-----------------------------------------------------------------------------------------*/
    class Node {

      int data = 0;
      Node* next = NULL;

    public:

      Node();
      Node(int data);
      Node(int data, Node* nextNode);
      ~Node();

      void setNext(Node* node);
      Node* getNext() const;
      int getValue() const;
      bool operator==(const Node &node);

    };
  }
}

#endif