#include <iostream>
#include <ctime>

struct pair
{
    int position;
    int element;
};

struct node
{
    int data;
    node *next;
};

void push_front(node **curr,int d)
{
    node *newnode=new node{d,nullptr};
    newnode->next=*curr;
    *curr=newnode;
}

void push_back(node *curr,int d)
{
    node *newnode=new node{d,nullptr};
    while(curr->next!=nullptr)
    {
      curr=curr->next;
    }
    curr->next=newnode;
}

void pop_back(node *curr)
{
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    node *delnode=curr->next;
    curr->next=nullptr;
    delete delnode;
}

void pop_front(node **curr)
{
    node *delnode=*curr;
    *curr=(*curr)->next;
    delete delnode;
}

int length(node *curr)
{
    int l=0;
    while(curr!=nullptr)
    {
        l++;
        curr=curr->next;
    }
    return l;
}

int sum(node *curr)
{
    int s=0;
    while(curr!=nullptr)
    {
        s+=curr->data;
        curr=curr->next;
    }
    return s;
}

double average(node *curr)
{
    return (double)sum(curr)/length(curr);
}

pair max_element(node *curr)
{
    int max=curr->data;
    curr=curr->next;
    int i=0;
    int maxpos=i;
    while(curr!=nullptr)
    {
        if(curr->data>max)
        {
            max=curr->data;
            maxpos=i;
        }
        i++;
        curr=curr->next;
    }
    return pair{maxpos,max};
}

pair min_element(node *curr)
{
    int i=0;
    int min=curr->data;
    int minpos=i;
    curr=curr->next;
    while(curr!=nullptr)
    {
        if(curr->data<min)
        {
            min=curr->data;
            minpos=i;
        }
        i++;
        curr=curr->next;
    }
    return pair{minpos,min};
}

void print(node *curr)
{
    const int size=length(curr);
    std::cout<<"\t\tLIST"<<std::endl;
    std::cout<<std::endl<<"======================================================="<<std::endl;
    int i=1;
    while(curr!=nullptr)
    {
       if(i<size-1)
       {
           std::cout<<curr->data<<"->";
       }
       else
       {
           std::cout<<curr->data<<std::endl;
       }
       i++;
       curr=curr->next;
    }
    std::cout<<"======================================================="<<std::endl<<std::endl;
}

int main()
{
    node *head=new node{rand(),nullptr};
    srand(time(nullptr));
    #define SIZE 10
    for(int i=0;i<SIZE;i++)
    {
      push_back(head,rand()%200);
    }
    push_front(&head,rand()%200);
    std::cout<<"CheckPoint 1"<<std::endl;
    print(head);

    pop_front(&head);
    std::cout<<"CheckPoint 2"<<std::endl;
    print(head);

    pop_back(head);
    std::cout<<"CheckPoint 3"<<std::endl;
    print(head);

    std::cout<<"CheckPoint 4"<<std::endl;
    std::cout<<"Length:"<<length(head)<<std::endl;
    std::cout<<std::endl<<"Checkpoint 5"<<std::endl;
    std::cout<<"Summary:"<<sum(head)<<std::endl;
    std::cout<<"Average:"<<average(head)<<std::endl;
    std::cout<<"Max:Element->"<<max_element(head).element<<"--"<<"Pos->"<<max_element(head).position<<std::endl;
    std::cout<<"Min:Element->"<<min_element(head).element<<"--"<<"Pos->"<<min_element(head).position<<std::endl;
     
    delete head;
}