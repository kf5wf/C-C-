/*
@Author: fangkun
@Date: 2016/11/17
@Function: LinkedList implementation
@implementation: 
@Test platform: Visual Studio 2015
@Test results:
@Test suggestions:
*/
#include "BinaryTree.h"
#include "CommonAPI.h"
#include "BalancedTree.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
/*Constructor
    Allocs an array of ListNodes to store elements of a given size
    Initializes ptrs to NULL, values to 65535
*/
BalancedTree::BalancedTree()
{
}
/*Destroyer
    Deallocates dynamic memory
*/
BalancedTree::BalancedTree()
{
}

bool BalancedTree::AddBalNode(int x, TreeNode* pstTreeNode)
{
    if (NULL == pstTreeNode)
    {
        return false;
    }
    //RootÎª¿ÕµÄ³¡¾°
    if (NULL_INT == pstTreeNode->value)
    {
        pstTreeNode->value = x;
        return true;
    }
    if (x == pstTreeNode->value)
    {
        LOG_COMMON("Element [%d] already exists!");
        return false;
    }
    if (x < pstTreeNode->value)
    {
        if (NULL == pstTreeNode->pstLeftChild)
        {
            TreeNode* pstTemp = new TreeNode();
            InitializeTreeNode(pstTemp);
            pstTemp->value = x;
            pstTemp->pstParent = pstTreeNode;
            pstTemp->ulDepth = pstTreeNode->ulDepth + 1;
            count++;
            if (AbsDiff(pstTemp->ulDepth, depth) > 1)
            {
                if (pstTreeNode == pstTreeNode->pstParent->pstLeftChild)
                {
                    RotateClockWise(pstTreeNode->pstParent);
                }
                else
                {
                    RotateAntiClockWise(pstTreeNode->pstParent);
                }
                UpdateDepth();
                return true;
            }
            else
            {
                ((pstTemp->ulDepth) > depth) ? (depth = (pstTemp->ulDepth)) : (depth = depth);
                return true;
            }
        }
        else
        {
            return AddBalNode(x, pstTreeNode->pstLeftChild);
        }
    }
    else
    {
        if (NULL == pstTreeNode->pstRightChild)
        {
            TreeNode* pstTemp = new TreeNode();
            InitializeTreeNode(pstTemp);
            pstTemp->value = x;
            pstTemp->pstParent = pstTreeNode;
            pstTemp->ulDepth = pstTreeNode->ulDepth + 1;
            count++;
            if (AbsDiff(pstTemp->ulDepth, depth) > 1)
            {
                if (pstTreeNode == pstTreeNode->pstParent->pstLeftChild)
                {
                    RotateClockWise(pstTreeNode->pstParent);
                }
                else
                {
                    RotateAntiClockWise(pstTreeNode->pstParent);
                }
                UpdateDepth();
                return true;
            }
            else
            {
                ((pstTemp->ulDepth) > depth) ? (depth = (pstTemp->ulDepth)) : (depth = depth);
                return true;
            }
        }
        else
        {
            return AddBalNode(x, pstTreeNode->pstRightChild);
        }
    }
}
bool BalancedTree::DeleteBalNode(int x)
{
    
}
int BalancedTree::GetMaxNode()
{
    
}
int BalancedTree::GetMinNode()
{
    
}
void BalancedTree::BalanceTree()
{
    
}

void BalancedTree::RotateClockWise(TreeNode* pstTreeNode)
{
    
}
void BalancedTree::RotateAntiClockWise(TreeNode* pstTreeNode)
{
    
}
            