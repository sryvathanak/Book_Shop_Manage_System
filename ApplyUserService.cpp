#pragma once

#include <iostream>
#include <vector>
#include <regex>
#include "User.cpp"
#include "UserService.cpp"
#include "FileNotFoundException.cpp"
#include "UserNotFoundException.cpp"
#include "UserDuplicatedException.cpp"
#include "BadInputException.cpp"
using namespace std;

enum
{
    MAIN_MENU = 0,
    DISPLAY_USER = 1,
    ADD_USER,
    UPDATE_USER,
    DELETE_USER,
    LOAD_USER,
    SAVE_USER
};
enum
{
    U_MODIFY_EVERYTHING = 1,
    U_MODIFY_USERNAME,
    U_MODIFY_PASSWORD,
    U_MODIFY_ROLE
};

class ApplyUserService
{
private:
    int choiceMain;
    int choiceAdmin;
    int choiceModifyUser;
    string username;
    string password;
    string role;
    string digit;
    User user;
    UserService userService;
    void manageUserMenu()
    {
        cout << "1. Display User Information" << endl;
        cout << "2. Add New User" << endl;
        cout << "3. Update Existing User" << endl;
        cout << "4. Delete User" << endl;
        cout << "0. Back to Main Menu" << endl;
        // do{
        cout << "Enter Choice: ";
        cin >> choiceAdmin;
        cout <<endl<<endl;
    }
    void modifyUserMenu()
    {
        cout << "1. Modify Everything" << endl;
        cout << "2. Modify Username" << endl;
        cout << "3. Modify Password" << endl;
        cout << "4. Modify Role" << endl;
        cout << "Input Choice: ";
        cin >> choiceModifyUser;
        cout << endl
             << endl;
    }
    string updateInput(string username)
    {
        cout << "Input Username To Modify: ";
        cin >> username;
        return username;
    }
    string deleteInput(string username)
    {
        cout << "Input Username To Delete: ";
        cin >> username;
        return username;
    }

public:
    void manageUserChoice()
    {
        char ch='y';
        do
        {
           // system("cls");
            manageUserMenu();
            system("cls");
            switch (choiceAdmin)
            {
            case DISPLAY_USER:
                try
                {
                    int choiceDisplayUser;
                    cout << "Display" << endl
                         << endl;
                    cout << "1. Display All Users" << endl;
                    cout << "2. Display User By Username" << endl;
                    cout << "Input Choice: ";
                    cin >> choiceDisplayUser;
                    system("cls");
                    if (choiceDisplayUser == 1)
                    {
                        cout << endl;
                        userService.displayUser();
                        cout << endl;
                    }
                    else if (choiceDisplayUser == 2)
                    {
                        cout << "Input Username to Diplay: ";
                        cin >> username;
                        cout << endl;
                        userService.displayUserByUserame(username);
                        cout << endl;
                    }
                    else
                    {
                        cout << "\nInvalid Choice!!!" << endl;
                    }
                }
                catch (UserNotFoundException &u)
                {
                    cout << u.what() << endl
                         << endl;
                }
                break;
            case ADD_USER:
                try
                {
                    do{
                    system("cls");
                    cout << "ADD" <<endl<< endl;
                    cout << "Enter Username:";
                    cin >> username;
                    cout << "Enter Password:";
                    cin >> password;
                    cout << "Enter Role:";
                    cin >> role;
                    userService.addUser(username, password, role);
                    cout<<"Do You Want Create  Anathor User? if Yes click Y No click N: ";
                    cin>>ch;
                    }while(ch=='y'|| ch=='Y');
                }
                catch (UserDuplicatedException &u)
                {
                    cout << u.what() << endl;
                }

                break;
            case UPDATE_USER:
                modifyUserMenu();
                system("cls");
                switch (choiceModifyUser)
                {
                case U_MODIFY_EVERYTHING:
                    username = updateInput(username);
                    userService.modifyUser(username);
                    break;
                case U_MODIFY_USERNAME:
                    username = updateInput(username);
                    userService.modifyUserUsername(username);
                    break;
                case U_MODIFY_PASSWORD:
                    username = updateInput(username);
                    userService.modifyUserPassword(username);
                    break;
                case U_MODIFY_ROLE:
                    username = updateInput(username);
                    try{
                        userService.modifyUserRole(username);
                    }catch(UserNotFoundException& u){
                        cout<<u.what()<<endl;
                    }
                    break;
                default:
                    break;
                }
                break;
            case DELETE_USER:
                system("cls");
                try{
                  do{
                      username = deleteInput(username);
                      cout<<"Do You Really Want To Delete This User?"<<endl;
                      cout<<"Enter Y For Yes and N for No: ";
                      cin>>ch;
                      userService.deleteUser(username);
                   }while (ch=='y'||ch=='Y');
                
                }catch(UserNotFoundException& u){
                    cout<<u.what()<<endl;
                }
                break;
            }
        } while (choiceAdmin != MAIN_MENU);
    }
};