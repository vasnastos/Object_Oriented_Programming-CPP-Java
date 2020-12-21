#include <iostream>
#define SIZE 10

struct node{
    int data;
    node *next;
};

class list
{
    node *head;
    public:
      list():head(nullptr) {}
      ~list() {
          while(this->head!=nullptr)
          {
              node *delnode=this->head;
              this->head=this->head->next;
              delete delnode;
          }
      }
      void pushfront(int data)
      {
          if(this->head==nullptr)
          {
              this->head=new node{data,nullptr};
              return;
          }
          node *newnode=new node{data,this->head};
          this->head=newnode;
      }
      void popfront()
      {
          node *delnode=this->head;
          this->head=this->head->next;
          delete delnode;
      }
      int headdata() {return this->head->data;}
      int size()
      {
          int l=0;
          node *curr=this->head;
          while(curr!=nullptr)
          {
              l++;
              curr=curr->next;
          }
          return l;
      }
      void print()
      {
          int i=1;
          std::cout<<"====================================="<<std::endl;
          node *curr=this->head;
          while(curr!=nullptr)
          {
              std::cout<<"\t"<<i++<<"."<<curr->data<<std::endl;
              curr=curr->next;
          }
          std::cout<<"====================================="<<std::endl;
      }
};

class stack
{
    list l;
    public:
      stack() {}
      ~stack() {}
      void push(int data)
      {
         l.pushfront(data);
      }
      void pop()
      {
          l.popfront();
      }
      bool empty() {return l.size()==0;}
      int top() {return l.headdata();}
      int size() {return l.size();}
      void print()
      {
          l.print();
      }
};

void hr()
{
    std::cout<<"--------------------------------------------------"<<std::endl<<std::endl;
}

int main()
{
  stack s;
  for(int i=1;i<=SIZE;i++)
  {
    s.push(i);
  }
  std::cout<<"Checkpoint 1"<<std::endl;
  std::cout<<"\tSize:"<<s.size()<<std::endl;
  std::cout<<"\tTop data:"<<s.top()<<std::endl;
  std::cout<<std::boolalpha;
  std::cout<<"\tEmpty:"<<s.empty()<<std::endl;
  hr();

  std::cout<<"Checkpoint 2"<<std::endl;
  s.pop();
  s.pop();
  s.print();
  hr(); 

  std::cout<<"Checkpoint 3"<<std::endl;
  s.push(13);
  s.print();
  hr();

  std::cout<<"Checkpoint 4"<<std::endl;
  std::cout<<"\tSize:"<<s.size()<<std::endl;
  std::cout<<"\tTop data:"<<s.top()<<std::endl;
  std::cout<<std::boolalpha;
  std::cout<<"\tEmpty:"<<s.empty()<<std::endl;
  s.print();
  hr(); 
}