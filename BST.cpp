#include <iostream>
#include"BST.h"
#include "utils.h"
/* using namespace DSA::DS::BINARY_TREE::BST;
namespace TreeSpace = DSA::DS::BINARY_TREE ; */

template<typename T>
Error_Code BST<T>::Insert(T Data)
{
    Error_Code Error_State = Helper_Insert(this->pRoot , Data );
    if(Error_State == Success)
    {
        this->_Size++;
    }
    return Error_State ; 
}
template<typename T>
Error_Code BST<T>::Helper_Insert(TreeNode_t<T> &pSubRoot , T Data)
{

    Error_Code Error_State = Success ; 
    if(pSubRoot == nullptr)
    {
        pSubRoot = new Node_t<T>(Data); 
        return Error_State ; 
    }else if ( Data > pSubRoot->Data)
    {
        Helper_Insert(pSubRoot->pRight , Data);

    }else if ( Data < pSubRoot->Data)
    {
        Helper_Insert(pSubRoot->pLeft , Data);
    }
    else
    {
        Error_State = Duplicated ; 
    }
    return Error_State ; 
}
template<typename T>
Error_Code BST<T>::Search(T Data)
{
    Error_Code Error_State = Not_Found ; 
    TreeNode_t<T> LocNode = Helper_Search(this->pRoot , Data );
    if(LocNode != nullptr )
    {
        Error_State = Found ; 
    }
    return Error_State ; 
}
template<typename T>
/* TreeSpace:: */ TreeNode_t<T> BST<T>:: Helper_Search(TreeNode_t<T> &pSubRoot , T Data)
{
    TreeNode_t<T> LocNode = nullptr ; 
    while (pSubRoot != nullptr)
    {
         if(pSubRoot->Data == Data )
         {
            LocNode =  pSubRoot ; 
            break;
 
         }else if(Data > pSubRoot->Data )
         {
            pSubRoot = pSubRoot->pRight ; 
         }
         else if(Data < pSubRoot->Data )
         {
            pSubRoot = pSubRoot->pRight ; 
         }
    }
    return LocNode ;
}
template<typename T>
Error_Code BST<T>::Delete(T Data)
{
    return Success ; 
}

template<typename T>
Error_Code BST<T>:: GetParent(T Data , T &Parent)
{
    Error_Code Error_State = Found ;
    TreeNode_t<T> LocNode = Helper_GetParent(this->pRoot , Data) ; 
    if(LocNode == nullptr){
        Error_State  = Not_Found ; 
    }
    else{
        Parent = LocNode->Data;
    } 
    return Error_State ; 
}
template<typename T>
TreeNode_t<T> BST<T>:: Helper_GetParent(TreeNode_t<T> &pSubRoot,T &Data )
{   
    // you search for parent of root so it is root himself 
    if(pSubRoot->Data = Data ){
        return pSubRoot ; 
    }
    else if(pSubRoot->pLeft == nullptr && pSubRoot->pRight== nullptr ){
        return nullptr ; 
    }
    else if ( (pSubRoot->pLeft  != nullptr && pSubRoot->pLeft->Data  == Data ) 
          ||  (pSubRoot->pRight != nullptr && pSubRoot->pRight->Data == Data ) ){
            return pSubRoot ;
          }
    else if(Data > pSubRoot->Data){
        pSubRoot = pSubRoot->pRight ; 
        Helper_GetParent(pSubRoot , Data);
    }
    else if(Data < pSubRoot->Data){
        pSubRoot = pSubRoot->pLeft ; 
        Helper_GetParent(pSubRoot , Data);
    }       
}
template<typename T>
void BST<T>::Destroy(T Data)
{

}
INSTANTIATE_CLASS_TEMPLATES(BST);
