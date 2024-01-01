#include "src\circularlinkedlist.hpp"
#include <iostream>
using namespace std;

CircularLinkedList :: CircularLinkedList() : head(NULL) {}

CircularLinkedList :: ~CircularLinkedList(){

    Node *delNode, *currNode = head, *lastNode = head;

    while(lastNode){

        if(lastNode->next == head) break;
        lastNode = lastNode->next;
    }

    while(currNode){

        delNode = currNode;
        currNode = currNode->next;
        delete delNode;

        if(currNode == lastNode){

            delete lastNode;
            break;
        }
    }
}

bool CircularLinkedList :: isEmpty(){

    return (head == NULL);
}

void CircularLinkedList :: insertAtBeginning(int item){

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        newNode->next = head;
    }
    else{

        Node *lastNode = head;
        while(lastNode){

            if(lastNode->next == head) break;
            lastNode = lastNode->next;
        }
        newNode->next = head;
        head = newNode;
        lastNode->next = head;
    }
}

void CircularLinkedList :: insertAtEnd(int item){

    Node *currNode = head;
    while(currNode){

        if(currNode->next == head) break;
        currNode = currNode->next;
    }

    Node *newNode = new Node(item);
    if(isEmpty()){

        head = newNode;
        newNode->next = head;
    }
    else{

        currNode->next = newNode;
        newNode->next = head;
    }
}

void CircularLinkedList :: insertAtPosition(int item, int position){

    if(isEmpty() && position > 0)
        throw Exception("Error: List is Empty!");

    Node *currNode = head, *prevNode;
    int index = 0;
    while(currNode && index < position){

        prevNode = currNode;
        currNode = currNode->next;
        index++;
        if(currNode == head)
            throw Exception("Error: Position is out of bounds!");
    }


    Node *newNode = new Node(item);
    if(currNode == head){

        if(isEmpty()){

            head = newNode;
            newNode->next = head;
        }
        else{

            Node *lastNode = head;
            while(lastNode){

                if(lastNode->next == head) break;
                lastNode = lastNode->next;
            }
            newNode->next = head;
            head = newNode;
            lastNode->next = head;
        }
    }
    else{

        newNode->next = currNode;
        prevNode->next = newNode;
    }
}

void CircularLinkedList :: deleteAtBeginning(){

    if(!isEmpty()){

        Node *delNode = head;
        if(delNode->next == head){

            head = NULL;
            delete delNode;
        }
        else{

            Node *lastNode = head;
            while(lastNode){

                if(lastNode->next == head) break;
                lastNode = lastNode->next;
            }

            head = head->next;
            lastNode->next = head;
            delete delNode;
        }
    }
    else{

        throw Exception("Error: List is Empty!");
    }
}

void CircularLinkedList :: deleteAtEnd(){

    if(isEmpty())
        throw Exception("Error: List is Empty!");

    Node *delNode = head, *prevNode;
    while(delNode){

        if(delNode->next == head) break;
        prevNode = delNode;
        delNode = delNode->next;
    }

    if(delNode == head){

        head = NULL;
        delete delNode;
    }
    else{

        prevNode->next = head;
        delete delNode;
    }
}

void CircularLinkedList :: deleteAtPosition(int position){

    if(isEmpty() && position > 0)
        throw Exception("Error: List is Empty!");

    Node *delNode = head, *prevNode;
    int index = 0;
    while(delNode && index < position){

        if(delNode->next == head) break;
        prevNode = delNode;
        delNode = delNode->next;
        index++;
    }

    if(delNode == head){

        if(head->next == head){

            head = NULL;
            delete delNode;
        }
        else{

            Node *lastNode = head;
            while(lastNode){

                if(lastNode->next == head) break;
                lastNode = lastNode->next;
            }
            head = head->next;
            lastNode->next = head;
            delete delNode;
        }
    }
    else{

        prevNode->next = delNode->next;
        delete delNode;
    }
}

int CircularLinkedList :: getItem(int position){

    if(isEmpty() && position > 0)
        throw Exception("Error: List is Empty!");

    Node *currNode = head;
    while(currNode){

        currNode = currNode->next;
        if(currNode == head)
            throw Exception("Error: Item Not Found!");
    }

    return currNode->getItem();
}

int CircularLinkedList :: findNode(int item){

    if(isEmpty())
        throw Exception("Error: List is Empty!");

    Node *currNode = head;
    while(currNode && item != currNode->getItem()){

        currNode = currNode->next;
        if(currNode == head) 
            throw Exception("Error: Item Not Found!");
    }

    return currNode->getItem();
}

void CircularLinkedList :: displayList(){

    Node *currNode = head;
    cout << "Circular Linked List: " << endl;
    while(currNode){

        cout << currNode->getItem() << endl;
        if(currNode->next == head) break;
        currNode = currNode->next;
    }
    cout << endl;
}
