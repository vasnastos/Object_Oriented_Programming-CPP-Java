/*
Στην παρούσα εργασία ζητείται η δημιουργία ενός προγράμματος σε C++ που να υλοποιεί δύο κλάσεις και να ελέγχει
μέσω συγκεκριμένων unit tests την ορθή λειτουργία τους. Ειδικότερα, ζητείται να συμπληρωθεί στο αρχείο
https://github.com/chgogos/oop/blob/master/lab2020/exercise1/account_bank.cpp ο κατάλληλος κώδικας έτσι
ώστε:
1. Να ορίζεται η κλάση account (λογαριασμός τράπεζας). Η κλάση account θα πρέπει να περιέχει τα ιδιωτικά
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
3. Χρησιμοποιώντας τη βιβλιοθήκη Catch2, συμπληρώστε τον απαιτούμενο κώδικα έτσι ώστε έτσι ώστε όλα τα
tests να περνούν με επιτυχία.
*/



#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <vector>

class account
{
private:
    std::string name;
    double balance;

public:
    account(std::string n):name(n),balance(0.0) {}

    account(std::string n, double initial_balance):name(n),balance(initial_balance) {}

    std::string get_name() const
    {
        return this->name;
    }

    double get_balance() const
    {
        return this->balance;
    }

    void deposit(double amount)
    {
        this->balance+=amount;
    }

    void withdraw(double amount)
    {
        if(amount>this->balance)
        {
            std::cerr<<"Not an acceptable transaction!!!"<<std::endl;
            return;
        }
        this->balance-=amount;
    }
};

class bank
{
private:
    std::vector <account> accounts;

public:
    void add_account(const account &acct)
    {
        this->accounts.push_back(acct);
    }

    double get_balance(std::string name) const
    {
        for(auto &x:this->accounts)
        {
            if(x.get_name()==name)
            {
                return x.get_balance();
            }
        }
        std::cerr<<"name "<<name<<" is not registered in the banksystem"<<std::endl;
        return -1.0;
    }

    void print_accounts() const
    {
        std::cout<<"      Accounts info  "<<std::endl;
        for(auto &x:this->accounts)
        {
            std::cout<<"Name:"<<x.get_name()<<"\t"<<"Balance:"<<x.get_balance()<<std::endl;
        }
    }

    void deposit(std::string name, double amount)
    {
        for(std::vector <account>::iterator itr=this->accounts.begin();itr!=this->accounts.end();itr++)
        {
            if(itr->get_name()==name)
            {
                itr->deposit(amount);
                return;
            }
        }
    }

    void withdraw(std::string name, double amount)
    {
        for(auto &x:this->accounts)
        {
           if(x.get_name()==name)
           {
               x.withdraw(amount);
               return;
           }
        }
    }

    void add_interest(double rate)
    {
        for(std::vector <account>::iterator itr=this->accounts.begin();itr!=this->accounts.end();itr++)
        {
            itr->deposit(rate*itr->get_balance()*0.01);
        }
    }
};

TEST_CASE("account class test 1", "[account]")
{
    account acct("Christos");
    REQUIRE(acct.get_name() == "Christos");
    REQUIRE(acct.get_balance() == 0.0);
    acct.deposit(50.0);
    REQUIRE(acct.get_balance() == 50.0);
}

TEST_CASE("account class test 2", "[account]")
{
    account acct("Vasilis", 100.0);
    REQUIRE(acct.get_name() == "Vasilis");
    REQUIRE(acct.get_balance() == 100.0);
    acct.withdraw(50.0);
    REQUIRE(acct.get_balance() == 50.0);
    acct.withdraw(70.0);
    REQUIRE(acct.get_balance() == 50.0);
}

TEST_CASE("bank class test", "[bank]")
{
    bank a_bank;
    for (int i = 0; i < 100; i++)
    {
        account acct("customer" + std::to_string(i), 100.0);
        a_bank.add_account(acct);
    }
    a_bank.deposit("customer42", 50.0);
    a_bank.withdraw("customer42", 10.0);
    REQUIRE(a_bank.get_balance("customer42") == 140.0);
    a_bank.add_interest(1.5);
    REQUIRE(a_bank.get_balance("customer46") == 101.5);
}
/*
int main()
{
    bank a_bank;

    account chr("Christos");
    account vas("Vasilis", 50.0);
    a_bank.add_account(chr);
    a_bank.add_account(vas);
    a_bank.print_accounts();

    a_bank.deposit("Christos", 10.0);
    a_bank.deposit("Vasilis", 10.0);
    a_bank.print_accounts();

    a_bank.add_interest(5.5);
    a_bank.print_accounts();

    return 0;
}
*/