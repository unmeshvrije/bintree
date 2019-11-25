// Implementation of the class
#include "BinarySearchTree.h"

// CTOR
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

// DTOR
BinarySearchTree::~BinarySearchTree() {
    delete root;
    root = NULL;
}
