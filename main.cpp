#include <iostream>
#include "src\singlylinkedlist.hpp"
#include "src\doublylinkedlist.hpp"
#include "src\circularlinkedlist.hpp"
#include "src\exception.hpp"
using namespace std;

int main()
{

    SinglyLinkedList singlyList;
    DoublyLinkedList doublyList;
    CircularLinkedList circularList;

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

        circularList.insertAtEnd(5);
        circularList.insertAtEnd(6);
        circularList.insertAtEnd(12);
        circularList.insertAtEnd(14);
        circularList.deleteAtPosition(2);
        circularList.displayList();
    }
    catch (SinglyLinkedList::ListIsEmpty)
    {
        cout << "Error: List is Empty!" << endl;
    }
    catch (SinglyLinkedList::ItemNotFound)
    {
        cout << "Error: Item Not Found!" << endl;
    }
    catch(Exception &e){

        cout << e.what() << endl;
    }

    singlyList.displayList();

    system("pause");
    return 0;
}