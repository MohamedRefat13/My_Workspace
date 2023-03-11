#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

/* namespace DSA{
namespace DS{
namespace BINARY_TREE { */

template<typename T>
struct Node_t
{
    Node_t(T Val):Data(Val) , pLeft(nullptr) , pRight(nullptr) {}
    T Data ; 
    Node_t<T> *pRight ; 
    Node_t<T> *pLeft ; 
};

template<typename T>
using TreeNode_t = Node_t<T>* ;

template<typename T>
class Binary_Tree 
{
    public:
        Binary_Tree();
        void InOrder(void (*pFun)(T &Data));
        void PreOrder(void (*pFun)(T &Data));
        void PostOrder(void (*pFun)(T &Data));
        bool IsEmpty()const;
        uint16_t GetSize() const;
        uint16_t GetHeight()const;

    protected:
        TreeNode_t<T> pRoot ; 
        uint16_t _Size ;
        uint16_t _Height ;

        void recur_InOrder  (Node_t<T> *pSubRoot,  void (*pFun)(T &Data));
        void recur_PreOrder (Node_t<T> *pSubRoot,  void (*pFun)(T &Data));
        void recur_PostOrder(Node_t<T> *pSubRoot,  void (*pFun)(T &Data));

};

/* }}} // DSA::DS::BINARY_TREE */
#endif /* _BINARY_TREE_H_ */











