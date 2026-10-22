#include "Node.h"

template <class T>
Node<T>::Node(T d): data(d){
    
    next = NULL;
}

template <class T>
Node<T>::~Node(){
    next = NULL;
}
template <class T>
Node<T>* Node<T>::insert(T data){
    
    if(data < this->data){
        
        Node<T>* newNode = new Node<T>(data);
        //New Node

        newNode->next = this;
        return newNode;
        //new node is inserted
    }

    if(next == NULL){
        next = new Node<T>(data);
        //New data is the largest
    }else{
        next = next->insert(data);
        //Recursive case
    }
    
    return this;
}

template <class T>
Node<T>* Node<T>::insert(Node<T>* node){
    
    if(node == NULL) return this;
    //node is null
    
    Node<T>* head = insert(node->data);
    //Copy of one value
    return head->insert(node->next);
    //Rest is passed in the list

}
template <class T>
Node<T>* Node<T>::remove(T data){
    
    if(next != NULL) next = next->remove(data);
    //Recursive call
    if(this->data == data){
        Node<T>* nodesLeft = next;

        delete this;
        return nodesLeft;
    }
    //We delete a node after deciding to continue traversing
    return this;
}
template <class T>
void Node<T>::print(){

    std::cout << data;
    //Print value
    if(next != NULL){
        std::cout <<"->";
        next->print();
        //Call next nodes print function
    }else{
        std::cout << std::endl;
        //Next line
    }
}
template <class T>
int Node<T>::size(){

    if(next == NULL) return 1;
    //Base case
    return 1 + next->size();
    //Recursive call
}
template <class T>
Node<T>* Node<T>::search(T data){

    Node<T>* nodesLeft = NULL;

    if(next != NULL){
        nodesLeft = next->search(data);
    }
    //Recursive call
    if(this->data == data){
        
        Node<T>* copy = new Node<T>(this->data);
        copy->next = nodesLeft;

        return copy;
    }
    //Check if data match, return copy list

    return nodesLeft;
}
template <class T>
void Node<T>::deleteList(){
    
    if(next != NULL){
        next->deleteList();
    }
    //Recursive call
    delete this; //Delete current node
}