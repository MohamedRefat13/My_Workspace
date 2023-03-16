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
    int parent = 0 ; 
    Tree.Insert(9);
    Tree.Insert(12);
    Tree.Insert(7);
    Tree.Insert(9);
    Tree.Insert(14);
    Tree.PreOrder(Print); 
    cout<<"\n";
    if(Tree.GetParent(9 , parent )==Found)
    {
        cout<<parent<<"\n";
    }
    else
    {
        cout<<"Not_Found\n";
    }
    cout<<"Size is : "<<Tree.GetSize()<<"\n";

}
