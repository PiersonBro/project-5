// BinarySearchTree.h
// Created on 04/10/2019
// All rights reserved.
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "Node.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template <class T>
class BinarySearchTree {
    private:
        Node<T> * root;
        void replaceParent(Node<T>*& oldTree, Node<T>*& tree) {
            if (tree->getRightNode() != NULL) {
                auto right = tree->getRightNode();
                replaceParent(oldTree, right);
            } else {
                oldTree->setData(tree->getData());
                oldTree = tree;
                tree = tree->getLeftNode();
            }
        }
        // With a tip of the cap to the book and a little help from cplusplus.com
        T insert(T item, Node<T>*& tree) {
            if (tree == NULL) {
                // cout << item << endl;
                tree = new Node<T>(item);
            } 
            if (item < tree->getData()) {
                auto left = tree->getLeftNode();
                Node<T>* newLeft = new Node<T>(insert(item, left));
                tree->setLeftNode(newLeft);
            }
            if (item > tree->getData()) {
                auto right = tree->getRightNode();
                Node<T>* newRight = new Node<T>(insert(item, right));
                tree->setRightNode(newRight);
            
            }/* else if (item == tree->getData()) {
                cout << "Item is already in tree" << endl;
            } else {
                cout << "This should never happen!" << endl;
            }*/
            return tree->getData();
        }
        bool search(T item, Node<T>* tree) {
            // cout << tree->getLeftNode()->getData() << "fail" << endl;
            // cout << tree->getRightNode()->getData() << "confirmed" << endl;
            if (tree == NULL) {
                return false;
            }
            if (item == tree->getData()) {
                return true;
            }
            if (item < tree->getData()) {
                return search(item, tree->getLeftNode());
            } else {
                return search(item, tree->getRightNode());
            }
        }
        // Implementation taken from book.
        void erase(T item, Node<T>*& tree) {
            if (tree == NULL) {
                return;
            }
            if (item < tree->getData()) {
                auto left = tree->getLeftNode();
                erase(item, left);
            } else if (item > tree->getData()) {
                auto right = tree->getRightNode();
                erase(item, right);
            } else {
                Node<T> * oldRoot = tree;
                if (tree->getLeftNode() == NULL) {
                    tree = tree->getRightNode();
                } else if (tree->getRightNode() == NULL) {
                    tree = tree->getLeftNode();
                } else {
                    auto left = oldRoot->getLeftNode();
                    replaceParent(oldRoot, left);
                }

                delete oldRoot;
            }
        }
    public:
        void insert(T item) {
            insert(item, root);
        }
        
        bool search(T item) {
            cout << "hello" << item << endl;
           return search(item, root);
        }
        
        void erase(T item) {
           erase(item, root);
        }

        void print() {
            vector<T> v;
            // We need a tree we can mutate without destroying data.
            BinarySearchTree<T> consumableTree(*this);
            while (root != NULL) {
                v.push_back(root->getData());
                erase(root->getData());
                // cout << root->getData() << endl;
            }
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ", ";
            }
            cout << endl;
        }

        BinarySearchTree() {
            root = NULL;
        }

        BinarySearchTree(const BinarySearchTree& tree) {
            root = new Node<T>(*tree.root);
        }

        ~BinarySearchTree() {
            delete root;
            root = NULL;
        }

        BinarySearchTree<T>& operator=(const BinarySearchTree<T>& tree) {
            BinarySearchTree<T> copiedTree(tree);
            swap(copiedTree, this);
            return *this;
        }

};
#endif