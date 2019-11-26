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
// Method for tree-traversing level by level
void BinarySearchTree::printLevelWise()
{
	int h = Height(root);
	int i;
	for (i = 1; i <= h; i++)
	{
		PrintLevelWiseInternal(root, i);
		cout << endl;
	}	
}
void BinarySearchTree::PrintLevelWiseInternal(TreeNode* root,int Level)
{
	if (root == NULL)
		return;
	if (Level == 1)
		std::cout<<root->data<<" ";
	else if (Level > 1)
	{
		PrintLevelWiseInternal(root->left, Level - 1);
		PrintLevelWiseInternal(root->right, Level - 1);
	}	
}
// function compute the number of nodes from the root down to the last leaf
int BinarySearchTree::Height(TreeNode* root)
{
	if (root == NULL) 
		return 0;
	else
    {
	int lefth = Height(root->left);
	int righth = Height(root->right);
	if (lefth > righth) 
		return lefth + 1;
	else 
		return righth + 1;
	}
}
