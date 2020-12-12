#include <iostream>

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
     ~list() 
     {
         node <T> *temp=this->head;
         this->head=this->head->next;
     }
     void push_front(T d)
     {
         if(this->head==nullptr)
         {
             this->head=new node<T>{d,nullptr};
             return;
         }
         node <T> *anode=new node<T>{d,nullptr};
         anode->next=this->head;
         this->head=anode;
     }
     void pop_front()
     {
         if(this->head==nullptr) return;
         node *felnode=this->head;
         this->head=this->head->next;
         delete felnode;
     }
     T front()
     {
         return this->head->data;
     }
     bool isEmpty() {return this->head==nullptr;}
     int size()
     {
         node <T> *curr=this->head;
         int l=0;
         while(curr!=nullptr)
         {
             l++;
             curr=curr->next;
         }
         return l;
     }
};

template <class T>
class Stack
{
    list <T> data;
    public:
    Stack() {}
    void push(T dt);
    void pop();
    T top();
    int size();
    bool empty();
};

void Stack::push(T dt)
{
   data.push_front(dt);
}

void Stack::pop()
{
  data.pop_front();
}

T Stack::top()
{
  return data.front();
}

int Stack::size()
{
   data.size();
}

bool Stack::empty()
{
  data.empty();
}