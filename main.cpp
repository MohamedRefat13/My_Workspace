#include<iostream>
#include"Tree/BinaryTree.h"
#include"Tree/BST.h"
#include"SortinngAlgorithms/Sort.h"
using namespace std ;
void TreeTest(void);
void SortTest(void);
void Print(int &Data);

int main()
{
   cout<<"SORTING TEST\n";
   SortTest();
  /*  cout<<"TREE TEST\n";
   TreeTest(); */

}

void SortTest(void)
{
   int Arr[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
   cout<<"Quick_Sort ASCENDING:: \n";
   Sort<int>::QuickSort(Arr , 12 );
 	for( int i : Arr)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;
   int Arr2[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
   cout<<"QuickSort DESCENDING:: \n";
 	Sort<int>::QuickSort(Arr2 ,12, SortingType_t::DESCENDING );
 	for( int i : Arr2)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;

   int Arr21[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
   cout<<"Quick_Sort_OLD_Virsion ASCENDING:: \n";
   Sort<int>::QuickSort_v1(Arr21 , 12 ,SortingType_t::ASCENDING  );
 	for( int i : Arr21)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;
   int Arr22[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
   cout<<"Quick_Sort_OLD_Virsion DESCENDING:: \n";
 	Sort<int>::QuickSort_v1(Arr22 ,12, SortingType_t::DESCENDING );
 	for( int i : Arr22)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;

   uint32_t Arr3[]   = {1,5,2,5,2,0,9,4,7,10,8,9};
   cout<<"Merg_Sort ASCENDING:: \n";
   Sort<uint32_t>::MergSort(Arr3 ,12, SortingType_t::ASCENDING );
 	for( uint32_t i : Arr3)
 	{
 		cout<<i<<"\t";
 	}
 	cout<<"End"<<endl;
    int Arr4[]   = {1,5,2,5,2,0,9,4,7,10,8,-9};
    cout<<"Merg_Sort DESCENDING:: \n";
 	Sort<int>::MergSort(Arr4 ,12, SortingType_t::DESCENDING );
 	for( int i : Arr4)
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