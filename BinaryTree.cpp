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
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

enum enLogSwitch g_LogLevel = LOG_ON;
void InitializeTreeNode(TreeNode* pstTreeNode)
{
    NULL_PTR_LOG_VOID(pstTreeNode);
    pstTreeNode->pstParent      = NULL;
    pstTreeNode->pstLeftChild   = NULL;
    pstTreeNode->pstRightChild  = NULL;
    pstTreeNode->value          = NULL_INT;
    pstTreeNode->ulDepth        = 0;
    return;
}
void PushToStackByValue(vector<int> &destContainer, TreeNode* pstTreeNode, int exception)
{
    if (NULL == pstTreeNode)
    {
        return;
    }
    if (exception != pstTreeNode->value)
    {
        destContainer.push_back(pstTreeNode->value);
    }
    if (IsLeaf(pstTreeNode))
    {
        return;
    }
    
    PushToStackByValue(destContainer, pstTreeNode->pstLeftChild, exception);
    PushToStackByValue(destContainer, pstTreeNode->pstRightChild, exception);
    return;
}
void PushToStackByDepth(vector<unsigned int> &destContainer, TreeNode* pstTreeNode)
{
    if (NULL == pstTreeNode)
    {
        return;
    }
    destContainer.push_back(pstTreeNode->ulDepth);
    if (IsLeaf(pstTreeNode))
    {
        return;
    }
    
    PushToStackByDepth(destContainer, pstTreeNode->pstLeftChild);
    PushToStackByDepth(destContainer, pstTreeNode->pstRightChild);
    return;
}
void PushToStackByDepthForLeaf(vector<unsigned int> &destContainer, TreeNode* pstTreeNode)
{
    if (NULL == pstTreeNode)
    {
        return;
    }
    if (IsLeaf(pstTreeNode))
    {
        destContainer.push_back(pstTreeNode->ulDepth);
        return;
    }
    PushToStackByDepthForLeaf(destContainer, pstTreeNode->pstLeftChild);
    PushToStackByDepthForLeaf(destContainer, pstTreeNode->pstRightChild);
    return;
}
bool IsRoot(TreeNode* pstTreeNode)
{
    NULL_PTR_LOG(pstTreeNode);
    if (NULL == pstTreeNode->pstParent)
    {
        return true;
    }
    return false;
}
bool IsLeaf(TreeNode* pstTreeNode)
{
    NULL_PTR_LOG(pstTreeNode);
    if ((NULL == pstTreeNode->pstLeftChild) && (NULL == pstTreeNode->pstRightChild))
    {
        return true;
    }
    return false;
}
/*Constructor
    Allocs an array of ListNodes to store elements of a given size
    Initializes ptrs to NULL, values to 65535
*/
BinaryTree::BinaryTree()
{
    TreeNode* pstTempRoot = new TreeNode();
    InitializeTreeNode(pstTempRoot);
    pstRoot = pstTempRoot;
    count   = 0;
    depth   = 0;
}
/*Destroyer
    Deallocates dynamic memory
*/
BinaryTree::~BinaryTree()
{
    TreeNode *pIter = pstRoot;
    DeleteTreeNode(pIter);   
}

/*Deleter
    Deletes a given Node ptr
    if the ptr is invalid, return false;
    Time = O(n)
*/


/*Root ptr
    Returns ptr to RootNode
    Time = O(1)
*/
TreeNode* BinaryTree::GetRoot()
{
    return pstRoot;
}

