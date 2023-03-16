#ifndef _BST_
#define _BST_
#include "BinaryTree.h"
/* namespace DSA {
namespace DS {
namespace BINARY_TREE {
namespace BST{ */
typedef enum
{
    Not_Found,
    Found,
    Success,
    Duplicated 
}Error_Code;   

template<class T>
class BST: public Binary_Tree<T>
{
    public:
        Error_Code Insert(T Data);
        Error_Code Search(T Data);
        Error_Code Delete(T Data);
        void Destroy(T Data);
        Error_Code GetParent(T Data , T &Parent);
    private:
        Error_Code Helper_Insert(TreeNode_t<T> &pSubRoot , T Data);
        TreeNode_t<T> Helper_Search(TreeNode_t<T> pSubRoot , T Data);
        TreeNode_t<T> Helper_GetParent(T Data);
        void Helper_Delete( TreeNode_t<T> &pDeletedNode);
        void Helper_Swap(TreeNode_t<T> &_1stNode , TreeNode_t<T> &_2ndNode);

    /* data */ 
};

/* 
}}}} // DSA::DS::BINART_TREE::BST
 */
#endif /* _BST_ */
