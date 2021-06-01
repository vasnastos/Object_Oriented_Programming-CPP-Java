#include <iostream>
#include <fstream>
#include <vector>

void save_to_file(std::vector <int> &primes)
{
    std::ofstream os;
    std::string fn;
    std::cout<<"Give filename:";
    std::cin>>fn;
    os.open(fn);
    os<<"######################### Prime Numbers List ##############################"<<std::endl;
    for(std::vector <int>::iterator itr=primes.begin();itr!=primes.end();itr++)
    {
        os<<"Prime Number "<<itr-primes.begin()<<":"<<*itr<<std::endl;
    }
    os<<"###########################################################################"<<std::endl;
    os.close();
}

void find_primes(std::vector <int> &primes,int lw,int up)
{
  int counter;
  for(int i=lw;i<=up;i++)
  {
      if(i==2 || i==1) {continue;}
      counter=2;
      for(int j=2;j<=up;j++)
      {
          if(i==j) continue;
          if(i%j==0) {counter++;}
      }
      if(counter==2)
      {
          primes.push_back(i);
      }
  }
  save_to_file(primes);
}

int main()
{
    int lowerbound,upperbound;
    std::cout<<"Lower Bound:";
    std::cin>>lowerbound;
    std::cout<<"Upper Bound:";
    std::cin>>upperbound;
    std::vector <int> primes;
    find_primes(primes,lowerbound,upperbound);
    return 0;
}