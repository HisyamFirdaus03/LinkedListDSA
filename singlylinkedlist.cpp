#include "src\singlylinkedlist.hpp"
#include <iostream>
using namespace std;

SinglyLinkedList :: SinglyLinkedList() : head(NULL) {}

SinglyLinkedList :: ~SinglyLinkedList(){

    Node *delNode, *currNode = head;
    while(currNode){

        delNode = currNode;
        currNode = currNode->next;
        delete delNode;
    }
}

bool SinglyLinkedList ::  isEmpty(){

    return (head == NULL);
}

void SinglyLinkedList ::  insertAtBeginning(int item){

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        newNode->next = NULL;
    }
    else{

        newNode->next = head;
        head = newNode;
    }
}

void SinglyLinkedList ::  insertAtEnd(int item){

    Node *currNode = head;
    while(currNode){

        if(currNode->next == NULL) break;
        currNode = currNode->next;
    }

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        newNode->next = NULL;
    }
    else{

        currNode->next = newNode;
        newNode->next = NULL;
    }
}

void SinglyLinkedList ::  insertAtPosition(int item, int position){

    if(isEmpty() && position > 0){

        throw ListIsEmpty();
    }

    Node *currNode = head, *prevNode;
    int index = 0;
    while(currNode && index < position){

        prevNode = currNode;
        currNode = currNode->next;
        index++;
    }

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        newNode->next = NULL;
    }
    else{

        newNode->next = currNode;
        prevNode->next = newNode;
    }
}

void SinglyLinkedList ::  deleteAtBeginning(){

    if(!isEmpty()){

        Node *delNode = head;
        head = head->next;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

void SinglyLinkedList ::  deleteAtEnd(){

    Node *delNode = head, *prevNode;
    while(delNode){

        if(delNode->next == NULL) break;
        prevNode = delNode;
        delNode = delNode->next;
    }

    if(delNode == head && !isEmpty()){

        head = NULL;
        delete delNode;
    }
    else if(!isEmpty()){

        prevNode->next = NULL;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

void SinglyLinkedList ::  deleteAtPosition(int position){

    if(isEmpty() && position > 0){

        throw ListIsEmpty();
    }

    Node *delNode = head, *prevNode;
    int index = 0;
    while(delNode && index < position){

        if(delNode->next == NULL) break;
        prevNode = delNode;
        delNode = delNode->next;
        index++;
    }

    if(position == 0 && !isEmpty()){

        head = head->next;
        delete delNode;
    }
    else if(!isEmpty()){

        prevNode->next = delNode->next;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

int SinglyLinkedList :: getItem(int position){

    if(isEmpty()){

        throw ListIsEmpty();
    }

    Node *currNode = head;
    int index = 0;
    while(currNode && index < position){

        currNode = currNode->next;
        index++;
    }

    if(currNode == NULL){

        throw ItemNotFound();
    }

    return currNode->getItem();
}

int SinglyLinkedList :: findNode(int item){

    Node *currNode = head;
    int index = 0;
    while(currNode && currNode->getItem() != item){

        currNode = currNode->next;
        index++;
    }

    if(currNode == NULL){

        throw ItemNotFound();
    }
    return index;
}

void SinglyLinkedList ::  displayList(){

    Node *currNode = head;
    cout << "Singly Linked List: " << endl;
    for(int i = 1; currNode; i++){

        cout << "Item #" << i << ": " << currNode->getItem() << endl;
        currNode = currNode->next;
    }
    cout << endl;
}