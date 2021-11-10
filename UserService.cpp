#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "User.cpp"
#include "UserServiceDAO.cpp"
#include "FileNotFoundException.cpp"
#include "UserNotFoundException.cpp"
#include "UserDuplicatedException.cpp"

using namespace std;

class UserService: public UserServiceDAO{
private:
    vector<User> userlist;
    User user;
    const string filename = "userlist.dat";
    
public:
    void addUser(string username,string password,string role){
        User user(username,password,role);
        if(userlist.empty()){
            userlist.push_back(user);
        }else{
            auto it=find_if(userlist.begin(),userlist.end(),[&username](User&u){
                return(u.getUsername()==username);
            });
            if(it!=userlist.end()){
                UserDuplicatedException U;
                throw U;
            }else{
                userlist.push_back(user);
            }
        }
    }
    void addUser(User user){
                userlist.push_back(user);
    }
    void displayUser(){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(User user: userlist){
            user.outputUser();
        }
    }
    void displayUserByUserame(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->outputUser();
                break;
                }else{
            UserNotFoundException u;
            throw u;                    
                }
            }
        }    
    void modifyUser(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUser();
                break;
                }
            }
        }
    void modifyUserUsername(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserUsername();
                break;
                }
            }
        }        
    void modifyUserPassword(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserPassword();
                break;
                }
            }
        }
    void modifyUserRole(string username){
        if(userlist.empty()){
            UserNotFoundException u;
            throw u;
        }        
        for(auto it=userlist.begin(); it!=userlist.end(); it++){
            if((it)->getUsername().compare(username)==0){
                (it)->inputUserRole();
                break;
                }
            }
        }                

    void deleteUser(string username){
        auto it=find_if(userlist.begin(),userlist.end(),[&username](User& u){
             return(u.getUsername()==username);
        });
        if(it!=userlist.end()){
            userlist.erase(it);
            cout<<"Has Been Delete Success"<<endl;
        }else{
            UserNotFoundException u;
            throw u;
        }
    }
    vector <User> getAllUsers(){
        User user1("dara","dara@123","admin");
        User user2("lina","Step@321","user");
        User user3("kai","12345!","admin");
        addUser(user1);
        addUser(user2);
        addUser(user3);
        return userlist;
      
    }
    
    
};