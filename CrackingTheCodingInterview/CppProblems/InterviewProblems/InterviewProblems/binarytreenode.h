#ifndef COM_BINARYTREENODE_H_
#define COM_BINARYTREENODE_H_

//-----------------------------------------------------------------------------

namespace com
{
  class BinaryTreeNode {

  public:
    int data;
    BinaryTreeNode* leftChild;
    BinaryTreeNode* rightChild;

    BinaryTreeNode();
    BinaryTreeNode(int data);
    ~BinaryTreeNode();

    void setLeftChild(BinaryTreeNode* node);
    void setRightChild(BinaryTreeNode* node);
    BinaryTreeNode* getLeftChild();
    BinaryTreeNode* getRightChild();
    int getValue() const;
    bool operator==(const BinaryTreeNode &node);

  };
}

#endif