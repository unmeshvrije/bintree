#ifndef BINTREE
#define BINTREE

#include <cstdio>

class TreeNode
{
public:
    struct TreeNode *left;
    int data;
    struct TreeNode *right;

    ~TreeNode()
    {
        delete left;
        delete right;
        //std::cout << "DTOR : TreeNode" << std::endl;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree
{

private:
    TreeNode *root;

    // some private functions
    // some changes by yousif
    void appendInternal(TreeNode **root, TreeNode *newnode);
    void inorderInternal(TreeNode *root);

    // Yousif Alneamy
    bool findInternal(TreeNode *root, int num);
    bool isBalancedInternal(TreeNode *root);
    int heightInternal(TreeNode *root);
    void PrintLevelWiseInternal(TreeNode* root,int Level);
    void preOrderInternal(TreeNode *root);
public:

    BinarySearchTree();
    virtual ~BinarySearchTree();

    // Unmesh
    void append(int num);
    void printInOrder();

    // Mohammed Maher
    void printPreOrder();

    // Omar Inaam
    void printPostOrder();

    // Abdullah S. Mahmoud
    void printLevelWise();

    // Shamil-Al-Ameen
    void printaLevel(TreeNode* root, int level);
    void LevelWiseReverseInternal(TreeNode* root);
    void printLevelWiseReverse();

    // Omar Al Saffar
    void printZigZagLevel();

    //According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
    // Omar Alhabeeb
    int lowestCommonAncestor(int num1, int num2);

    //Yousif Alneamy
    bool find(int num);
    bool isBalanced();
    int height();
};

#endif
