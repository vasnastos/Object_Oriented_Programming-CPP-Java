#include <iostream>

struct node
{
   double data;
   node *next;
};

class list
{
    private:
       node *head;
    public:
      list():head(nullptr)
      {

      }
      ~list()
      {
          node *temp;
          while(this->head!=nullptr)
          {
              temp=this->head;
              this->head=this->head->next;
              delete temp;
          }
      }
      void push_front(double adata)
      {
          if(this->head==nullptr)
          {
              this->head=new node{adata,nullptr};
              return;
          }
         node *newnode=new node{adata,nullptr};
         newnode->next=this->head;
         this->head=newnode;
      }
      void pop_front()
      {
          node *delnode=this->head;
          this->head=this->head->next;
          delete delnode;
      }
      void push_back(double adata)
      {
          if(this->head==nullptr)
          {
              this->head=new node{adata,nullptr};
              return;
          }
         node *curr=this->head;
         while(curr->next!=nullptr)
         {
             curr=curr->next;
         }
         node *newnode=new node{adata,nullptr};
         curr->next=newnode;
      }
      void pop_back()
      {
          node *curr=this->head;
          while(curr->next->next!=nullptr)
          {
              curr=curr->next;
          }
          node *delnode=curr->next;
          curr->next=nullptr;
          delete delnode;
      }
      int size()const
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
      void reverse()
      {
          const int SZ=this->size();
          double *data=new double[SZ];
          node *curr=this->head;
          int i=0;
          while(curr!=nullptr)
          {
              data[i++]=curr->data;
              curr=curr->next;
          }
          curr=this->head;
          for(int j=SZ-1;j>=0;j--)
          {
              curr->data=data[j];
              curr=curr->next;
          }
          delete data;
      }
};

#include <random>
#include <ctime>


int main()
{
    list l;
    std::mt19937 mt(time(nullptr));
    std::uniform_real_distribution <double> dist(1.0,50.0);
    #define SIZE 12
    for(int i=0;i<SIZE;i++)
    {
       l.push_back(dist(mt));
    }
    std::cout<<"\t\tCheckpoint 1"<<std::endl;
    std::cout<<l<<std::endl<<std::endl;

    std::cout<<"\t\tCheckpoint 2"<<std::endl;
    l.push_front(dist(mt));
    std::cout<<l<<std::endl<<std::endl;

    std::cout<<"\t\tCheckpoint 3"<<std::endl;
    l.pop_back();
    std::cout<<l<<std::endl<<std::endl;

    std::cout<<"\t\tCheckpoint 4"<<std::endl;
    l.pop_front();
    std::cout<<l<<std::endl<<std::endl;

    std::cout<<"\t\tCheckpoint 5"<<std::endl;
    std::cout<<"List Length:"<<l.size()<<std::endl<<std::endl;


    std::cout<<"\t\tCheckpoint 6"<<std::endl;
    l.reverse();
    std::cout<<l<<std::endl<<std::endl;
}