// Node.h
// Created on 04/10/2019
// All rights reserved.
#ifndef NODE_H
#define NODE_H
// To use NULL we need this.
// Source: https://stackoverflow.com/questions/462165/error-null-was-not-declared-in-this-scope 
#include <cstddef>
#include <algorithm>

template <class T>
class Node {
    private:
    Node<T> * left;
    Node<T> * right;
    T data;
    public:
    Node(): data() {
        left = NULL;
        right = NULL;
    }

    Node(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    Node(const Node& node) {
        left = new Node;
        right = new Node;
        left = node.left;
        right = node.right;
        data = node.data;
    }

    ~Node() {
        delete left;
        delete right;
        left = NULL;
        right = NULL;
    }

    void setLeftNode(Node<T> * node) {
        left = node;
    }

    void setRightNode(Node<T> * node) {
        right = node;
    }

    Node<T> * getRightNode() {
        return right;
    }

    Node<T> * getLeftNode() {
        return left;
    }

    T getData() {
        return data;
    }

    void setData(T data) {
        this->data = data;
    }

    bool isLeaf() {
        return left == NULL && right == NULL;
    }

    Node<T>& operator=(const Node<T>& node) {
        Node<T> copy(node);
        swap(copy, this);
        return *this;        
    }
};
#endif