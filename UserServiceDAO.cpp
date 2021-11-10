#include <iostream>
#include "User.cpp"
#include <vector>
using namespace std;

class UserServiceDAO{
public:
    virtual void addUser(string username,string password,string role)=0;
    virtual void displayUser()=0;
    virtual void modifyUser(string username) = 0;
    virtual void deleteUser(string username) = 0;


};