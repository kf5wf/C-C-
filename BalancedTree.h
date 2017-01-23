#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H
#include "CommonAPI.h"
#include "BianryTree.h"
using namespace std;
class BalancedTree : public BinaryTree
{
public:
    BalancedTree() : BinaryTree();
    ~BalancedTree();
    
    bool            AddBalNode(int x);
    bool            DeleteBalNode(int x);
    int             GetMaxNode();
    int             GetMinNode();
    void            BalanceTree();
    void            RotateClockWise(TreeNode* pstTreeNode);
    void            RotateAntiClockWise(TreeNode* pstTreeNode);
};
#endif
