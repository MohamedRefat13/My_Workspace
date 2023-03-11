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

    private:
        Error_Code Helper_Insert(TreeNode_t<T> &pSubRoot , T Data);
        TreeNode_t<T> Helper_Search(TreeNode_t<T> &pSubRoot , T Data);
        TreeNode_t<T> Helper_GetParent(TreeNode_t<T> &pSubRoot,TreeNode_t<T> &pChild );

    /* data */ 
};

/* 
}}}} // DSA::DS::BINART_TREE::BST
 */
#endif /* _BST_ */
