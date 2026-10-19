#ifndef NODE_H
#define NODE_H
#include <iostream>

template <class T>
class LLWrapper;

template <class T>
class Node {
    friend LLWrapper<T>;
   private:
    Node<T>* next;
    T data;
    Node(T data);
    Node<T>* insert(T data);
    Node<T>* insert(Node<T>* node);
    Node<T>* remove(T data);
    void print();
    int size();
    Node<T>* search(T data);
    ~Node();
    void deleteList();
};

#include "Node.cpp"
#endif