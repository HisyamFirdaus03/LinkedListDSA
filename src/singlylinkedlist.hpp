#pragma once
#include "node.hpp"

class SinglyLinkedList{

    private:
        Node *head;

    public:

        SinglyLinkedList();

        ~SinglyLinkedList();

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

        class ListIsEmpty {};

        class ItemNotFound {};
};