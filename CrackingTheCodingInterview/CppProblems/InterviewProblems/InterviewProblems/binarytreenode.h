#ifndef COM_BINARYTREENODE_H_
#define COM_BINARYTREENODE_H_

#include <iostream>
#include <string>

//-----------------------------------------------------------------------------

namespace com
{
  class BinaryTreeNode {

    //A class to help print out trees in the console
    struct NodeDepth
    {
      BinaryTreeNode* n;
      int lvl;
      NodeDepth(BinaryTreeNode* n_, int lvl_) : n(n_), lvl(lvl_) {}
    };

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
    std::string static toString(BinaryTreeNode* root);

  private:

    std::string spacesPerTreeDepth(int depth, int height) const;

  };
}

#endif