#include "datastructureutils.h"

using namespace com;

/* Creates and returns this graph
    0 -> 1 -> 2
    0 -> 3 -> 4 -> 5
    4 -> 1
*/
vector<graph::Node> DataStructureUtils::createGraph1() {
  vector<graph::Node> returnNodes = vector<graph::Node>({
    graph::Node(0), graph::Node(1),
    graph::Node(2), graph::Node(3),
    graph::Node(4), graph::Node(5)
  });

  returnNodes[0].addChild(&returnNodes[1]);
  returnNodes[0].addChild(&returnNodes[3]);
  returnNodes[1].addChild(&returnNodes[2]);
  returnNodes[3].addChild(&returnNodes[4]);
  returnNodes[4].addChild(&returnNodes[5]);
  returnNodes[4].addChild(&returnNodes[1]);

  return returnNodes;
}

/*
Creates and returns this binary tree
0
1          2
3       4         5
6
*/
binarytree::Node* DataStructureUtils::createTree1() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n3 = new binarytree::Node(3);
  binarytree::Node* n4 = new binarytree::Node(4);
  binarytree::Node* n5 = new binarytree::Node(5);
  binarytree::Node* n6 = new binarytree::Node(6);

  root->setLeftChild(n1);
  root->setRightChild(n2);

  n1->setLeftChild(n3);
  n1->setRightChild(n4);

  n2->setRightChild(n5);

  n3->setRightChild(n6);

  return root;
}

/*
Creates and returns this binary tree
                0
              1
            2
          3
        4
*/
binarytree::Node* DataStructureUtils::createTree2() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n3 = new binarytree::Node(3);
  binarytree::Node* n4 = new binarytree::Node(4);

  root->setLeftChild(n1);
  n1->setLeftChild(n2);
  n2->setLeftChild(n3);
  n2->setLeftChild(n4);

  return root;
}

/*
Creates and returns a binary tree with just a single root node
*/
binarytree::Node* DataStructureUtils::createTree3() {
  binarytree::Node* root = new binarytree::Node(0);

  return root;
}

//A simple vector print for data testing
string com::DataStructureUtils::printIntVector(const vector<int> &values) {
  string returnString = "{";

  for (int i = 0; i < values.size(); ++i) {
    returnString += to_string(values[i]);
    if (i < values.size() - 1){
      returnString += ", ";
    }
  }
  returnString += "}";

  return returnString;
}
