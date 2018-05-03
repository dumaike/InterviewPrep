#ifndef COM_BINARYTREENODE_H_
#define COM_BINARYTREENODE_H_

#include <iostream>
#include <string>

//-----------------------------------------------------------------------------

namespace com
{
  class BinaryTreeNode {
    int data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;

  public:

    BinaryTreeNode();
    BinaryTreeNode(int data);
    ~BinaryTreeNode();

    void setLeftChild(BinaryTreeNode* node);
    void setRightChild(BinaryTreeNode* node);
    BinaryTreeNode* getLeftChild() const;
    BinaryTreeNode* getRightChild() const;
    int getValue() const;
    int getHeight() const;
    bool operator==(const BinaryTreeNode &node) const;
    std::string toString() const;

  private:

    std::string spacesPerTreeDepth(int depth, int height) const;

  };
}

#endif