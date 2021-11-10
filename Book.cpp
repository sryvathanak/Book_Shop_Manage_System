#pragma once
#include<iostream>
using namespace std;

class Book
{
private:
    string tittle;
    int code;
    float price;
    string author;
    float discount;
public:
    Book():tittle("unknow"),code(0),price(0),author("unknow"),discount(0){}
    Book(string tittle,int code,float price,string author,float discount):tittle(tittle),code(code),price(price),author(author),discount(discount){}

    string getTittle(){
        return tittle;
    }
    void setTittle(string tittle){
        this->tittle=tittle;
    }
    int getCode(){
        return code;
    }
    void setCode(int code){
        this->code=code;
    }
    float getPrice(){
        return price;
    }
    void setPrice(float price){
        this->price=price;
    }
    string getAuthor(){
        return author;
    }
    void setAuthor(string author){
        this->author=author;
    }
    float getDiscount(){
        return discount;
    }
    void set(float discount){
        this->discount=discount;
    }
   virtual void outPut(){
        cout<<"  "<<tittle<<"\t\t "<<code<<"\t\t  "<<price<<"\t\t "<<author<<"\t\t  "<<discount<<endl;
    }
    void ouput_search(){
        cout<<"Tittle# "<<tittle<<endl<<"Code# "<<code<<endl<<"Price# "<<price<<endl<<"Author# "<<author<<endl<<"Discount# "<<discount<<endl;
    }
   virtual void inPut(){
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
    }
    bool isEqualTittle(string tittle){
        return(this->tittle==tittle);
    }
    bool operator()(string tittle){
         return(this->tittle==tittle);
    }

    
    
};

