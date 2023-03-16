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
BST<int> B;
    B.Insert(100);
    B.Insert(70);
    B.Insert(50);
    B.Insert(80);
    B.Insert(130);
    B.Insert(110);
    B.Insert(140);
    B.Insert(120);
    B.Insert(115);
    B.Insert(125);
    B.Insert(75);
    B.Insert(71);
    B.Insert(77);
    B.InOrder(Print);
    std::cout<<"\n";
    B.Delete(110);
    B.InOrder(Print);
    std::cout<<"\n";
    B.Delete(80);
    B.InOrder(Print);
    std::cout<<"\n";
    B.Delete(130);
    B.InOrder(Print);
    std::cout<<"\n";

    cout<<"\nSize is : "<<B.GetSize()<<"\n";


}
