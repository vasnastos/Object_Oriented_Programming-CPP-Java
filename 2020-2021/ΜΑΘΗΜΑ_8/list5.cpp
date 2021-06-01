/*
*/
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <map>

struct node
{
    std::string name;
    std::string phone;
    node *next;
};

class list
{
    node *head;
    public:
      list():head(nullptr) {}
      ~list() {}
      void push_back(std::string n,std::string p)
      {
          if(this->head==nullptr)
          {
              this->head=new node{n,p,nullptr};
              return;
          }
          node *newnode=new node{n,p,nullptr};
          node *curr=this->head;
          while(curr->next!=nullptr)
          {
             curr=curr->next;
          }
          curr->next=newnode;
      }
      std::string search(std::string name)
      {
          node *curr=this->head;
         while(curr!=nullptr)
         {
            if(curr->name==name)
            {
                return curr->phone;
            }
            curr=curr->next;
         }
         return "Not Registered";
      }
      void print()
      {
          node *curr=this->head;
          std::cout<<"======================================"<<std::endl;
          while(curr!=nullptr)
          {
              std::cout<<"\t->"<<curr->name<<"\t"<<curr->phone<<std::endl;
              curr=curr->next;
          }
          std::cout<<"======================================"<<std::endl<<std::endl;
      }
};

class phonebook
{
    std::map <std::string,list> phones;
    public:
      phonebook()
      {
          std::string st;
          for(int i=0;i<26;i++)
          {
              st="";
              st+='A'+i;
              phones.insert(std::make_pair(st,list()));
          }
      }
      void insert(std::string name,std::string phonenum)
      {
          std::string starts=""+std::toupper(name.at(0));
          phones[starts].push_back(name,phonenum);
      }
      void search()
      {
          std::string name;
          std::cout<<"Give name you want to search:";
          std::cin>>name;
          std::string starts=""+std::toupper(name.at(0));
          std::cout<<std::endl<<"============================================="<<std::endl;
          std::cout<<"Name:"<<name<<"---------"<<"Phone:"<<this->phones[starts].search(name)<<std::endl;
          std::cout<<"============================================="<<std::endl<<std::endl;
      }

      void hr()
      {
          std::cout<<"---------------------------------------------------"<<std::endl;
      }

      void print()
      {
          for(auto &x:this->phones)
          {
              std::cout<<"\tStrarting letter:"<<x.first<<std::endl;
              hr();
              x.second.print();
          }
      }
};

int menu()
{
    int option;
    std::cout<<"1-Show Records"<<std::endl;
    std::cout<<"2-Search record"<<std::endl;
    std::cout<<"3-Exit"<<std::endl;
    std::cout<<"Select option:";
    std::cin>>option;
    return option;
}

void fill_data(phonebook &b)
{
   std::fstream fs;
   std::string line,word,w;
   fs.open("source.csv",std::ios::in);
   while(std::getline(fs,line))
   {
       std::stringstream ss(line);
       std::getline(ss,word,'|');
       std::getline(ss,w,'|');
       b.insert(word,w);
   }
   fs.close();
}

int main()
{
    phonebook book;
    fill_data(book);
    while(true)
    {
        switch(menu())
        {
            case 1:
               book.print();
               break;
            case 2:
               book.search();
               break;
            case 3:
               exit(EXIT_SUCCESS);
            default:
              std::cerr<<"Invallid option!!!"<<std::endl;
              break;
        }
    }
    return 0;
}