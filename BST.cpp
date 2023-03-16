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
/* TreeSpace:: */ TreeNode_t<T> BST<T>:: Helper_Search(TreeNode_t<T> pSubRoot , T Data)
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
            pSubRoot = pSubRoot->pLeft ; 
         }
    }
    return LocNode ;
}
template<typename T>
Error_Code BST<T>::Delete(T Data)
{
    Error_Code  Error_State = Success; 
    TreeNode_t<T> LocNode = Helper_Search(this->pRoot , Data);
    if(LocNode != nullptr ){
        Helper_Delete(LocNode );
        this->_Size--;
        
    }else{
        Error_State = Not_Found ; 
    }
    return Error_State ; 
}
template<typename T>
void  BST<T>:: Helper_Delete(TreeNode_t<T> &pDeletedNode)
{
    //CASE I : Node is Leaf
    if (pDeletedNode->pRight == nullptr && pDeletedNode->pLeft == nullptr ){
        TreeNode_t<T> pParentNode = Helper_GetParent( pDeletedNode->Data);
        if     (pParentNode->pLeft  == pDeletedNode )  pParentNode->pLeft   = nullptr ;
        else if(pParentNode->pRight == pDeletedNode )  pParentNode->pRight  = nullptr ; 
        delete pDeletedNode ; 
    }
    
    //CASE II : Node has one Left child
    else if(pDeletedNode->pRight == nullptr && pDeletedNode->pLeft != nullptr)
    {
        TreeNode_t<T> IteratorNode = pDeletedNode ; 
        TreeNode_t<T> pParentNode = nullptr;
        while(IteratorNode->pLeft !=nullptr ){
            Helper_Swap(IteratorNode , IteratorNode->pLeft);
            pParentNode = IteratorNode;
            IteratorNode = IteratorNode->pLeft;
        }
        pParentNode->pLeft = nullptr ;
        delete IteratorNode ; 
    
    }

    //CASE III : Node has one Right child
    else if(pDeletedNode->pLeft == nullptr && pDeletedNode->pRight != nullptr)
    {
        TreeNode_t<T> IteratorNode = pDeletedNode ; 
        TreeNode_t<T> pParentNode = nullptr;
        while(IteratorNode->pRight !=nullptr){
            Helper_Swap(IteratorNode , IteratorNode->pRight );
            pParentNode = IteratorNode;
            IteratorNode = IteratorNode->pRight;
        }
        pParentNode->pRight = nullptr ;
        delete IteratorNode ; 
    }

    //CASE IV : Node Has Two Child
    else if(pDeletedNode->pLeft != nullptr && pDeletedNode->pRight != nullptr){
        /* Go one step left the get most right node 
           swap pDeletedNode with the most right node then delete it  */
        TreeNode_t<T> IteratorNode = pDeletedNode->pLeft ; 
        TreeNode_t<T> pParentNode = nullptr ; 
        while(IteratorNode->pRight){
            pParentNode=IteratorNode;
            IteratorNode = IteratorNode->pRight ; 
        }
        Helper_Swap(IteratorNode , pDeletedNode);
        std::cout<<"Parent : \n"<<pParentNode->pLeft->Data<<"\n";
        std::cout<<"Deleted : \n"<<IteratorNode->Data<<"\n";

        if (pParentNode->pLeft->Data  == IteratorNode->Data ){
            pParentNode->pLeft   = nullptr ;
            std::cout<<"NO : \n";
        }
        else if(pParentNode->pRight->Data == IteratorNode->Data ) {
            pParentNode->pRight  = nullptr ; 
            std::cout<<"Yes : \n";
        } 
        
        delete IteratorNode ; 
    }

}
template<typename T>
Error_Code BST<T>:: GetParent(T Data , T &Parent)
{
    Error_Code Error_State = Found ;
    TreeNode_t<T> LocNode = Helper_GetParent( Data) ; 
    if(LocNode == nullptr){
        Error_State  = Not_Found ; 
    }
    else{
        Parent = LocNode->Data;
    } 
    return Error_State ; 
}
template<typename T>
TreeNode_t<T> BST<T>:: Helper_GetParent(T Data )
{   
    // you search for parent of root so it is root himself 
    TreeNode_t<T> pSubRoot = this->pRoot ; 
    if(pSubRoot->Data == Data ){
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
        Helper_GetParent( Data);
    }
    else if(Data < pSubRoot->Data){
        pSubRoot = pSubRoot->pLeft ; 
        Helper_GetParent( Data);
    }
    return pSubRoot   ;      
}

template<typename T>
void BST<T>:: Helper_Swap(TreeNode_t<T> &_1stNode , TreeNode_t<T> &_2ndNode)
{
    auto TempData  = _1stNode->Data ; 
    _1stNode->Data = _2ndNode->Data;
    _2ndNode->Data = TempData;
}
template<typename T>
void BST<T>::Destroy(T Data)
{

}
INSTANTIATE_CLASS_TEMPLATES(BST);
