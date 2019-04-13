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
    b.insert(72);
    b.insert(12);
    b.insert(42);
    b.insert(55);
    b.insert(2);
    b.insert(122);
    b.insert(412);
    b.insert(557);
    b.insert(221);
    b.insert(98);
    
   auto a =
    b.search(72) &&
    b.search(12) &&
    b.search(42) &&
    b.search(55) &&
    b.search(2) &&
    b.search(122) &&
    b.search(412) &&
    b.search(557) &&
    b.search(221) &&
    b.search(98);
    cout << "hello:" << a << endl;
    
    
     b.print();
    return 0;
}