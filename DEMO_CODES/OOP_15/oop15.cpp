/*
Να γραφεί οντότητα που να αναπαριστά μία εφαρμογή app με ιδιωτικά
μέλη:
   ● κωδικός εφαρμογής
   ● Όνομα παιχνιδιού
   ● Περιγραφή παιχνιδιού
   ● Κατηγορία παιχνιδιού
   ● Τιμή
   ● Αξιολογήσεις(Διάνυσμα που θα αποθηκεύει τις αξιολογήσεις χρηστών.)
  Να κατασκευαστούν τα ακόλουθα δημόσια μέλη:
  ● Να δημιουργηθεί κατασκευαστής που θα ορίζει όλο τα μέλη με τιμές.
  ● Να ορίζει getters για όλα τα πεδία.
  ● Να υπερφορτωθεί ο τελεστής << ώστε να εμφανίζει όλες τις πληροφορίες 
  για την εφαρμογή.
Να γραφεί οντότητα αξιολόγηση που θα περιέχει ιδιωτικά δεδομένα :
  ● Αξιολογητής
  ● σχόλια
  ● αστέρια
 Να κατασκευαστούν τα ακόλουθα δημόσια μέλη :
   ● κατασκευαστής που να ορίζει όλα τα πεδία
   ● getters για τα πεδία 
   ● Υπερφόρτωση του τελεστή <<.
Στην κύρια συνάρτηση 
  ● εισάγεται 10 εφαρμογές τις επιλογής σας.
  ● εισάγεται αξιολογήσεις για τις εφαρμογές.
  (Οι παραπάνω λειτουργικότητες μπορούν να εκτελεστούν και με εισαγωγή δεδομένων από αρχείο).
  ● εμφανίστε τις αναλυτικές πληροφορίες.
Το πρόγραμμα να εισάγει τα δεδομένα σε μία τοπική βάση δεδομένων.
Να εμφανίζει τα δεδομένα την βάση δεδομένων.
Να εισάγει δεδομένα από το αρχείο αν δεν υπάρχουν στην ΒΔ.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class evaluation;

std::string fn="data.txt";

class app
{
  std::string code;
  std::string appname;
  std::string description;
  std::string category;
  double price;
  std::vector <evaluation> evaluations;
  public:
    app(std::string c,std::string an,std::string des,std::string cat,double pr):code(c),appname(an),description(des),category(cat),price(pr) {}
    std::string get_codes()const {return this->code;}
    std::string get_appname()const {return this->appname;}
    std::string get_description()const {return this->description;}
    std::string get_category()const {return this->category;}
    std::string get_price()const {return this->price;}
    void add_evaluation(evaluation &evl) {this->evaluations.push_back(evl);}
    friend std::ostream &operator<<(std::ostream &os,const app &ap)
    {
      os<<ap.code<<"-"<<ap.appname<<"-"<<ap.description<<"-"<<ap.category<<"-"<<ap.price;
      return os;
    } 
};

class evaluation
{
  std::string evaluator;
  std::string comments;
  int stars;
  public:
  evaluation(std::string ev,std::string coms,int sts):evaluator(ev),comments(coms),stars(sts) {}
  std::string get_evaluator()const {return this->evaluator;}
  std::string get_comments()const {return this->comments;}
  int get_stars()const {return this->stars;}
  friend std::ostream &operator<<(std::ostream &os,const evaluation &ev)
  {
    os<<"User:"<<ev.evaluator<<std::endl;
    os<<"Comment:"<<ev.comments<<std::endl;
    for(int i=0;i<ev.stars;i++)
    {
      os<<"*";
    }
    os<<std::endl;
    return os;
  }
};

void read_apps(std::vector <app> &apps)
{
  std::ifstream is;
  is.open(fn,std::ios::in);
  if(!is.is_open())
  {
    std::cerr<<"No file opened!!!"<<std::endl;
    return;
  }
  std::string line,word;
  std::vector <std::string> data;
  int start=0;
  app *newapp=nullptr;
  while(std::getline(is,line))
  {
    if(line.size()==0)
    {
      continue;
    }
    if(line.at(0)=='#') {
      start++;
      if(start!=1)
      {
        apps.push_back(*newapp);
      }
      data.clear();
      std::stringstream ss(line);
       while(std::getline(ss,word,','))
       {
         data.push_back(word);
       }
       newapp=new app(data[0],data[1],data[2],data[3],std::stod(data[4]));
       continue;
    }
    data.clear();
    std::stringstream ss(line);
    while(std::getline(ss,word,','))
    {
      data.push_back(word);
    }
    evaluation ev(data[0],data[1],std::stoi(data[2]));
    newapp->add_evaluation(ev);
  }
  is.close();
}

void insertdata(std::vector <app> &apps)
{
  std::string cd,name,desc,cat;
  double prc;
  std::cout<<"Give code of app:";
  std::cin>>cd;
  std::cout<<"Give name of the app:";
  std::cin>>name;
  std::cout<<"Give description:";
  std::cin>>desc;
  std::cout<<"Give category of the app:";
  std::cin>>cat;
  std::cout<<"Price of the app:";
  std::cin>>prc;
  for(auto &x:apps)
  {
    if(x.get_codes()==cd)
    {
      std::cerr<<"App exists in the list of apps"<<std::endl;
      return;
    }
  }
  app newapp(cd,name,desc,cat,prc);
  apps.push_back(newapp);
}

void insert_evaluation(std::vector <app> &apps)
{
  int ev;
  std::string name,des;
  int stars;
  while(true)
  {
    int i=1;
    for(auto &x:apps)
    {
      std::cout<<i<<"."<<x.get_appname()<<std::endl;
    }
    int choice;
    std::cout<<"Select app:";
    std::cin>>choice;
    if(choice<=0 || choice>apps.size())
    {
      std::cerr<<"Invallid choice!!!"<<std::endl;
      continue;
    }
    int j=choice-1;
    std::cout<<"New Evaluation(0/no,1/yes):";
    std::cin>>ev;
    if(ev==0) {return;}
    std::cout<<"Give user name:";
    std::cin>>name;
    std::cout<<"Give description:";
    std::cin>>des;
    std::cout<<"Give stars:";
    std::cin>>stars;
    evaluation ev(name,des,stars);
    apps[j].add_evaluation(ev);
  }
}

//Μέρος 1 υλοποιήση κυρίων συναρτήσεων στα υπόλοιπα μέρη.