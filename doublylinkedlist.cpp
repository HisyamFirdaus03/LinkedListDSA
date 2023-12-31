#include "src\doublylinkedlist.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList :: DoublyLinkedList() : head(NULL), tail(NULL) {}

DoublyLinkedList :: ~DoublyLinkedList(){

    Node *delNode, *currNode = head;
    while(currNode){

        delNode = currNode;
        currNode = currNode->next;
        delete delNode;
    }
}

bool DoublyLinkedList ::  isEmpty(){

    return (head == NULL && tail == NULL);
}

void DoublyLinkedList ::  insertAtBeginning(int item){

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else{

        head->previous = newNode;
        newNode->next = head;
        newNode->previous = NULL;
        head = newNode;
    }
}

void DoublyLinkedList ::  insertAtEnd(int item){

    Node *currNode = head;
    while(currNode){

        if(currNode->next == NULL) break;
        currNode = currNode->next;
    }

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else{
        tail = newNode;
        currNode->next = newNode;
        newNode->next = NULL;
        newNode->previous = currNode;
    }
}

void DoublyLinkedList ::  insertAtPosition(int item, int position){

    if(isEmpty() && position > 0){

        throw ListIsEmpty();
    }

    Node *currNode = head, *prevNode, *nextNode;
    int index = 0;
    while(currNode && index < position){

        prevNode = currNode;
        currNode = currNode->next;
        index++;
    }

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else if(currNode == head && !isEmpty()){

        newNode->next = head;
        newNode->previous = NULL;
        head->previous = newNode;
        head = newNode;
    }
    else if(currNode == tail && !isEmpty()){

        newNode->next = tail;
        tail->previous = newNode;
        newNode->previous = prevNode;
        prevNode->next = newNode;
    }
    else if(!isEmpty()){

        newNode->next = currNode;
        currNode->previous = newNode;
        newNode->previous = prevNode;
        prevNode->next = newNode;
    }
}

void DoublyLinkedList ::  deleteAtBeginning(){

    Node *delNode = head;
    if(!isEmpty() && head->next != NULL){

        head = head->next;
        head->previous = NULL;
        delete delNode;
    }
    else if(!isEmpty() && head->next == NULL){

        head = NULL;
        tail = NULL;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

void DoublyLinkedList ::  deleteAtEnd(){

    Node *delNode = head, *prevNode;
    while(delNode){

        if(delNode->next == NULL) break;
        prevNode = delNode;
        delNode = delNode->next;
    }

    if(delNode == head && !isEmpty()){

        head = NULL;
        tail = NULL;
        delete delNode;
    }
    else if(!isEmpty()){

        tail = prevNode;
        prevNode->next = NULL;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

void DoublyLinkedList ::  deleteAtPosition(int position){

    if(isEmpty() && position > 0){

        throw ListIsEmpty();
    }

    Node *delNode = head, *prevNode, *nextNode;
    int index = 0;
    while(delNode && index < position){

        if(delNode->next == NULL) break;
        prevNode = delNode;
        delNode = delNode->next;
        index++;
    }

    if(delNode == head && !isEmpty()){

        if(head->next){

            head = head->next;
            head->previous = NULL;
            delete delNode;
        }
        else{

            head = NULL;
            tail = NULL;
            delete delNode;
        }
    }
    else if(delNode == tail && !isEmpty()){

        tail = tail->previous;
        tail->next = NULL;
        delete delNode;   
    }
    else if(!isEmpty()){

        nextNode = delNode->next;
        prevNode->next = delNode->next;
        nextNode->previous = prevNode;
        delete delNode;
    }
    else{

        throw ListIsEmpty();
    }
}

int DoublyLinkedList :: getItem(int position){

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

int DoublyLinkedList :: findNode(int item){

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

void DoublyLinkedList ::  displayList(){

    Node *currNode = head;
    cout << "Doubly Linked List: " << endl;
    for(int i = 1; currNode; i++){

        cout << "Item #" << i << ": " << currNode->getItem() << endl;
        currNode = currNode->next;
    }
    cout << endl;
}

void DoublyLinkedList :: displayReverseList(){

    Node *currNode = tail;
    cout << "Reverse Doubly Linked List: " << endl;
    for(int i = 1; currNode; i++){

        cout << "Item #" << i << ": " << currNode->getItem() << endl;
        currNode = currNode->previous;
    }
    cout << endl;
}
