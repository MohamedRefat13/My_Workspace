#include<iostream>
#include"BinaryTree.h"
#include"BST.h"
using namespace std ;
void Print(int &Data)
{
    cout<<Data<<"\t";
}
/* using namespace DSA::DS::BINARY_TREE::BST; */

int main()
{
    BST<int> Tree ;
    Tree.Insert(9);
    Tree.Insert(12);
    Tree.Insert(7);
    Tree.Insert(9);
    Tree.Insert(14);
    Tree.PreOrder(Print); 
    cout<<"\n";
    if(Tree.Search(14)==Found)
    {
        cout<<"Found";
    }
    else
    {
        cout<<"Not_Found";
    }

}
