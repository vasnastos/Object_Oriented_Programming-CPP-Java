#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <unordered_map>

std::unordered_map <std::pair<std::string,std::string>,double> board;
std::pair <std::string,std::string> connecteduser;

bool sign_in(std::string user,std::string pas)
{
  for(auto &x:board)
  {
      if(x.first.first==user && x.first.second==pas)
      {
          connecteduser=x;
          return true;
      }
  }
  return false;
}

int menu()
{
    int option;
    std::cout<<"********************************************************"<<std::endl;
    std::cout<<"\t1-Deposit Money"<<std::endl;
    std::cout<<"\t2-WithDraw Money"<<std::endl;
    std::cout<<"\t3-Show Balance"<<std::endl;
    std::cout<<"********************************************************"<<std::endl;
    std::cout<<"Select Option:";
    std::cin>>option;
    return option;
}

int main()
{
    std::mt19937 mt(time(nullptr));
    std::uniform_real_distribution <double> d(10,2000);
   for(int i=1;i<=10;i++)
   board.insert(std::make_pair(std::make_pair("user"+std::to_string(i),std::to_string(i)),d(mt)));
   std::string us;
   std::string p;
   double bal;
   bool logout=true; 
   while(true)
   {
       if(logout)
      {
          std::cout<<"Give username:";
          std::cin>>us;
          std::cout<<"Give you password";
          std::cin>>p;
        if(!sign_in(us,p))
        {
            std::cout<<"You are not authenticated!!!"<<std::endl;
            logout=true;
            continue;
        }
        logout=false;
      }
      int men=menu();
      switch(men)
      {
          case 1:
            std::cout<<"Give amount:";
            std::cin>>bal;
            d[connecteduser]+=bal;
            break;
          case 2:
            std::cout<<"Give amount:";
            std::cin>>bal;
            if(d[connecteduser]<bal)
            {
                d[connecteduser]=0;
            }
            break;
         case 3:
            std::cout<<"Amount:"<<d[connecteduser]<<std::endl;
         default:
          std::cerr<<"Invallid option"<<std::endl;
      }
      std::cout<<"execute Another transaction(y/n):";
      char x;
      std::cin>>x;
      if(std::tolower(x)=='y')
      {
          logout=false;
      }
   }
}