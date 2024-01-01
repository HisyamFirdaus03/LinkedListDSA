#pragma once
#include "node.hpp"
#include "exception.hpp"

class CircularLinkedList{

    private:
        Node *head;

    public:

        CircularLinkedList();

        ~CircularLinkedList();

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