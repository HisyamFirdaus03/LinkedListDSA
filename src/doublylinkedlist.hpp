#pragma once
#include "node.hpp"

class DoublyLinkedList{

    private:
        Node *head, *tail;
    
    public:

        DoublyLinkedList();

        ~DoublyLinkedList();

        bool isEmpty();

        void insertAtBeginning(int item);

        void insertAtEnd(int item);

        void insertAtPosition(int item, int position);

        void deleteAtBeginning();

        void deleteAtEnd();

        void deleteAtPosition(int position);

        int getItem(int position);

        int findNode(int item);

        void displayList();

        void displayReverseList();

        class ListIsEmpty {};

        class ItemNotFound {};
};