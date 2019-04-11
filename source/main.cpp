#include "Node.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

void nodeTests() {
    Node<int> head(10);
    Node<int> * left = new Node<int>(20);
    Node<int> * right = new Node<int>(30);
    head.setLeftNode(left);
    head.setRightNode(right);
    cout << head.getLeftNode()->getData() << endl;
    cout << head.getRightNode()->getData() << endl;
    cout << head.getData() << endl;
}


int main() {
    nodeTests();
    BinarySearchTree<int> b;
    return 0;
}