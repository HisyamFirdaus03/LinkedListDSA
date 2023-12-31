#pragma once

class Node{

    public:
        int item;
        Node* next;
        Node *previous;

        Node();

        Node(int _item);

        int getItem() const;
};