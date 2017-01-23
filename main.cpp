/*
@Author: fangkun
@Date: 2016/11/17
@Function:  test
@implementation: 
@Test platform: Visual Studio 2015
@Test results:
@Test suggestions:
*/

#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "LinkedList.h"
#include "BinaryTree.h"
#include "CommonAPI.h"


using namespace std;

int main()
{
    fstream file;
    file.open("input.txt");
    int temp = NULL_INT;
    file.close();
    LinkedList list_one;
    BinaryTree tree_one;
    file.open("input.txt");
    while (!file.eof())
    {
        file >> temp;
        list_one.InsertAtTail(temp);
        tree_one.AddElement(temp);
    }
    file.close();
    list_one.Print();
    list_one.DeleteElement(1);
    //list_one.print();
    list_one.DeleteElement(214);
    list_one.DeleteElement(4);
    list_one.SortDown();
    list_one.Print();
    list_one.SortUp();
    list_one.Print();
    list_one.InsertAtTail(232);
    list_one.InsertAtTail(12);
    list_one.Print();
    list_one.SortDown();
    list_one.Print();
    list_one.SortUp();
    list_one.Print();
    list_one.InsertAtTail(12);
    list_one.Print();
    tree_one.AddElement(88);
    //tree_one.DeleteSubTree(tree_one.pstRoot->pstRightChild);
    //tree_one.DeleteTreeNode(tree_one.pstRoot->pstLeftChild->pstRightChild);
    //tree_one.DeleteElement(12);
    tree_one.SetRoot(tree_one.GetElement(32));
    bool bIsBalanced = tree_one.IsBalanced();
    return 0;
}