/*Max
    Find the max element of first occurence
    Time = O(log(n))
*/
TreeNode* BinaryTree::FindMax()
{
    TreeNode* out  = pstRoot;
    NULL_PTR_LOG_NULL(out);
    if (count == 0)
    {
        LOG_COMMON("No max with 0 element");
        return NULL;
    }
    while (1)
    {
        if (out->pstRightChild == NULL)
        {
            return out;
        }
        out = out->pstRightChild;
    }
    return out;
}
/*Min
    Find the min element of first occurence
    Time = O(log(n))
*/
TreeNode* BinaryTree::FindMin()
{
    TreeNode* out  = pstRoot;
    NULL_PTR_LOG_NULL(out);
    if (count == 0)
    {
        LOG_COMMON("No max with 0 element");
        return NULL;
    }
    while (1)
    {
        if (out->pstLeftChild == NULL)
        {
            return out;
        }
        out = out->pstLeftChild;
    }
    return out;
}
/*GetElement
    Returns the ptr to the Node of a given value
    Time = O(log(n))
*/
TreeNode* BinaryTree::GetElement(int x)
{
    TreeNode* out  = pstRoot;
    NULL_PTR_LOG_NULL(out);
    if (count == 0)
    {
        LOG_COMMON("No max with 0 element");
        return NULL;
    }
    while (1)
    {
        if (x == out->value)
        {
            return out;
        }
        if (out->value < x)
        {
            if ((NULL != out->pstRightChild) && (out = out->pstRightChild))
            {
                continue;
            }
            else
            {
                LOG_COMMON("Element [%d] not found!", x)
                return NULL;
            }
        }
        if (out->value > x)
        {
            if ((NULL != out->pstLeftChild) && (out = out->pstLeftChild))
            {
                continue;
            }
            else
            {
                LOG_COMMON("Element [%d] not found!", x)
                return NULL;
            }
        }
    }
    out = NULL;
    LOG_COMMON("Element [%d] not found!", x)
    return out;
}
/*GetDepth
    Returns the depth of the Node of a given value
    Time = O(log(n))
*/
unsigned int BinaryTree::GetDepth(int x)
{
    unsigned int    ulDepth         = 0;
    TreeNode*       pstTempNode     = pstRoot;
    
    NULL_PTR_LOG_INT(pstTempNode)
    ulDepth++;
    while (x != pstTempNode->value)
    {
        if (x > pstTempNode->value)
        {
            if (NULL != pstTempNode->pstRightChild)
            {
                pstTempNode = pstTempNode->pstRightChild;
            }
            else
            {
                LOG_COMMON("Element [%d] not found!", x)
                return 0;
            }
        }
        else
        {
            if (NULL != pstTempNode->pstLeftChild)
            {
                pstTempNode = pstTempNode->pstLeftChild;
            }
            else
            {
                LOG_COMMON("Element [%d] not found!", x)
                return 0;
            }
        }
    }
    ulDepth = pstTempNode->ulDepth;
    return ulDepth;
}
/*UpdateDepth
    Updates the depth of this tree
*/
void BinaryTree::UpdateDepth()
{
    depth = GetMaxDepth(pstRoot);
    return;
}
/*SetRoot
    Set current RootNode to a given Node
    Time = O(1)
*/
void BinaryTree::SetRoot(TreeNode* pstTreeNode)
{
    bool bHasNode = HasNode(pstTreeNode);
    int tempValue = 0;
    if (bHasNode)
    {
        //保存旧树所有值到数组变量，入参的值除外
        vector<int> Temp;
        PushToStackByValue(Temp, pstRoot, pstTreeNode->value);
        //源root节点及子节点内存释放
        tempValue = pstTreeNode->value;
        DeleteSubTree(pstRoot);
        pstRoot->value = tempValue;
        count   = 1;
        depth   = 1;
        pstRoot->ulDepth = 1;
        //重新添加数组变量中的值
        while (!Temp.empty())
        {
            AddElement(Temp.back());
            Temp.pop_back();
        }
    }
    else
    {
        LOG_COMMON("Input Node is not part of current Tree");
        return;
    }
}

unsigned int BinaryTree::GetMaxDepth(TreeNode* pstTreeNode)
{
    unsigned int ulDepth = 0;
    unsigned int ulDepthCount = 0;
    if (NULL == pstTreeNode)
    {
        return 0;
    }
    vector<unsigned int> Temp;
    PushToStackByDepth(Temp, pstTreeNode);
    while (!Temp.empty())
    {
        if (Temp.back() > ulDepth)
        {
            ulDepth = Temp.back();
            ulDepthCount = 1;
        }
        else if (Temp.back() == ulDepth)
        {
            ulDepthCount++;
        }
        else{}
        Temp.pop_back();
    }
    return ulDepth;
}
unsigned int BinaryTree::GetMaxDepthNum(TreeNode* pstTreeNode)
{
    unsigned int ulDepth = 0;
    unsigned int ulDepthCount = 0;
    if (NULL == pstTreeNode)
    {
        return 0;
    }
    vector<unsigned int> Temp;
    PushToStackByDepth(Temp, pstTreeNode);
    while (!Temp.empty())
    {
        if (Temp.back() > ulDepth)
        {
            ulDepth = Temp.back();
            ulDepthCount = 1;
        }
        else if (Temp.back() == ulDepth)
        {
            ulDepthCount++;
        }
        else{}
        Temp.pop_back();
    }
    return ulDepthCount;
}

