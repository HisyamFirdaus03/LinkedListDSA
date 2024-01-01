#include "src\exception.hpp"

Exception :: Exception(string _msg) : msg(_msg) {}

Exception :: ~Exception() {}

string Exception :: what() const{

    return msg;
}
