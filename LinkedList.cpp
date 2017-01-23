/*
@Author: fangkun
@Date: 2016/11/17
@Function: LinkedList implementation
@implementation: 
@Test platform: Visual Studio 2015
@Test results:
@Test suggestions:
*/
#include "Linkedlist.h"
#include "CommonAPI.h"
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void InitializeListNode(ListNode* pstListNode)
{
    NULL_PTR_LOG_VOID(pstListNode);
    pstListNode->left = NULL;
    pstListNode->right = NULL;
    pstListNode->value = NULL_INT;
    return;
}

/*Constructor
    Allocs an array of ListNodes to store elements of a given size
    Initializes ptrs to NULL, values to 65535
*/
LinkedList::LinkedList()
{
    count = 0;
    begin = new ListNode();
    end = new ListNode();
    InitializeListNode(begin);
    InitializeListNode(end);
    begin->right = end;
    end->left = begin;
}
/*Destroyer
    Deallocates dynamic memory
*/
LinkedList::~LinkedList()
{
    ListNode *pIter = begin;
    while (1)
    {
        if (pIter->right == NULL)
        {
            ListNode *pTemp = pIter;
            delete pTemp;
            break;
        }
        ListNode *pTemp = pIter;
        pIter = pIter->right;
        delete pTemp;
    }
}
/*Finder
    Find a specific element and returns the ptr of first occurence
    Time = O(n)
*/
ListNode* LinkedList::Find(int x)
{
    ListNode *pIter = begin;
    while (1)
    {
        NULL_PTR_LOG_NULL(pIter);
        if (pIter->value == x)
        {
            break;
        }
        if (pIter == end)
        {
            pIter = NULL;
            break;
        }
        pIter = pIter->right;
    }
    return pIter;
}
/*Counter
    Returns the number of occurences of a given element
    Time = O(n)
*/
unsigned int LinkedList::Count(int x)
{
    unsigned int count = 0;
    ListNode *pIter = begin;
    while (1)
    {
        NULL_PTR_LOG_INT(pIter);
        if (pIter->value == x)
        {
            count++;
        }
        if (pIter == end)
        {
            break;
        }
        pIter = pIter->right;
    }
    return count;
}
/*Adder
    Adds an element of int x to the end of current linkedlist
    Time = O(1)
*/
bool LinkedList::InsertAtTail(int x)
{
    NULL_PTR_LOG(end->left);
    ListNode *pIter = end->left;
    ListNode *pstTempNode = new ListNode();
    InitializeListNode(pstTempNode);
    pstTempNode->value = x;
    pstTempNode->left = pIter;
    pIter->right = pstTempNode;
    pstTempNode->right = end;
    end->left = pstTempNode;
    count++;
    return true;
}
/*Inserter
    Inserts an element of int x after a given node
    Time = O(1)
*/
bool LinkedList::InsertAfter(int x, ListNode* pstListNode)
{
    NULL_PTR_LOG(pstListNode);
    if (end == pstListNode)
    {
        LOG_COMMON("Cannot insert outside the bounds!")
        return false;
    }
    ListNode *pstTempNode = new ListNode();
    InitializeListNode(pstTempNode);
    pstTempNode->value = x;
    ListNode *pstTempRight = pstListNode->right;
    pstListNode->right = pstTempNode;
    pstTempRight->left = pstTempNode;
    pstTempNode->left = pstListNode;
    pstTempNode->right = pstTempRight;
    return true;
}
/*Inserter
    Inserts an element of int x before a given node
    Time = O(1)
*/
bool LinkedList::InsertBefore(int x, ListNode* pstListNode)
{
    NULL_PTR_LOG(pstListNode);
    if (begin == pstListNode)
    {
        LOG_COMMON("Cannot insert outside the bounds!")
        return false;
    }
    ListNode *pstTempNode = new ListNode();
    InitializeListNode(pstTempNode);
    pstTempNode->value = x;
    ListNode *pstTempLeft = pstListNode->left;
    pstListNode->left = pstTempNode;
    pstTempLeft->right = pstTempNode;
    pstTempNode->left = pstTempLeft;
    pstTempNode->right = pstListNode;
    return true;
}
/*Deleter
    Deletes an element of int x to the current linkedlist
    if the element does not exist, return false;
    Time = O(n)
*/
bool LinkedList::DeleteElement(int x)
{
    ListNode *pstIter = begin;
    NULL_PTR_LOG(begin);
    NULL_PTR_LOG(end);
    pstIter = pstIter->right;
    while (1)
    {
        NULL_PTR_LOG(pstIter);
        if (pstIter->value == x)
        {
            pstIter->left->right = pstIter->right;
            pstIter->right->left = pstIter->left;
            delete (pstIter);
            count--;
            LOG_COMMON("element [%d] successfully deleted!", x);
            return true;
        }
        pstIter = pstIter->right;
        if (pstIter == end)
        {
            break;
        }
    }
    LOG_COMMON("element [%d] not found", x);
    return false;
}

