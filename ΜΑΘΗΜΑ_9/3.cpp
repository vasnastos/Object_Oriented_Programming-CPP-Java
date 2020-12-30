#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <random>
#define SIZE 10

class account
{
    std::string name;
    double balance;
    public:
      account(std::string name):name(name) {}
      double getBalance()const {return this->balance;}
      void deposit(double amount)
      {
          this->balance+=amount;
      }
      bool withdraw(double amount)
      {
          if(amount>this->balance)
          {
              return false;
          }
          else
          {
              this->balance-=amount;
              return true;
          }
      }
      void info()
      {
          std::cout<<"  "<<this->name<<"  \t"<<this->balance<<std::endl;
      }
};

int main()
{
    std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_real_distribution <double> amount(100,4000);
    std::vector <account> accounts;
    for(int i=0;i<SIZE;i++)
    {
        accounts.push_back(account("account"+std::to_string(i+1)));
    }
    std::uniform_int_distribution <int> pos(0,accounts.size()-1);
    for(int i=0;i<SIZE*SIZE;i++)
    {
        accounts[pos(mt)].deposit(amount(mt));
    }
    for(int i=0;i<SIZE+SIZE;i++)
    {
        std::cout<<std::boolalpha;
        std::cout<<accounts[pos(mt)].withdraw(amount(mt))<<" withdraw"<<std::endl;
    }
    std::cout<<"\tAccounts List"<<std::endl;
    std::cout<<"-------------------------------------------------"<<std::endl;
    std::cout<<"     Name\tBalance"<<std::endl;
    for(account &acc:accounts)
    {
       acc.info();
    }
    return 0;
}