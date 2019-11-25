#ifndef BINTREE
#define BINTREE

#include<cstdio>

class TreeNode
{
    public:

    struct TreeNode *left;
    int data;
    struct TreeNode *right;


    ~TreeNode() {
        delete left;
        delete right;
        left = NULL;
        right = NULL;
    }
};


class BinarySearchTree {

    private:
        TreeNode* root;

    public:
    
    BinarySearchTree();
    virtual ~BinarySearchTree();

    int append(int num);

    void printInOrder();
    void printPreOrder();
    void printPostOrder();

    void printLevelWise();
    void printLevelWiseReverse();
    void printZigZagLevel();

    //According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
    int lowestCommonAncestor(int num1, int num2);

    bool find(int num);
    bool isBalanced();

};

#endif
