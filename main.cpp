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
    Tree.Insert(30);
    Tree.Insert(15);
    Tree.Insert(45);
    Tree.Insert(7);
    Tree.Insert(17);
    Tree.Insert(69);
    Tree.Insert(80);
    Tree.InOrder(Print); 
    cout<<"\n";
    cout<<"Done1\n";
    if( Tree.Delete(45) == Success){
        
        Tree.InOrder(Print); 
    }else{
        cout<<"NotFound\n";
    }
    cout<<"\nSize is : "<<Tree.GetSize()<<"\n";


}
