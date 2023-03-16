#include <iostream>
#include"BinaryTree.h"
#include "utils.h"

/* using namespace DSA::DS::BINARY_TREE; */
template<typename T>
Binary_Tree<T> :: Binary_Tree() : pRoot(nullptr) , _Size(0) , _Height(0) { }
template<typename T>
void Binary_Tree<T> :: InOrder(void (*pFun)(T &Data))
{
    recur_InOrder(pRoot , pFun);
}
template<typename T>
void Binary_Tree<T> :: PreOrder(void (*pFun)(T &Data))
{
    recur_PreOrder(pRoot , pFun);
}
template<typename T>
void Binary_Tree<T> :: PostOrder(void (*pFun)(T &Data))
{
    recur_PostOrder(pRoot , pFun);
}
template<typename T>
bool  Binary_Tree<T> ::  IsEmpty()const
{
    return _Size ? false : true ;
}
template<typename T>
uint16_t  Binary_Tree<T> :: GetSize() const
{
    return _Size ;
}
template<typename T>
uint16_t  Binary_Tree<T> :: GetHeight()const
{
    return 0 ;
}

template<typename T>
void Binary_Tree<T> :: recur_InOrder(Node_t<T> *pSubRoot,  void(*pFun)(T &Data))
{
    if( pSubRoot == nullptr )
    {
        return ;
    }
    recur_InOrder(pSubRoot->pLeft  , pFun);
    pFun(pSubRoot->Data);
    recur_InOrder(pSubRoot->pRight , pFun);
}
template<typename T>
void Binary_Tree<T> :: recur_PreOrder(Node_t<T> *pSubRoot,  void(*pFun)(T &Data))
{
    if( pSubRoot == nullptr )
    {
        return ;
    }
    pFun(pSubRoot->Data);
    recur_PreOrder(pSubRoot->pLeft  , pFun);
    recur_PreOrder(pSubRoot->pRight , pFun);
}
template<typename T>
void Binary_Tree<T> :: recur_PostOrder(Node_t<T> *pSubRoot,  void(*pFun)(T &Data))
{
    if( pSubRoot == nullptr )
    {
        return ;
    }
    recur_PostOrder(pSubRoot->pLeft  , pFun);
    recur_PostOrder(pSubRoot->pRight , pFun);
    pFun(pSubRoot->Data);
}

INSTANTIATE_CLASS_TEMPLATES(Binary_Tree);