/*AddElement
    Add a new element of given value to the tree
    Time = O(log(n))
*/
void BinaryTree::AddElement(int x)
{
    TreeNode*       pstTempNode = pstRoot;
    while (1)
    {
        if (pstTempNode->value == x)
        {
            LOG_COMMON("Element [%d] already exists!", x);
            return;
        }
        //Root为空场景
        if ((pstTempNode == pstRoot) && (NULL_INT == pstTempNode->value))
        {
            pstTempNode->value = x;
            depth = pstTempNode->ulDepth = 1;
            count++;
            return;
        }
        if (pstTempNode->value > x)
        {
            //当前左子节点为空，可以直接插入
            if ((NULL == pstTempNode->pstLeftChild))
            {
                TreeNode* pstTreeNode = new TreeNode();
                InitializeTreeNode(pstTreeNode);
                pstTreeNode->value = x;
                pstTreeNode->pstParent = pstTempNode;
                pstTempNode->pstLeftChild = pstTreeNode;
                pstTreeNode->ulDepth = pstTempNode->ulDepth + 1;
                if (depth < pstTreeNode->ulDepth)
                {
                    depth = pstTreeNode->ulDepth;
                }
                count++;
                return;
            }
            //当前左子节点不为空，需继续深入
            else
            {
                pstTempNode = pstTempNode->pstLeftChild;
                continue;
            }
        }
        else if (pstTempNode->value < x)
        {
            //当前右子节点为空，可以直接插入
            if ((NULL == pstTempNode->pstRightChild))
            {
                TreeNode* pstTreeNode = new TreeNode();
                InitializeTreeNode(pstTreeNode);
                pstTreeNode->value = x;
                pstTreeNode->pstParent = pstTempNode;
                pstTempNode->pstRightChild = pstTreeNode;
                pstTreeNode->ulDepth = pstTempNode->ulDepth + 1;
                if (depth < pstTreeNode->ulDepth)
                {
                    depth = pstTreeNode->ulDepth;
                }
                count++;
                return;
            }
            //当前右子节点不为空，需继续深入
            else
            {
                pstTempNode = pstTempNode->pstRightChild;
                continue;
            }
        }
    }
}

void BinaryTree::AddTreeNode(TreeNode* pstTreeNode)
{
    NULL_PTR_LOG_VOID(pstTreeNode);
    
    TreeNode*       pstTempNode = pstRoot;
    int             value       = pstTreeNode->value;
    //已存在该值的节点
    if (NULL != GetElement(pstTreeNode->value))
    {
        LOG_COMMON("TreeNode [%d] already exists!", pstTreeNode->value);
        return;
    }
    
    //添加节点
    while (1)
    {
        if (pstTempNode->value == value)
        {
            LOG_COMMON("TreeNode [%d] already exists!", value);
            return;
        }
        if (pstTempNode->value < value)
        {
            //当前左子节点为空，可以直接插入
            if ((NULL == pstTempNode->pstLeftChild))
            {
                pstTreeNode->pstParent = pstTempNode;
                pstTempNode->pstLeftChild = pstTreeNode;
                pstTreeNode->ulDepth = pstTempNode->ulDepth + 1;
                if (depth < pstTreeNode->ulDepth)
                {
                    depth = pstTreeNode->ulDepth;
                }
                return;
            }
            //当前左子节点不为空，需继续深入
            else
            {
                pstTempNode = pstTempNode->pstLeftChild;
                continue;
            }
        }
        else if (pstTempNode->value > value)
        {
            //当前右子节点为空，可以直接插入
            if ((NULL == pstTempNode->pstRightChild))
            {                
                pstTreeNode->pstParent = pstTempNode;
                pstTempNode->pstRightChild = pstTreeNode;
                pstTreeNode->ulDepth = pstTempNode->ulDepth + 1;
                if (depth < pstTreeNode->ulDepth)
                {
                    depth = pstTreeNode->ulDepth;
                }
                return;
            }
            //当前右子节点不为空，需继续深入
            else
            {
                pstTempNode = pstTempNode->pstRightChild;
                continue;
            }
        }
    }
    return;
}

