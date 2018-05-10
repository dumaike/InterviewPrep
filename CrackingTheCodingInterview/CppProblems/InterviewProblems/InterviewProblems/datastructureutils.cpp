#include "datastructureutils.h"

#include <queue>
#include <list>

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

binarytree::Node* DataStructureUtils::createTree1() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n3 = new binarytree::Node(3);
  binarytree::Node* n4 = new binarytree::Node(4);
  binarytree::Node* n5 = new binarytree::Node(5);
  binarytree::Node* n6 = new binarytree::Node(6);
  binarytree::Node* n7 = new binarytree::Node(7);

  root->setLeftChild(n1);
  root->setRightChild(n2);

  n1->setLeftChild(n3);
  n1->setRightChild(n4);

  n2->setRightChild(n5);

  n3->setLeftChild(n6);

  n6->setRightChild(n7);

  return root;
}

binarytree::Node* DataStructureUtils::createTree2() {
  int nodeIndex = 0;
  int numNodes = 13;
  binarytree::Node* root = new binarytree::Node(nodeIndex);

  queue<binarytree::Node*> nodesToChild = queue<binarytree::Node*>();
  nodesToChild.push(root);

  while (nodeIndex <= numNodes) {
    binarytree::Node* cur = nodesToChild.front();
    nodesToChild.pop();

    nodeIndex++;
    cur->setLeftChild(new binarytree::Node(nodeIndex));
    nodesToChild.push(cur->getLeftChild());

    nodeIndex++;
    cur->setRightChild(new binarytree::Node(nodeIndex));
    nodesToChild.push(cur->getRightChild());
  }

  return root;
}

binarytree::Node* DataStructureUtils::createTree3() {
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
binarytree::Node* DataStructureUtils::createTree4() {
  binarytree::Node* root = new binarytree::Node(0);

  return root;
}


binarytree::Node* DataStructureUtils::createTree5() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(0);
  binarytree::Node* n2 = new binarytree::Node(0);
  binarytree::Node* n3 = new binarytree::Node(0);
  binarytree::Node* n4 = new binarytree::Node(1);
  binarytree::Node* n5 = new binarytree::Node(1);
  binarytree::Node* n6 = new binarytree::Node(0);

  root->setLeftChild(n1);
  root->setRightChild(n2);

  n1->setLeftChild(n3);
  n1->setRightChild(n4);

  n2->setLeftChild(n5);
  n2->setRightChild(n6);

  return root;
}

binarytree::Node* DataStructureUtils::createTree6() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(0);
  binarytree::Node* n2 = new binarytree::Node(0);
  binarytree::Node* n3 = new binarytree::Node(1);
  binarytree::Node* n4 = new binarytree::Node(0);
  binarytree::Node* n5 = new binarytree::Node(0);
  binarytree::Node* n6 = new binarytree::Node(1);

  root->setLeftChild(n1);
  root->setRightChild(n2);

  n1->setLeftChild(n3);
  n1->setRightChild(n4);

  n2->setLeftChild(n5);
  n2->setRightChild(n6);

  return root;
}

binarytree::Node* DataStructureUtils::createTree7() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n3 = new binarytree::Node(3);

  root->setRightChild(n1);

  n1->setLeftChild(n2);
  n1->setRightChild(n3);

  return root;
}

binarytree::Node* DataStructureUtils::createTree8() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(-1);
  binarytree::Node* n3 = new binarytree::Node(3);

  root->setRightChild(n1);

  n1->setLeftChild(n2);
  n1->setRightChild(n3);

  return root;
}

binarytree::Node* DataStructureUtils::createTree9() {
  binarytree::Node* root = new binarytree::Node(0);
  binarytree::Node* n1 = new binarytree::Node(-1);
  binarytree::Node* n2 = new binarytree::Node(-2);
  binarytree::Node* n3 = new binarytree::Node(3);

  root->setLeftChild(n1);

  n1->setLeftChild(n2);
  n1->setRightChild(n3);

  return root;
}

binarytree::Node* DataStructureUtils::createTree10() {
  binarytree::Node* root = new binarytree::Node(10);
  binarytree::Node* n5 = new binarytree::Node(5);
  binarytree::Node* n15 = new binarytree::Node(15);
  binarytree::Node* n3 = new binarytree::Node(3);
  binarytree::Node* n7 = new binarytree::Node(7);
  binarytree::Node* n12 = new binarytree::Node(12);
  binarytree::Node* n17 = new binarytree::Node(17);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n4 = new binarytree::Node(4);
  binarytree::Node* n6 = new binarytree::Node(6);
  binarytree::Node* n8 = new binarytree::Node(8);
  binarytree::Node* n11 = new binarytree::Node(11);
  binarytree::Node* n13 = new binarytree::Node(13);

  root->setLeftChild(n5);
  root->setRightChild(n15);

  n5->setLeftChild(n3);
  n5->setRightChild(n7);

  n15->setLeftChild(n12);
  n15->setRightChild(n17);

  n3->setLeftChild(n1);
  n3->setRightChild(n4);

  n7->setLeftChild(n6);
  n7->setRightChild(n8);

  n12->setLeftChild(n11);
  n12->setRightChild(n13);

  return root;
}

