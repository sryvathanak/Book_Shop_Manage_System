#pragma once

#include <iostream>
#include <vector>
#include "ApplyUserService.cpp"
#include"User.cpp"
#include "FileNotFoundException.cpp"
#include "BadInputException.cpp"
#include "Authentication.cpp"
#include"Application.cpp"
using namespace std;


enum
{
    EXIT = 0,
    LOGIN = 1
};
enum
{
    WELCOME_PAGE = 0,
    MANAGE_USER,
    MANAGE_BOOK,
};

class ApplicationRearrange
{
private:
    int choiceWelcome;
    int choiceMain;
    string username;
    string password;
    string role;
    ApplyUserService applyUserService;
    Application application;
    Authentication authentication;
    User user;
    void welcomePage()
    {
        cout << "\n1. Login To The System" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choiceWelcome;
        cout << endl;
    }
    void mainMenu()
    {
        cout << "1. Manage User" << endl;
        cout << "2. Manage Book" << endl;
        cout << "0. Back to Welcome Page" << endl;
        cout << "Enter Choice: ";
        cin >> choiceMain;
        cout << endl;
    }
    bool isValidUsername(string username){
        return all_of(username.begin(), username.end(), [](char ch){
            return (isalpha(ch) || isspace(ch));
        });
    }    
    void inputUsername(){
        do{
            cout<<"Input Username: ";
            cin>>username;        
        }while(!isValidUsername(username));
    }    
    bool isValidRole(string role){
        return all_of(role.begin(), role.end(), [](char ch){
            return (isalpha(ch) || isspace(ch));
        });
    }    
    void inputRole(){
        do{
            cout<<"Input Role: ";
            cin>>role;        
        }while(!isValidRole(role));
    }    
    bool isValidPassword(string password){
        const regex pattern("[A-Z a-z 0-9 @#!*&]+");
        return regex_match(password, pattern);
    }
    void inputPassword(){
        do{
            cout<<"Input Password: ";
            cin>>password;
        }while(!isValidPassword(password));
    }
public:
    void run()
    {
        do
        {
            welcomePage();
            switch (choiceWelcome)
            {
            case LOGIN:
                system("cls");
                inputUsername();
                inputPassword();
                cout << endl;
                do
                {

                    if (authentication.authenticateUser(username, password, role="admin"))
                    {
                        system("cls");
                        cout << "\n@@@@@@@@@ WELCOME BOOK STORE @@@@@@@@@@@" << endl<<endl<<endl;
                      
                            mainMenu();
                            switch (choiceMain)
                            {
                            case MANAGE_USER:
                                system("cls");
                                applyUserService.manageUserChoice();
                                break;
                            case MANAGE_BOOK:
                                   system("cls");
                                   application.Run();
                        
                                break;
                            case WELCOME_PAGE:
                                break;
                            default:
                                cout << ">>> Invalid Input <<<" << endl
                                     << endl;
                                break;
                            
                            }    
                    }else if(authentication.authenticateUser(username, password, role="user")){        
                            system("cls");
                            application.Buy();
                            break;
                    }else   
                        {
                            cout << "\nInvalid Login!!!" << endl;
                            break;
                        }
                   
                }while(choiceMain != WELCOME_PAGE);
                        break;

            case EXIT:
                break;
            default:
                cout << ">>> Invalid Input <<<" << endl;
                break;
            }
        }while(choiceWelcome != EXIT);
    }
        
};