void BinaryTree::DeleteSubTree(TreeNode* pstSubTreeRoot)
{
    if (pstSubTreeRoot == NULL)
    {
        return;
    }
    vector<unsigned int> MaxDepth;
    if (IsLeaf(pstSubTreeRoot))
    {
        if (NULL != pstSubTreeRoot->pstParent)
        {
            if (pstSubTreeRoot == pstSubTreeRoot->pstParent->pstLeftChild)
            {
                pstSubTreeRoot->pstParent->pstLeftChild = NULL;
            }
            else
            {
                pstSubTreeRoot->pstParent->pstRightChild = NULL;
            }
        }
        //是叶又是根，不释放内存，置空
        else
        {
            InitializeTreeNode(pstSubTreeRoot);
            count = 0;
            depth = 0;
            return;
        }
        //判断该节点是否为最大深度唯一节点，若是则需要更新深度
        unsigned int ulDepthAfter = GetMaxDepth(pstRoot);
        if (ulDepthAfter < depth)
        {
            depth = ulDepthAfter;
        }
        count--;
        delete pstSubTreeRoot;
        return;
    }
    (void)DeleteSubTree(pstSubTreeRoot->pstLeftChild);
    (void)DeleteSubTree(pstSubTreeRoot->pstRightChild);
    if (NULL != pstSubTreeRoot->pstParent)
    {
        if (pstSubTreeRoot == pstSubTreeRoot->pstParent->pstLeftChild)
        {
            pstSubTreeRoot->pstParent->pstLeftChild = NULL;
        }
        else
        {
            pstSubTreeRoot->pstParent->pstRightChild = NULL;
        }
    }
    //入参为根的情况，不释放内存，只需要置空
    else
    {
        InitializeTreeNode(pstSubTreeRoot);
        count = 0;
        depth = 0;
        return;
    }
    unsigned int ulDepthAfter = GetMaxDepth(pstRoot);
    if (ulDepthAfter < depth)
    {
        depth = ulDepthAfter;
    }
    count--;
    delete pstSubTreeRoot;
    return;
}
void BinaryTree::DeleteTreeNode(TreeNode* pstTreeNode)
{
    if (NULL == pstTreeNode)
    {
        return;
    }

    //入参为叶的情况
    if (IsLeaf(pstTreeNode))
    {
        if (NULL != pstTreeNode->pstParent)
        {
            if (pstTreeNode->value < pstTreeNode->pstParent->value)
            {
                pstTreeNode->pstParent->pstLeftChild = NULL;
            }
            else
            {
                pstTreeNode->pstParent->pstRightChild = NULL; 
            }
        
            count--;
            //TO do: 删除叶后是否更新深度
            if (0 == GetMaxDepthNum(pstRoot))
            {
                depth -- ;
            }
            delete pstTreeNode;
        }
        else
        {
            pstTreeNode->value = NULL_INT;
            count = 0;
            depth = 0;
            pstTreeNode->ulDepth = 0;
        }
        return;
    }
    //TO do: 入参为中间节点的情况，非平衡树不需要考虑平衡问题，让任意子节点替代自己即可
    //方案: 删掉该节点为根的子树，重新添加子树的元素
    vector<int> Temp;
    PushToStackByValue(Temp, pstTreeNode, pstTreeNode->value);
    DeleteSubTree(pstTreeNode);
    while (!Temp.empty())
    {
        AddElement(Temp.back());
        Temp.pop_back();
    }
    return;
}
/*Deleter
    Deletes an element of int x to the current linkedlist
    if the element does not exist, return false;
    Time = O(n)
*/
void BinaryTree::DeleteElement(int x)
{
    TreeNode* pstTarget = GetElement(x);
    if (NULL == pstTarget)
    {
        LOG_COMMON("Element [%d] does not exist!", x);
        return;
    }
    DeleteTreeNode(pstTarget);
    return;
}

void BinaryTree::PrintTree()
{
    return;
}


bool BinaryTree::HasNode(TreeNode* pstTreeNode)
{
    TreeNode* pstTemp = NULL;        
    pstTemp = GetElement(pstTreeNode->value);
    if (NULL != pstTemp)
    {
        return true;
    }
    return false;
}
bool BinaryTree::IsBalanced()
{
    vector<unsigned int> Temp;
    PushToStackByDepthForLeaf(Temp, pstRoot);
    unsigned int ulMax = Temp.back();
    while (!Temp.empty())
    {
        if (ulMax < Temp.back())
        {
            if (Temp.back() - ulMax > 1)
            {
                return false;
            }
            ulMax = Temp.back();
            Temp.pop_back();
            continue;
        }
        else if (ulMax >= Temp.back())
        {
            if (ulMax - Temp.back() > 1)
            {
                return false;
            }
            Temp.pop_back();
            continue;
        }
    }
    return true;
}