binarytree::Node* DataStructureUtils::createTree11() {
  binarytree::Node* root = new binarytree::Node(8);
  binarytree::Node* n1 = new binarytree::Node(1);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n3 = new binarytree::Node(3);
  binarytree::Node* n4 = new binarytree::Node(4);
  binarytree::Node* n5 = new binarytree::Node(5);
  binarytree::Node* n6 = new binarytree::Node(6);
  binarytree::Node* n7 = new binarytree::Node(7);
  binarytree::Node* n8 = new binarytree::Node(8);
  binarytree::Node* n9 = new binarytree::Node(9);
  binarytree::Node* n10 = new binarytree::Node(10);
  binarytree::Node* n11 = new binarytree::Node(11);
  binarytree::Node* n12 = new binarytree::Node(12);
  binarytree::Node* n13 = new binarytree::Node(13);
  binarytree::Node* n14 = new binarytree::Node(14);
  binarytree::Node* n15 = new binarytree::Node(15);

  root->setLeftChild(n4);
  root->setRightChild(n12);

  n4->setLeftChild(n2);
  n4->setRightChild(n6);

  n2->setLeftChild(n1);
  n2->setRightChild(n3);

  n6->setLeftChild(n5);
  n6->setRightChild(n7);

  n12->setLeftChild(n10);
  n12->setRightChild(n14);

  n10->setLeftChild(n9);
  n10->setRightChild(n11);

  n14->setLeftChild(n13);
  n14->setRightChild(n15);


  return root;
}


binarytree::Node* DataStructureUtils::createTree12() {
  binarytree::Node* root = new binarytree::Node(15);
  binarytree::Node* n10 = new binarytree::Node(12);
  binarytree::Node* n14 = new binarytree::Node(17);
  binarytree::Node* n9 = new binarytree::Node(11);
  binarytree::Node* n3 = new binarytree::Node(13);

  root->setRightChild(n14);
  root->setLeftChild(n10);
  
  n10->setLeftChild(n9);
  n10->setRightChild(n3);

  return root;
}


binarytree::Node* DataStructureUtils::createTree13() {
  binarytree::Node* root = new binarytree::Node(8);
  binarytree::Node* n2 = new binarytree::Node(2);
  binarytree::Node* n4 = new binarytree::Node(4);
  binarytree::Node* n6 = new binarytree::Node(6);
  binarytree::Node* n10 = new binarytree::Node(10);
  binarytree::Node* n12 = new binarytree::Node(12);
  binarytree::Node* n14 = new binarytree::Node(14);

  root->setLeftChild(n4);
  root->setRightChild(n12);

  n4->setLeftChild(n2);
  n4->setRightChild(n6);

  n12->setLeftChild(n10);
  n12->setRightChild(n14);

  return root;
}

//A simple vector print for data testing
string com::DataStructureUtils::toString(const vector<int> &values) {
  string returnString = "{";

  for (int i = 0; i < values.size(); ++i) {
    returnString += to_string(values[i]);
    if (i < values.size() - 1) {
      returnString += ", ";
    }
  }
  returnString += "}";

  return returnString;
}

//A simple vector print for data testing
string com::DataStructureUtils::toString(const vector<char> &values) {
  string returnString = "{";

  for (int i = 0; i < values.size(); ++i) {
    returnString += values[i];
    if (i < values.size() - 1) {
      returnString += ", ";
    }
  }
  returnString += "}";

  return returnString;
}

//Algorithm adapted from: https://stackoverflow.com/questions/801740/c-how-to-draw-a-binary-tree-to-the-console
string DataStructureUtils::toString(binarytree::Node* root) {
  int depth = root->getHeight();

  char buf[1024];
  int last_lvl = 0;
  int offset = (1 << depth) - 1;

  // using a queue means we perform a breadth first iteration through the tree
  std::list<NodeDepth> q;

  q.push_back(NodeDepth(root, last_lvl));

  string returnString = "";

  while (q.size())
  {
    const NodeDepth &nd = *q.begin();

    // moving to a new level in the tree, output a new line and calculate new offset
    if (last_lvl != nd.lvl)
    {
      returnString += "\n";

      last_lvl = nd.lvl;
      offset = (1 << (depth - nd.lvl)) - 1;
    }

    // output <offset><data><offset>
    string strBuffer = "";
    if (nd.n)
      sprintf_s(buf, " %*s%d%*s", offset, " ", nd.n->getValue(), offset, " ");
    else
      sprintf_s(buf, " %*s", offset << 1, " ");
    returnString += buf;

    if (nd.n)
    {
      q.push_back(NodeDepth(nd.n->getLeftChild(), last_lvl + 1));
      q.push_back(NodeDepth(nd.n->getRightChild(), last_lvl + 1));
    }

    q.pop_front();
  }
  returnString += "\n";

  return returnString;
}
