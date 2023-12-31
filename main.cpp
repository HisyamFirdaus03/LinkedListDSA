#include <iostream>
#include "src\singlylinkedlist.hpp"
#include "src\doublylinkedlist.hpp"
using namespace std;

int main()
{

    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;

    try
    {
        singlyList.insertAtEnd(10);
        singlyList.insertAtEnd(12);
        singlyList.insertAtEnd(13);
        singlyList.insertAtPosition(29, 1);
        singlyList.deleteAtPosition(1);
        //cout << singlyList.getItem(5);

        doublyList.insertAtEnd(5);
        doublyList.insertAtEnd(6);
        doublyList.insertAtEnd(12);
        doublyList.insertAtEnd(13);
        doublyList.insertAtPosition(69 ,3);

        doublyList.deleteAtPosition(0);
        doublyList.displayList();
        doublyList.displayReverseList();
    }
    catch (SinglyLinkedList::ListIsEmpty)
    {
        cout << "Error: List is Empty!" << endl;
    }
    catch (SinglyLinkedList::ItemNotFound)
    {
        cout << "Error: Item Not Found!" << endl;
    }

    singlyList.displayList();

    system("pause");
    return 0;
}