// Implementation of the class
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;
// CTOR
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

// DTOR
BinarySearchTree::~BinarySearchTree() {
    delete root;
    cout << "DTOR : BST" << endl;
    root = NULL;
}

void BinarySearchTree::appendInternal(TreeNode ** root, TreeNode* newnode){
    // Check if the root is NULL
    if (*root == NULL) {
        *root = newnode;
        return;
    }
    if (newnode->data <= (*root)->data) {
        appendInternal((&(*root)->left), newnode);
    } else {
        appendInternal((&(*root)->right), newnode);
    }
}

void BinarySearchTree::append(int num) {
    TreeNode * newnode = new TreeNode;
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;

    appendInternal(&root, newnode);
}

void BinarySearchTree::inorderInternal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    inorderInternal(root->left);
    cout << root->data << endl;
    inorderInternal(root->right);
}

void BinarySearchTree::printInOrder() {
    inorderInternal(root);
}

/////    Omar Inaam

void BinarySearchTree::postorderInternal(TreeNode *root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << endl;
    postorderInternal(root->left);

    postorderInternal(root->right);
}

void BinarySearchTree::printpostOrder() {
    postorderInternal(root);
}
