#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <sstream>
#define LIMIT 1000

class random
{
    private:
      int randint;
      double randdouble;
      char randchar;
    public:
      random()
      {
          randint=rand()%LIMIT;
          std::mt19937 mt(time(nullptr));
          std::uniform_real_distribution <double> dist(0.0,1000.0);
          randdouble=(double)(rand())/RAND_MAX;
          randchar='A'+rand()%26;
      }
      ~random() {}
      operator std::string()
      {
          std::stringstream ss;
          ss<<this->randint<<"---"<<this->randdouble<<"-----"<<this->randchar;
          return ss.str();
      }
};

void save_to_file(random *defl,int size)
{
    std::string fn;
    std::cout<<"Give filename:";
    std::cin>>fn;
    std::ofstream in;
    in.open(fn,std::ios::out);
    in.precision(4);
    if(!in.is_open())
    {
        std::cerr<<"file did not open"<<std::endl;
    }
    in<<"########################################################"<<std::endl;
    for(int i=0;i<size;i++)
    {
        in<<std::string(defl[i])<<std::endl;
    } 
    in<<"########################################################"<<std::endl;
    in.close();
    std::cout<<"Randoms numbers have been on "<<fn<<std::endl;  
}

int main()
{
    random rands[20];
    std::cout.precision(4);
    std::cout<<"**************************************************"<<std::endl;
    for(int i=0;i<20;i++)
    {
        std::cout<<std::string(rands[i])<<std::endl;
    }
    std::cout<<"**************************************************"<<std::endl;
    save_to_file(rands,20);
    return 0;
}