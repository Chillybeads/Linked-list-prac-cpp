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
    Node<T>* newNode = new Node<T>(data);
    //New Node
    if(data < this->data){
        //newNode data is smaller than head data
        newNode->next = this;
        return newNode;
        //new node becomes head
    }

    Node<T>* curr = this;
    //Travesalvariable
    while(curr->next != NULL && (data > curr->next->data) ){
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    //New node is placed in list
    return this;
    
}

template <class T>
Node<T>* Node<T>::insert(Node<T>* node){
    
    if(node == NULL) return this;
    //node is null
    Node<T>* curr = node;
    //Traversal Varaible for passed lsit
    Node<T>* head = this;
    //current list
    while(curr != NULL){

        head  = head->insert(curr->data);
        //New list 
        curr = curr->next;
        //next node in passed lsit
    }
    return head;
}
template <class T>
Node<T>* Node<T>::remove(T data){

    Node<T>* curr = this;
    //copy of pointer to the first node
    Node<T>** slot = &curr;
    //points to pointer at current node
    while(*slot != NULL){
        
        if((*slot)->data == data){
            
            Node<T>* toRemove = *slot;
            *slot = toRemove->next;
            //We move toward a anohter node
            delete toRemove;
            //delete matching ndoe;
        }else{
            slot = &(*slot)->next;
            //move to the next pointer
        }
    }
    return curr;
}
template <class T>
void Node<T>::print(){

    Node<T>* curr = this;
    //Traversal variable 
    curr = curr->next;
    //Point to second node in list
    std::cout << "- " << data;
    //Print first node's data
    while(curr != NULL){
        std::cout << "->" << curr->data;
        //Print data
        curr = curr->next;
    }

    std::cout << std::endl;
    //New line after print list
}
template <class T>
int Node<T>::size(){

    int count = 0;
    Node<T>* curr = this;
    //Traversal Variable 
    while(curr != NULL){
        
        count++;
        //Increment list size
        curr = curr->next;
        
    }

    return count;
}
template <class T>
Node<T>* Node<T>::search(T data){

    Node<T>* result = NULL;
    Node <T>* curr = this;
    //Traversal Variable

    while(curr != NULL){
        if(curr->data == data){
            //node data is equall
            Node<T>* copy = new Node<T>(curr->data);
            //Copy data
            copy->next = result;
            result = copy;
            //Insert data into new list;
        }

        curr = curr->next;
    }

    return result;
}
template <class T>
void Node<T>::deleteList(){
    
    Node<T>* curr = this;
    //Traversal Varaible
    while(curr != NULL){
        
        Node<T>* toRemove = curr;
        curr = curr->next;

        delete toRemove;
    }
    //Delete list
}