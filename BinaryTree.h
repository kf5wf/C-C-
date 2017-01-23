/*
@Author: fangkun
@Date: 2016/11/17
@Function: Big number basic operation in Array
@implementation: +,-,*,/,gcd,lcm,prime,power
@Test platform: Visual Studio 2015
@Test results:
@Test suggestions:
*/

#include "CommonAPI.h"
#include <vector>

#ifndef BINARYTREE_H
#define BINARYTREE_H
using namespace std;
typedef struct TreeNode
{
    TreeNode*       pstParent;
    TreeNode*       pstLeftChild;
    TreeNode*       pstRightChild;
    int             value;
    unsigned int    ulDepth;
}TreeNode;
void InitializeTreeNode(TreeNode* pstTreeNode);
void PushToStackByValue(vector<int> &destContainer, TreeNode* pstTreeNode, int exception);
void PushToStackByDepth(vector<unsigned int> &destContainer, TreeNode* pstTreeNode);
void PushToStackByDepthForLeaf(vector<unsigned int> &destContainer, TreeNode* pstTreeNode);
bool IsRoot(TreeNode* pstTreeNode);
bool IsLeaf(TreeNode* pstTreeNode);
class BinaryTree
{
    /*Field Members*/
protected:
    TreeNode*       pstRoot;
    unsigned int    count;
    unsigned int    depth;
    
public:
    /*Constructor*/
    BinaryTree();
    /*Destructor*/
    ~BinaryTree();

    /*Func Members*/
    TreeNode*       GetRoot();
    TreeNode*       FindMax();
    TreeNode*       FindMin();
    TreeNode*       GetElement(int x);
    unsigned int    GetDepth(int x);    
    void            UpdateDepth();
    void            SetRoot(TreeNode* pstTreeNode);
    unsigned int    GetMaxDepth(TreeNode* pstTreeNode);
    unsigned int    GetMaxDepthNum(TreeNode* pstTreeNode);
    void            AddElement(int x);
    void            AddTreeNode(TreeNode* pstTreeNode);
    void            DeleteSubTree(TreeNode* pstSubTreeRoot);
    void            DeleteTreeNode(TreeNode* pstTreeNode);
    void            DeleteElement(int x);
    void            PrintTree();
    bool            HasNode(TreeNode* pstTreeNode);
    bool            IsBalanced();
};

#endif
