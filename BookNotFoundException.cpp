#pragma once
#include<iostream>
using namespace std;

class BookNotFoundException{
    public:
       virtual const char* what() const throw(){
           return  "Book Was Not Found";
       }
};
