#pragma once
#include <string>
using namespace std;

class Exception{

    private:
        string msg;

    public:
        Exception(string _msg);

        ~Exception();

        string what() const;

};