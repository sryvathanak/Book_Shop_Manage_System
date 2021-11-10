#include<iostream>
#include"Book.cpp"
#include<vector>
using namespace std;

class BookDAO{
     public:
       virtual void add_book(string tittle,int code,float price,string author,float discount)=0;
       virtual void view_book()=0;
       virtual void search_book(string tittle)=0;
       virtual void edit_book(string tittle)=0;
       virtual void delete_book(string tittle)=0;
       virtual void order_book()=0;
       virtual void detail()=0;

};