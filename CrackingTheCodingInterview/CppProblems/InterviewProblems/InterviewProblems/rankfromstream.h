#ifndef SORTINGANDSEARCHING_RANKFROMSTREAM_H_
#define SORTINGANDSEARCHING_RANKFROMSTREAM_H_

#include <map>

#include "testableproblem.h"
#include "binarytreenode.h"

namespace sortingandsearching{

  //Chapter 10 Question 9
  class RankFromStream: public com::TestableProblem {

    class StreamNode: public com::binarytree::Node {

    public:

      int leftChildrenCount;

      StreamNode(int x) : Node(x) {
        leftChildrenCount = 0;
      }

    };

    //The root of the bst where streamed nodes are stored
    com::binarytree::Node* bstRoot;
    std::map<int, com::binarytree::Node*> nodeMap = std::map<int, com::binarytree::Node*>();

    void insertIntoTree(com::binarytree::Node* root, int x);

    void singleTest();

    void track(int x);

    int getRankOfNumber(int x);
    int getRankOfNumber(StreamNode* curNode, StreamNode* prevNode);

    void resetStream();

    public:

    void runTestCases();
  };
}

#endif
