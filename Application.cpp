#pragma once
#include <iostream>
#include "BookService.cpp"
#include "Book.cpp"
#include"BookNotFoundException.cpp"
using namespace std;

class Application
{
private:
   Book book;
    string tittle;
    int code;
    float price;
    string author;
    float discount;
  // BookService bookservice;
   string enter_tittle()
   {
      string tittle;
      cin >> tittle;
      return tittle;
   }
   void show_funtion(){
       cout<<"\n\n\t\t\t===========MAIN MENU=============\n\n\n"<<endl;
       cout<<"1.Create Book"<<endl;
       cout<<"2.View All Book"<<endl;
       cout<<"3.Search Book"<<endl;
       cout<<"4.Update Book"<<endl;
       cout<<"5.Delete Book"<<endl;
       cout<<"0.Back To Role"<<endl;
   }
  
public:
   BookService  bookservice;

   void Run()
   {
      int option;
      string Tittle;
      int QTY;
      char ask='y';
      do
      { 
         
         show_funtion();
         cout << "Please Enter Your Option: ";
         cin >> option;
         system("cls");
         if (option == 1)
         {   
               try{
                  do{
                     system("cls");
                     cout<<"Enter Tittle: ";
                     cin>>tittle;
                     cout<<"Enter Code:";
                     cin>>code;
                     cout<<"Enter Price: ";
                    cin>>price;
                    cout<<"Enter Author: ";
                    cin>>author;
                    cout<<"Enter Discount: ";
                    cin>>discount;
                    bookservice.add_book(tittle,code,price,author,discount);
                    cout<<"Do You Want Create Anathor Book? if Yes click Y No click N: ";
                    cin>>ask;
                  }while(ask=='y'|| ask=='Y');
              }catch(BookDuplicatedException e){
                    cout<<e.what()<<endl;
              }catch(BookNotFoundException e){
                    cout<<e.what()<<endl;
              }
         }else if (option == 2)
         {
              try{
                  bookservice.view_book();
              }catch(BookNotFoundException& e){
                  cout<<e.what()<<endl;
              }
         }else if(option==3){
            
               cout<<"Enter Tittle For Search: ";
               Tittle=enter_tittle();
               try{
                       bookservice.search_book(Tittle);
               }catch(BookNotFoundException& e){
                       cout<<e.what()<<endl;
               }
         }else if(option==4){
               try{
                  do{   
                   cout<<"Enter Tittle For Update: ";
                   Tittle=enter_tittle();
                   bookservice.edit_book(Tittle);
                   cout<<"Do You Want Update Anathor Book?if Yes click Y No click N:";
                   cin>>ask;
                  }while(ask=='y' || ask=='Y'); 
               }catch(BookNotFoundException& e){
                      cout<<e.what()<<endl;
               }       
        }else if(option==5){
              try{
                  do{  
                     cout<<"Enter Tittle For Delete: ";
                     Tittle=enter_tittle();
                     cout<<"Do You Want Delete Anathor Book?if Yes click Y No click N:";
                     cin>>ask;
                     bookservice.delete_book(Tittle);
                  }while(ask=='y'|| ask=='Y');   
               }catch(BookNotFoundException& e){
                     cout<<e.what()<<endl;
               }      
         }
        else{
               cout<<"Invalid Option Please Enter Number 1-6"<<endl;
        }
        }while (option != 0);
      
   }
   void Buy(){
      bookservice.detail();
      bookservice.order_book();
   }
};