/*Deleter
    Deletes a given Node ptr
    if the ptr is invalid, return false;
    Time = O(1)
*/
bool LinkedList::DeleteNode(ListNode* pstListNode)
{
    NULL_PTR_LOG(pstListNode);
    ListNode *pstTempLeft = pstListNode->left;
    ListNode *pstTempRight = pstListNode->right;
    NULL_PTR_LOG(pstTempLeft);
    NULL_PTR_LOG(pstTempRight);
    if ((begin == pstListNode) || (end == pstListNode))
    {
        LOG_COMMON("Cannot delete bounds!");      
        return false;
    }
    delete pstListNode;
    pstTempLeft->right = pstTempRight;
    pstTempRight->left = pstTempLeft;
    count--;
    return true;
}
/*Printer
    Prints the list in linked way
*/
void LinkedList::Print()
{
    ListNode *pstIter = begin;
    NULL_PTR_LOG_VOID(pstIter);
    pstIter = pstIter->right;
    if (count == 0)
    {
        cout<<"No Element! exit 0"<<endl;
        return;
    }

    LOG_COMMON("Printing List...");
    cout<<endl;
    while (1)
    {   
        NULL_PTR_LOG_VOID(pstIter);
        if (pstIter->right == end)
        {
            printf("[%d]\n", pstIter->value);
            cout<<endl;
            LOG_COMMON("Print success! exit 1");
            return;
        }
        printf("[%d]--", pstIter->value);
        pstIter = pstIter->right;
    }
    return;
}
/*Max
    Find the max element of first occurence
    Time = O(n)
*/
ListNode* LinkedList::FindMax()
{
    ListNode* out  = begin;
    NULL_PTR_LOG_NULL(out);
    out = out->right;
    NULL_PTR_LOG_NULL(out);
    ListNode* temp = out;
    if (count == 0)
    {
        LOG_COMMON("No max with 0 element");
        return NULL;
    }
    while (1)
    {
        NULL_PTR_LOG_NULL(temp);
        if (temp->right == end)
        {
            if (temp->value > out->value)
            {
                out = temp;
            }
            return out;
        }
        if (temp->value > out->value)
        {
            out = temp;
        }
        temp = temp->right;
    }
    return out;
}
/*Min
    Find the min element of first occurence
    Time = O(n)
*/
ListNode* LinkedList::FindMin()
{
    ListNode* out  = begin;
    NULL_PTR_LOG_NULL(out);
    out = out->right;
    NULL_PTR_LOG_NULL(out);
    ListNode* temp = out;
    if (count == 0)
    {
        LOG_COMMON("No min with 0 element");
        return NULL;
    }
    while (1)
    {
        NULL_PTR_LOG_NULL(temp);
        if (temp->right == end)
        {
            if (temp->value < out->value)
            {
                out = temp;
            }
            return out;
        }
        if (temp->value < out->value)
        {
            out = temp;
        }
        temp = temp->right;
    }
    return out;
}

/*Copy
    Copy all elements to destination List
    Time = O(n)
*/
void LinkedList::Copy(LinkedList *pDestList)
{
    ListNode *pstIter = begin;
    NULL_PTR_LOG_VOID(pstIter);
    pstIter = pstIter->right;
    if (count == 0)
    {
        return;
    }
    while (1)
    {
        NULL_PTR_LOG_VOID(pstIter);
        g_LogLevel = LOG_OFF;
        if (pstIter->right == end)
        {
            pDestList->InsertAtTail(pstIter->value);
            return;
        }
        pDestList->InsertAtTail(pstIter->value);
        pstIter = pstIter->right;
    }
    g_LogLevel = LOG_ON;
    return;
}
/*SortDown
    Sort from top to bot
    Time = O(n^2)
*/
void LinkedList::SortDown()
{
    ListNode *pstIter = begin;
    LinkedList tempList;
    Copy(&tempList);
    pstIter = pstIter->right;
    while (tempList.count != 0)
    {
        NULL_PTR_LOG_VOID(pstIter);
        ListNode *tempMax = tempList.FindMax();
        pstIter->value = tempMax->value;
        pstIter = pstIter->right;
        g_LogLevel = LOG_OFF;
        tempList.DeleteElement(tempMax->value);      
    }
    g_LogLevel = LOG_ON;
    return;
}
/*SortUp
    Sort from bot to top
    Time = O(n^2)
*/
void LinkedList::SortUp()
{
    ListNode *pstIter = begin;
    LinkedList tempList;
    Copy(&tempList);
    pstIter = pstIter->right;
    while (tempList.count != 0)
    {
        NULL_PTR_LOG_VOID(pstIter);
        ListNode *tempMin = tempList.FindMin();
        pstIter->value = tempMin->value;
        pstIter = pstIter->right;
        g_LogLevel = LOG_OFF;
        tempList.DeleteElement(tempMin->value);
    }
    g_LogLevel = LOG_ON;
    return;
}
