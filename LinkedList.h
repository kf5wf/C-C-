/*
@Author: fangkun
@Date: 2016/11/17
@Function: Big number basic operation in Array
@implementation: +,-,*,/,gcd,lcm,prime,power
@Test platform: Visual Studio 2015
@Test results:
@Test suggestions:
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "CommonAPI.h"
using namespace std;

typedef struct ListNode
{
    ListNode*   left;
    ListNode*   right;
    int         value;
}ListNode;
void InitializeListNode(ListNode* pstListNode);
class LinkedList
{
public:
    /*Field Members*/
    ListNode*       begin;
    ListNode*       end;
    int             count;

    /*Constructor*/
    LinkedList();
    /*Destructor*/
    ~LinkedList();

    /*Func Members*/
    ListNode*           Find(int x);    
    ListNode*           FindMax();
    ListNode*           FindMin();
    unsigned int        Count(int x);
    bool                InsertAtTail(int x);
    bool                InsertAfter(int x, ListNode* pstListNode);
    bool                InsertBefore(int x, ListNode* pstListNode);
    bool                DeleteElement(int x);
    bool                DeleteNode(ListNode* pstListNode);
    void                Copy(LinkedList *pDestList);
    void                SortDown();
    void                SortUp();    
    void                Print();    
};
#endif
