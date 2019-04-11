// BinarySearchTree.h
// Created on 04/10/2019
// All rights reserved.
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Node.h"
#include <iostream>
using std::cout;
using std::endl;
template <class T>
class BinarySearchTree {
    private:
        Node<T> * root;
        void replaceParent(Node<T>*& oldTree, Node<T>*& tree) {
            if (tree->getRightNode() != NULL) {
                replaceParent(oldTree, tree->getRightNode());
            } else {
                oldTree->setData(tree.getData());
                oldTree = tree;
                tree = tree->getLeftNode();
            }
        }
        // With a tip of the cap to the book.
        void insert(T item, Node<T>*& tree) {
            if (tree == NULL) {
                tree = new Node<T>(item);
            } else if (item < tree->getData()) {
                insert(item, tree->getLeftNode());
            } else if (item > tree->getData()) {
                insert(item, tree->getRightNode());
            } else if (item == tree->getData()) {
                cout << "Item is already in tree" << endl;
            } else {
                cout << "This should never happen!" << endl;
            }
        }
        bool search(T item, Node<T> tree) {
            if (tree == NULL) {
                return false;
            }
            if (item == tree.getData()) {
                return true;
            }
            if (item < tree.getData()) {
                return search(item, tree.getLeftNode());
            } else {
                return search(item, tree.getRightNode());
            }
        }
        // Implementation taken from book.
        void erase(T item, Node<T>*& tree) {
            if (tree == NULL) {
                return;
            }
            if (item < tree->getData()) {
                erase(item, tree->getLeftNode());
            } else if (item > tree->getData()) {
                erase(item, tree->getRightNode());
            } else {
                Node<T> * oldRoot = tree;
                if (tree->getLeftNode() == NULL) {
                    tree = tree->getRightNode();
                } else if (tree->getRightNode() == NULL) {
                    tree = tree->getLeftNode();
                } else {
                    replaceParent(oldRoot, oldRoot->getLeftNode());
                }

                delete oldRoot;
            }
        }
    public:
        void insert(T item) {
            insert(item, root);
        }
        
        bool search(T item) {
           return search(item, root);
        }
        
        void erase(T item) {
           erase(item, root);
        }
       
        void print();

};
#endif