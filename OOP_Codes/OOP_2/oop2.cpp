/*
   Να κατασκευαστεί Πρόγραμμα Διαχείρισης τηλεφωνικού καταλόγου το οποίο θα εκτελεί τις παρακάτω λειτουργίες:
   Το phonebook να αναπαρασταθεί με τα παρακάτω δεδομένα(name(std::string),region(std::string),phone(std::string))
     •Εισαγωγή τηλεφώνων από αρχείο phonebook.txt.
     •Αναζήτηση ενός τηλεφωνικού αριθμού βάσει το όνομα.
     •Εμφάνιση όλων των εγγραφών ομαδοποιημένων βάση της περιοχής.
     •Εμφάνιση όλων των εγγραφών.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

class phone
{
    std::string name;
    std::string region;
    std::string ph;
    public:
       phone(std::string n,std::string r,std::string p):name(n),region(r),ph(p) {}
       std::string get_region() {return this->region;}
       std::string get_name()const {return this->name;}
       friend std::ostream& operator<<(std::ostream &os,const phone &p)
       {
           os<<p.name<<"--"<<p.region<<"--"<<p.ph;
           return os;
       } 
       operator std::string()
       {
           std::stringstream ss;
           ss<<this->name<<"--"<<this->region<<"--"<<this->ph;
           return ss.str();
       }
};


void read_data(std::vector <phone> &vec)
{
    std::ifstream fin;
    std::string line;
    std::string word;
    std::vector <std::string> data;
    fin.open("contacts.csv");
    int counter=0;
    while(std::getline(fin,line))
    {
        counter++;
        if(counter==1) 
        {
            continue;
        }
        data.clear();
        std::stringstream ss(line);
        while(std::getline(ss,word,','))
        {
           data.push_back(word);
        }
        phone p(data[0],data[1],data[2]);
        vec.push_back(p);
    }
    fin.close();
}

int make_menu()
{
    int op;
    std::cout<<"1-Search by Name"<<std::endl;
    std::cout<<"2-Search by Region"<<std::endl;
    std::cout<<"3-Show Catalog"<<std::endl;
    std::cout<<"4-Exit Catlog"<<std::endl;
    std::cout<<"Give choice"<<std::endl;
    std::cin>>op;
    return op;
}

void show_by_name(std::vector <phone> &cat)
{
    std::string name;
    std::cout<<"Give Search Name:";
    std::cin>>name;
    bool f=false;
    for(auto &x:cat)
    {
        if(x.get_name()==name)
        {
            std::cout<<x<<std::endl;
            f=true;
            break;
        }
    }
    if(!f)
    {
       std::cout<<"Name:"<<name<<" did not found"<<std::endl;
    }
}

void show_by_region(std::vector <phone> &cat)
{
    std::string reg;
    std::cout<<"Give Search Region:";
    std::cin>>reg;
    bool f=false;
    std::cout<<"Info about region:"<<reg<<std::endl;
    for(auto &x:cat)
    {
        if(x.get_region()==reg)
        {
            std::cout<<x<<std::endl;
        }
    }
    std::cout<<std::endl;
    if(!f)
    {
        std::cerr<<"Invalid region!Region did not found catalog"<<std::endl;
    }
}

void show(std::vector <phone> &cat)
{
    std::cout<<"Phones List"<<std::endl;
   std::ostream_iterator <phone> output(std::cout,"\n");
   std::copy(cat.begin(),cat.end(),output);
   std::cout<<std::endl;
}

int main()
{
    std::vector <phone> catalog;
    read_data(catalog);
    std::cout<<"######## Demo Catalog Retrivied Csv Data information"<<std::endl;
    int menu;
    while(true)
    {
       menu=make_menu();
       if(menu==1)
       {
          show_by_name(catalog);
       }
       else if(menu==2)
       {
           show_by_region(catalog);
       }
       else if(menu==3)
       {
          show(catalog);
       }
       else if(menu==4)
       {
          exit(EXIT_SUCCESS);
       }
       else
       {
           std::cerr<<"Invalid choice try again!!!!!!"<<std::endl;
       }
       
    }
}