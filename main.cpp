#include<iostream>
#include"BinaryTree.h"
#include"BST.h"
#include"Sort.h"
using namespace std ;
void TreeTest(void);
void Print(int &Data);

int main()
{

 	int Arr[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
    cout<<"MERG_SORT ASCENDING:: \n";
 	Sort<int>::MergSort(Arr ,12, SortingType_t::ASCENDING );
 	for( int i : Arr)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;
    int Arr2[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
    cout<<"MERG_SORT DESCENDING:: \n";
 	Sort<int>::MergSort(Arr2 ,12, SortingType_t::DESCENDING );
 	for( int i : Arr2)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;

 }

void Print(int &Data)
{
    cout<<Data<<"\t";
}
/* using namespace DSA::DS::BINARY_TREE::BST; */
void TreeTest(void)
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