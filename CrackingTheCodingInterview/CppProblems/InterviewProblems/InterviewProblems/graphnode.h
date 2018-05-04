#ifndef COM_GRAPHNODE_H_
#define COM_GRAPHNODE_H_

//-----------------------------------------------------------------------------

#include <vector>

using namespace std;

//*-----------------------------------------------------------------------------------------*/
//A node class for graph problems. It's somewhat ambigously named "Node" with
//a nested namespace to help with transcribing from a whiteboard with as little
//editing as possible
//*-----------------------------------------------------------------------------------------*/
namespace com {
  namespace graph {
    class Node {

    public:
      int data;
      vector<Node*> childNodes;

      Node();
      Node(int data);
      ~Node();

      void addChild(Node* node);
      vector<Node*> Node::getChildren() const;
      int getValue() const;
      int numConnections();
      bool operator==(const Node &node);

    };
  }
}

#endif