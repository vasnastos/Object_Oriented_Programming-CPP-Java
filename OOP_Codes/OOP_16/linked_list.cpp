/*
Υλοποίηση συνδεδεμένης λίστας.
*/

#include <iostream>
#include <fstream>
#include "catch.hpp"

template <class T>
struct node
{
  T data;
  node *next;
};

template <class T>
class list
{
  node <T> *head;
  public:
   list():head(nullptr) {}
   list(list &ll)
   {
       this->head=new node<T>{ll.head->data,nullptr};
       node <T> *curr=ll.head;
       curr=curr->next;
       node <T> *temp=this->head;
       while(curr!=nullptr)
       {
           node <T> *nextnode=new node<T>{curr->data,nullptr};
           temp->next=nextnode;
           temp=temp->next;
           curr=curr->next;
       }
   }
   ~list()
   {
       while(head!=nullptr)
       {
           node <T> *temp=head;
           this->head=this->head->next;
           delete temp;
       }
   }
   void push_back(T d)
   {
       if(this->head==nullptr)
       {
           head=new node<T>{d,nullptr};
           return;
       }
       node <T> *curr=this->head;
       node <T> *newnode=new node<T>{d,nullptr};
       while(this->curr->next!=nullptr)
       {
          curr=curr->next;
       }
       curr->next=newnode;
   }
   void push_front(int d)
   {
       if(this->head==nullptr)
       {
           this->head=new node<T>{d,nullptr};
           return;
       }
       node <T> *newnode=new node<T>{d,nullptr};
       newnode->next=this->head;
       this->head=newnode;
   }
   int length()
   {
       int len=0;
       node <T> curr=this->head;
       while(curr!=nullptr)
       {
           len++;
           curr=curr->next;
       }
       return len;
   }
   T sum()
   {
       T s=0;
       node <T> *curr=this->head;
       while(curr!=nullptr)
       {
           s+=curr->data;
           curr=curr->next;
       }
       return s;
   }
   void erase_front()
   {
       if(this->head!=nullptr)
       {
           std::cerr<<"Empty list!!!!!"<<std::endl;
           return;
       }
       node <T> *del=this->head;
       this->head=this->head->next;
       delete del;
   }
   void popback()
   {
       if(this->head==nullptr)
       {
           std::cerr<<"Empty List!!!"<<std::endl;
           return;
       }
       node <T> *curr=this->head;
       node *prev=curr;
       while(curr->next!=nullptr)
       {
           prev=curr;
           curr=curr->next;
       }
       temp->next=nullptr;
       delete curr;
   }
   void bubblesort()
   {
       int size=this->length();
       node <T> *curr=this->head;
       node <T> *temp;
       while(curr!=nullptr)
       {
           temp=this->head;
           for(int i=0;i<size-1;i++)
           {
              if(temp->data<temp->next->data)
              {
                  T tmp=temp->data;
                  temp->data=temp->next->data;
                  temp->next->data=tmp;
              }
              temp=temp->next;
           }
           curr=curr->next;
       }
   }
   void insert(T dt,int pos)
   {
       int len=this->length();
       if(pos<=0 && pos>len)
       {
           std::cerr<<"Invallid position error!!!!"<<std::endl;
           return;
       }
       node <T> *curr=this->head;
       node <T> *newnode=new node<T>{d,nullptr};
       for(int i=1;i<pos-1;i++)
       {
          curr=curr->next;
       }
       node <T> *tmp=curr->next;
       curr->next=newnode;
       newnode->next=tmp;
   }

   void erase(int pos)
   {
       int len=this->length();
       if(pos<=0 || pos>len)
       {
           std::cerr<<"Invalid position!!!"<<std::endl;
           return;
       }
       node <T> *curr=this->head;
       for(int i=1;i<pos-1;i++)
       {
           curr=curr->next;   
       }
       node *del=curr->next;
       curr->next=curr->next->next;
       delete del;
   }
   void printlist()
   {
       node <T> *curr=this->head;
       int len=this->length();
       int i=0;
       while(curr!=nullptr)
       {
           if(i<len-1)
           std::cout<<curr->data<<"->";
           else 
           std::cout<<curr->data;
           curr=curr->next;
       }
       std::cout<<std::endl;
   }
   T front() {this->head->data;}
   T print_elem(int i)
   {
       node <T> *curr=this->head;
       for(int j=1;j<i;j++)
       {
           curr=curr->next;
       }
       return curr->data;
   }
};

TEST_CASE("Integers list","[List]")
{
    list <int> mylist;
    for(int i=1;i<=10;i++)
    {
        mylist.push_back(i);
    }
    REQUIRE(mylist.length()==10);
    mylist.push_front(20);
    REQUIRE(mylist.front()==20);
    mylist.erase_front();
    REQUIRE(mylist.front()==1);
    int a[]{1,2,3,4,5,6,7,8,9,10};
    for(int i=1;i<=10;i++)
    {
      REQUIRE(mylist.print_elem(i)==a[i-1]);
    }
    mylist.popback();
    REQUIRE(mylist.length()==9);
    for(int i=1;i<=9;i++)
    {
      REQUIRE(mylist.print_elem(i)==a[i-1]);
    }
}

TEST_CASE("Double List","[List]")
{
    list <double> mylist;
    for(double i=2.0;i<=5.0;i+=0.2)
    {
        mylist.push_back(i);
    }
    REQUIRE(mylist.length()==17);
    mylist.erase(3);
    double a[]{2.0,2.2,2.6,2.8,3.0,3.2,3.2,3.4,3.6,3.8,4.0,4.2,4.4,4.6,4.8,5.0};
    REQUIRE(mylist.length()==sizeof(a)/sizeof(a[0]));
    for(int i=1;i<=sizeof(a)/sizeof(a[0]);i++)
    {
        REQUIRE(mylist.print_elem(i)==a[i-1]);
    }
    mylist.erase(4);
    REQUIRE_FALSE(mylist.print_elem(4)==2.8);
}
