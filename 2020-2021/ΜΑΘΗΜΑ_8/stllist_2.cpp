#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

struct phonebook
{
    std::string name;
    std::string phone;
};

void add_to_list(std::list <phonebook> &l)
{
    std::fstream fs;
    std::string line,word,w;
    fs.open("source.csv",std::ios::in);
    while(std::getline(fs,line))
    {
        std::stringstream ss(line);
        std::getline(ss,word,'|');
        std::getline(ss,w,'|');
        phonebook b{word,w};
        l.push_back(b);
    }
    fs.close();
}


void show(std::list <phonebook> &b)
{
    std::cout<<"===================================================="<<std::endl;
    for(std::list <phonebook>::iterator i=b.begin();i!=b.end();i++)
    {
        std::cout<<i->name<<"\t"<<i->phone<<std::endl;
    }
    std::cout<<"===================================================="<<std::endl;
}

void search(std::list <phonebook> &b)
{
    std::string name;
    std::cout<<"Search name:";
    std::cin>>name;
    std::cout<<"----------------------------------------------"<<std::endl;
    std::cout<<name<<"\t";
    bool found=false;
    for(auto &x:b)
    {
        if(x.name==name)
        {
            std::cout<<x.phone<<std::endl;
            found=true;
            break;
        }
    }
    if(!found)
    {
        std::cout<<"Not found"<<std::endl;
    }
    std::cout<<"----------------------------------------------"<<std::endl;
}

int menu()
{
    int op;
    std::cout<<"1-Show Records"<<std::endl;
    std::cout<<"2-Search Record"<<std::endl;
    std::cout<<"3-Exit"<<std::endl;
    std::cout<<"Give option:";
    std::cin>>op;
    return op;
}

int main()
{
    std::list <phonebook> li;
    add_to_list(li);
    while(true)
    {
        switch(menu())
        {
            case 1:
               show(li);
               break;
            case 2:
               search(li);
               break;
            case 3:
              exit(EXIT_SUCCESS);
              break;
            default:
              std::cerr<<"Invallid input"<<std::endl;
        }
    }
    return 0;
}