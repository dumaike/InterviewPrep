#ifndef COM_GRAPHNODE_H_
#define COM_GRAPHNODE_H_

//-----------------------------------------------------------------------------

#include <vector>

using namespace std;

namespace com {
  namespace graph {

//*-----------------------------------------------------------------------------------------*/
//A node class for graph problems. It's somewhat ambigously named "Node" with
//a nested namespace to help with transcribing from a whiteboard with as little
//editing as possible
//*-----------------------------------------------------------------------------------------*/
    class Node {

      int data;
      vector<Node*> childNodes;

    public:

      Node();
      Node(int data);
      ~Node();

      void addChild(Node* node);
      vector<Node*> getChildren() const;
      int getValue() const;
      int numChildren();
      bool operator==(const Node &node);

    };
  }
}

#endif