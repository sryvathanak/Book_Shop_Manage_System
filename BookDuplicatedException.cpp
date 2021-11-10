#pragma once

#include <iostream>
#include <exception>
using namespace std;

class BookDuplicatedException: public exception{
public:
    virtual const char* what() const throw(){
        return "This book already has in the system!!!";
    }
};