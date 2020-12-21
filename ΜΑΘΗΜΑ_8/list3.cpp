#include <iostream>


struct node
{
    int data;
    node *next;
};

class list
{
    node *head;
    public:
      list():head(nullptr) {}
      ~list()
      {
          node *delnode;
          while(this->head!=nullptr)
          {
              delnode=this->head;
              this->head=this->head->next;
          }
      }
      int size()const
      {
          int s=0;
          node *curr=this->head;
          while(curr!=nullptr)
          {
              s++;
              curr=curr->next;
          }
          return s;
      }
      void Insert(int data,int pos)
      {
          if(pos==1 && this->head==nullptr)
          {
             this->head=new node{data,nullptr};
             return;
          }
          else if(pos<=0 || pos>this->size()+1)
          {
              std::cerr<<"Invallid position"<<std::endl;
              return;
          }
          node *newnode=new node{data,nullptr};
          node *curr=this->head;
          if(pos==1)
          {
              newnode->next=this->head;
              this->head=newnode;
              return;
          }
          int i=1;
          while(i<pos-1)
          {
             curr=curr->next;
             i++;
          }
          node *temprorary=curr->next;
          curr->next=newnode;
          newnode->next=temprorary;
      }
      void Delete(int pos)
      {
          if(pos<=0 || pos>this->size())
          {
              std::cerr<<"Invallid position"<<std::endl;
              return;
          }
          node *curr=this->head;
          if(pos==1)
          {
              node *delnode=this->head;
              this->head=this->head->next;
              delete delnode;
              return;
          }
          int i=1;
          while(i<pos-1)
          {
              i++;
              curr=curr->next;
          }
          node *delnode=curr->next;
          node *afternode=curr->next->next;
          curr->next=afternode;
          delete delnode;
      }
      friend std::ostream &operator<<(std::ostream &os,const list &l)
      {
          const int SZ=l.size();
          int i=1;
          node *curr=l.head;
          while(curr!=nullptr)
          {
              if(i<=SZ-1)
              {
                  os<<curr->data<<"->";
              }
              else
              {
                  os<<curr->data<<std::endl;
              }
              i++;
              curr=curr->next;
          }
          return os;
      }
};

#define SIZE 10
#define DELETIONS 3
#include <random>
#include <ctime>

int main()
{
    list l;
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> dist(12,100);
    std::uniform_int_distribution <int> del(1,10);
    for(int i=1;i<=SIZE;i++)
    {
      l.Insert(dist(mt),i);
    }
    std::cout<<"Checkpoint 1"<<std::endl;
    std::cout<<l<<std::endl<<std::endl;

    std::cout<<"Checkpoint 2"<<std::endl;
    for(int i=0;i<DELETIONS;i++)
    {
        int position=del(mt);
        std::cout<<"Iteration:"<<i+1<<"\tPosition deleted:"<<position<<std::endl;
        l.Delete(position);
    }
    std::cout<<std::endl<<l<<std::endl<<std::endl;

    std::cout<<"Checkpoint 3"<<std::endl;
    std::cout<<"List's Final Size:"<<l.size()<<std::endl;
}
