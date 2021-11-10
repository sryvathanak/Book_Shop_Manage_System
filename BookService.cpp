#pragma once
#include <iostream>
#include "Book.cpp"
#include"BookDAO.cpp"
#include"BookNotFoundException.cpp"
#include <vector>
#include <algorithm>
#include"BookDuplicatedException.cpp"
using namespace std;

class BookService:public BookDAO
{

private:
    vector<Book> listbook;
    string EditTittle()
    {
        string tittle;
        cout << "Enter Tittle for Edit: ";
        cin >> tittle;
        return tittle;
    }
    Book book;
    int code[100];
    int qty[100];
    void check_code(){
           while (true)
           {
              cout<<"Enter Code:";
              cin>>code[x];
              if(cin.fail()){
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(),'\n');
                  continue;
              }
              cin.ignore(numeric_limits<streamsize>::max(),'\n');
              if(cin.gcount()>1){
                  continue;
              }
              if(code[x]<=0){
                  continue;
              }
              break;
           }
           
     }
     void check_quantity(){
         while (true)
         {
            cout<<"Enter Quantity:";
            cin>>qty[x];
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if(cin.gcount()>1){
                continue;
            }
            if(qty[x]<=0){
                continue;
            }
            break;
         }
     }

public:
    int  x=0;
    void add_book(string tittle,int code,float price,string author,float discount)   
    {
           Book book(tittle,code,price,author,discount); 
            if(listbook.empty()){
                listbook.push_back(book);
            }else{
                
                auto it = find_if(listbook.begin(), listbook.end(), [&tittle](Book &o)
                          { return (o.getTittle()== tittle); });
                if (it != listbook.end())
                {
                          BookDuplicatedException ee;
                          throw ee;       
                }
               else
                {
                    listbook.push_back(book);
                }
            }
    }
    void view_book()
          {
    
             cout<<"_____________________________________________________________________________"<<endl;
             cout<<" Tittle\t\tCode\t\tPrice\t\tAuthor\t\tDiscount"<<endl;
             cout<<"_____________________________________________________________________________"<<endl;
             if(listbook.empty()){
                 BookNotFoundException ee;
                 throw ee;
             }
             for(Book book: listbook){
                (book).outPut();
             }
        
    }
    void search_book(string tittle)
    {
        auto it = find_if(listbook.begin(), listbook.end(), [&tittle](Book &o)
                          { return (o.getTittle() == tittle); });
        if (it != listbook.end())
        {
            (*it).ouput_search();
        }else{
            BookNotFoundException ee;
            throw ee;
        }
    }
    void edit_book(string tittle)
    {
        
        auto it = find_if(listbook.begin(), listbook.end(), [&tittle](Book &o)
                          { return (o.getTittle() == tittle); });
        if (it != listbook.end())
        {
            (*it).inPut();
            cout << "Has Been Update Success!"<<endl;
        }
        else
        {
            BookNotFoundException ee;
            throw ee;
        }
    }
    void delete_book(string tittle)
    {
        auto it = find_if(listbook.begin(), listbook.end(), [&tittle](Book &o)
                          { return (o.getTittle() == tittle); });
        if (it != listbook.end())
        {
            listbook.erase(it);
            cout << "Has Been Delete Success!"<<endl;
        }
        else
        {
            BookNotFoundException ee;
            throw ee;
        }
    }
     void order_book(){
            float amt,damt,total=0;
            again();
            
            for(int c=0;c<=x;c++){
               for (Book book : listbook)
               {
                    if((book).getCode()==code[c]){
                    amt=(book).getPrice()*qty[c];
                    damt=amt-(amt*(book).getDiscount()/100);
                    cout<<"  "<<(book).getTittle()<<"\t  "<<code[c]<<"\t  "<<qty[c]<<"\t\t "<<(book).getPrice()<<"$\t\t "<<amt<<"$\t\t "<<damt<<"$"<<endl<<endl;
                    total+=damt;
                    }
                   
                }
            }
            cout<<"\t\tTotal="<<total<<"$"<<endl;
     }  
     void detail(){
         cout<<"\n\n\n\t\t!!!!!!!!!!!BOOK SHOP!!!!!!!!!!!!"<<endl<<endl;
         cout<<"___________________________________________________________"<<endl;
         cout<<"Tittle\t\t Code\t\t Price\t\t  Discount"<<endl;
         cout<<"___________________________________________________________"<<endl;
         for(Book book: listbook){
            cout<<" "<<(book).getTittle()<<"\t\t "<<(book).getCode()<<"\t\t  "<<(book).getPrice()<<"$\t\t    "<<(book).getDiscount()<<"%"<<endl;
         }
     }
     void again(){
          char ch='y';
            do{
            
                check_code();
                check_quantity();
                x++;
                cout<<"\nDo You Want To Order Another Product ?(Y/N)";
                cin>>ch;
                }while(ch=='y'||ch=='Y');
                cout<<"\n\t\t*********************INVOICE************************"<<endl;
                cout<<"\n\n________________________________________________________________________________"<<endl;
                cout<<" Tittle\t Code\t Quantity\t Price\tAmount \t  Amount After Discount"<<endl;
                cout<<"________________________________________________________________________________"<<endl;
     }
};