// Implementation of the class
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;
// CTOR
BinarySearchTree::BinarySearchTree()
{
    root = NULL;
}

// DTOR
BinarySearchTree::~BinarySearchTree()
{
    delete root;
    cout << "DTOR : BST" << endl;
    root = NULL;
}

void BinarySearchTree::appendInternal(TreeNode **root, TreeNode *newnode)
{
    // Check if the root is NULL
    if (*root == NULL)
    {
        *root = newnode;
        return;
    }
    if (newnode->data <= (*root)->data)
    {
        appendInternal((&(*root)->left), newnode);
    }
    else
    {
        appendInternal((&(*root)->right), newnode);
    }
}

void BinarySearchTree::append(int num)
{
    TreeNode *newnode = new TreeNode;
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;

    appendInternal(&root, newnode);
}

void BinarySearchTree::inorderInternal(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderInternal(root->left);
    cout << root->data << endl;
    inorderInternal(root->right);
}

void BinarySearchTree::printInOrder()
{
    inorderInternal(root);
}

bool BinarySearchTree::find(int num)
{
    return findInternal(root, num);
}

bool BinarySearchTree::findInternal(TreeNode *root, int num)
{
    if (root == NULL)
    {
        return false;
    }
    int data = root->data;
    if (num == data)
    {
        return true;
    }
    if (num > data)
    {
        return findInternal(root->right, num);
    }
    else
    {
        return findInternal(root->left, num);
    }
}

bool BinarySearchTree::isBalanced()
{
    return isBalancedInternal(root);
}

bool BinarySearchTree::isBalancedInternal(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    int leftMaxHeight = heightInternal(root->left);
    int rightMaxHeight = heightInternal(root->right);

    int diff = abs(leftMaxHeight - rightMaxHeight);

    return diff <= 1 && isBalancedInternal(root->left) && isBalancedInternal(root->right);
}

int BinarySearchTree::height()
{
    return heightInternal(root);
}

int BinarySearchTree::heightInternal(TreeNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int leftHeight = heightInternal(root->left) + 1;
    int rightHeight = heightInternal(root->right) + 1;
    return max(leftHeight, rightHeight);
}
