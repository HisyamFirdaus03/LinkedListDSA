#include "src\node.hpp"
using namespace std;


Node :: Node() {}

Node :: Node(int _item) : item(_item) {}

int Node :: getItem() const{

    return item;
}