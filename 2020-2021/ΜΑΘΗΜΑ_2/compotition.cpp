/*
Να ορίζεται η κλάση account (λογαριασμός τράπεζας). Η κλάση account θα πρέπει να περιέχει τα ιδιωτικά
πεδία name (όνομα πελάτη) και balance (υπόλοιπο λογαριασμού), δύο constructors, getters για τα πεδία
name και balance, καθώς και μεθόδους για deposit (κατάθεση) ενός ποσού στον λογαριασμό και withdraw
(ανάληψη) ενός ποσού από τον λογαριασμό. Η μέθοδος withdraw θα πρέπει να ελέγχει έτσι ώστε να μην
επιτρέπει την ανάληψη μεγαλύτερου ποσού από το διαθέσιμο και σε περίπτωση που επιχειρηθεί κάτι τέτοιο
να εμφανίζει σχετικό μήνυμα.
2. Να ορίζεται η κλάση bank (τράπεζα) που να περιέχει έναν std::vector με λογαριασμούς. Συμπληρώστε τις
κατάλληλες μεθόδους έτσι ώστε:
  a. Να προστίθεται ένας λογαριασμός στην τράπεζα. Μέθοδος: add_account(account)
  b. Να εμφανίζονται όλοι οι λογαριασμοί. Μέθοδος: print_accounts()
  c. Να πραγματοποιείται κατάθεση ενός ποσού σε έναν λογαριασμό δεδομένου του ονόματος του
πελάτη. Μέθοδος: deposit(string, double)
  d. Να πραγματοποιείται ανάληψη ενός ποσού από έναν λογαριασμό δεδομένου του ονόματος του
πελάτη. Μέθοδος withdraw(string, double)
  e. Να αποδίδεταιτόκος βάσει ενός επιτοκίου και να προστίθεται στα υπόλοιπα όλων των λογαριασμών
της τράπεζας. Μέθοδος add_interest(double). Για παράδειγμα αν το επιτόκιο είναι 1,5% τότε η
μέθοδος θα καλείται ως bank_object.add_interest(1.5);
 Στην κύρια συνάρτηση να δημιουργηθούν 10 τυχαίοι λογοριασμοί και να προστεθούν σε ένα αντικείμενο τράπεζας,
 να εμφανιστούν όλοι οι λογαριασμοί και να προστεθεί σε λογαριασμό της επιλογής σας ένα ποσό της επιλογής σας 
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <random>

int seed()
{
  std::string time=__TIME__;
  std::string word;
  std::stringstream ss(time);
  std::vector <std::string> data;
  while(std::getline(ss,word,':')) {data.push_back(word);}
  return 3600*std::stoi(data[0])+60*std::stoi(data[1])+std::stoi(data[2]);
}

class account
{
  std::string name;
  double amount;
  public:
    account(std::string n):name(n),amount(0.0) {}
    account(std::string n,double b):name(n),amount(b) {}
    ~account() {}
    bool operator==(std::string n)
    {
      return this->name==n;
    }
    void deposit(double am) {this->amount+=am;}
    void withdraw(double am)
    {
      if(this->amount<am)
      {
        std::cerr<<"Invalid amount!!you can't withdraw this amount of money"<<std::endl;
        return;
      }
      this->amount-=am;
    }
    friend std::ostream &operator<<(std::ostream &os,const account &acc)
    {
      os<<"Name:"<<acc.name<<"\tBalance:"<<acc.amount;
      return os;

    }
};

class bank
{
  std::vector <account> accounts;
  public:
   bank() {}
   ~bank() {}
   void add_account(account &acc) {this->accounts.push_back(acc);}
   void print_accounts()
   {
     std::cout<<"*************************************************"<<std::endl;
     for(auto &x:this->accounts)
     {
       std::cout<<x<<std::endl;
     }
     std::cout<<"*************************************************"<<std::endl<<std::endl;
   }
   void deposit(std::string name,double amount)
   {
     for(auto &x:accounts)
     {
       if(x==name)
       {
           x.deposit(amount);
       }
     }
   }
   void withdraw(std::string name,double amount)
   {
     for(auto &x:this->accounts)
     {
       if(x==name)
       {
         x.withdraw(amount);
       }
     }
   }
};

int main(int argc,char **argv)
{
  bank bnk;
  std::mt19937 mt(seed());
  std::uniform_int_distribution <int> dist(0,20);
  std::uniform_real_distribution <double> balance(0,100000);
  std::string names[20]={"8746390786",
                         "6670784072",
                         "5454017819",
                         "0923399260",
                         "6832400034",
                         "2762840361",
                         "8553098282",
                         "4263025029",
                         "2497379467",
                         "1072368326",
                         "1116515793",
                         "6796515456",
                         "7913659819",
                         "7627541750",
                         "9282755642",
                         "1679542437",
                         "6507659905",
                         "7989624701",
                         "2945395412",
                         "5169886659"};
    for(int i=0;i<10;i++)
    {
      account ac(names[dist(mt)],balance(mt));
      bnk.add_account(ac);
    }
    bnk.print_accounts();
    bnk.deposit("7913659819",150);
    bnk.deposit("5169886659",260);
    bnk.withdraw("7913659819",67.89);
    bnk.print_accounts();
}