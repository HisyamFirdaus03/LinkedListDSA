# LinkedListDSA

This repository contains C++ implementations of linked list data structures, created as part of the Data Structures & Algorithms class. It includes singly linked list, doubly linked list, circular linked list, and exception handling, along with a test driver (`main.cpp`) to demonstrate their usage.

## Table of Contents

- [Features](#features)  
- [Folder Structure](#folder-structure)  
- [Getting Started](#getting-started)  
  - [Prerequisites](#prerequisites)  
  - [Building](#building)  
  - [Running](#running)  
- [Usage / Examples](#usage--examples)  
- [Contributing](#contributing)  
- [License](#license)  
- [Acknowledgements](#acknowledgements)

## Features

- Singly linked list implementation (`singlylinkedlist.cpp`)  
- Doubly linked list implementation (`doublylinkedlist.cpp`)  
- Circular linked list implementation (`circularlinkedlist.cpp`)  
- Node definition file (`node.cpp`)  
- Exception handling (e.g. boundary checks) via `exception.cpp`  
- A `main.cpp` file to test and demonstrate the operations  

## File Structure
```
LinkedListDSA/
├── .vscode/
├── src/
│ ├── … (header files, if any)
├── main.cpp
├── node.cpp
├── singlylinkedlist.cpp
├── doublylinkedlist.cpp
├── circularlinkedlist.cpp
├── exception.cpp
├── LinkedList.exe
└── README.md
```
## Getting Started

### Prerequisites

You’ll need a C++ compiler (e.g. `g++`, `clang++`, or MSVC) that supports C++11 or later.

### Building

From the root directory:

```bash
cd src
g++ -std=c++11 main.cpp node.cpp singlylinkedlist.cpp doublylinkedlist.cpp circularlinkedlist.cpp exception.cpp -o LinkedList
```

### Running

```bash
./LinkedList
```

This will run the test driver in main.cpp, which should demonstrate various operations (insertion, deletion, traversal, etc.) across different list types.

### Usage Examples

```
SinglyLinkedList sl;
sl.insertFront(10);
sl.insertBack(20);
sl.insertAt(1, 15);
sl.remove(10);
sl.print();  // Expected output: 15 -> 20

DoublyLinkedList dl;
dl.insertBack(5);
dl.insertFront(3);
dl.remove(5);
dl.printForward();
dl.printBackward();

CircularLinkedList cl;
cl.insertBack(100);
cl.insertBack(200);
cl.remove(100);
cl.print();  // with wrap-around behavior

// Exception handling: e.g. remove from empty list, or invalid index
```

