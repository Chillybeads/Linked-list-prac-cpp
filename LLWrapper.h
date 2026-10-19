#ifndef LLWRAPPER_H
#define LLWRAPPER_H

#include <iostream>

#include "Node.h"
template <class T>
class LLWrapper {
   public:
    LLWrapper() {
        head = NULL;
    }

    LLWrapper(T data) {
        head = new Node<T>(data);
    }

    ~LLWrapper() {
        if (head != NULL) {
            head->deleteList();
        }
    }

    void insert(T data) {
        if (head == NULL) {
            head = new Node<T>(data);
        } else {
            head = head->insert(data);
        }
    }

    void insert(LLWrapper<T>* node) {
        if (node == NULL || node->head == NULL) {
            return;
        }

        if (head == NULL) {
            head = new Node<T>(node->head->data);
            head = head->insert(node->head->next);
            return;
        }

        head = head->insert(node->head);
    }

    void remove(T data) {
        if (head != NULL) {
            head = head->remove(data);
        }
    }

    void print() {
        if (head == NULL) {
            std::cout << "Empty list" << std::endl;
            return;
        }

        head->print();
    }

    int size() {
        return head->size();
    }

    LLWrapper<T>* search(T data) {
        Node<T>* searchResult = head->search(data);
        LLWrapper<T>* resultWrapper = new LLWrapper<T>();
        resultWrapper->head = searchResult;
        return resultWrapper;
    }

    T peek() {
        if (head == NULL) {
            return T();
        }
        return head->data;
    }

   private:
    Node<T>* head;
};
#endif