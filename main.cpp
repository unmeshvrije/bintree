#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char* argv[]) {

    cout << "Hello Trees!" << endl;
    BinarySearchTree bst;
    //calling of append method
    bst.append(45);
    bst.append(23);
    bst.append(14);
    bst.append(18);
    bst.append(8);
    bst.append(5);
    bst.append(7);
    bst.append(89);
    bst.append(56);
    bst.append(67);
    bst.append(52);
    bst.append(91);

    bst.printInOrder();

    /*bst.printPreOrder();

    bst.printPostOrder();

    bst.printLevelWise();

    bst.printLevelWiseReverse();

    bst.printZigZagLevel();

    cout << bst.lowestCommonAncestor(18, 56);

    cout << bst.find(56);
    */
}
