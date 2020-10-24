#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#define size 8

class pair
{
    std::string key;
    double val;
    public:
     pair(std::string k,double v):key(k),val(v) {}
     ~pair() {}
     void set_pair(double val) {this->val=val;}
     double getValue()const {return this->val;}
     friend std::ostream &operator<<(std::ostream &os,const pair &p);
};

std::ostream &operator<<(std::ostream &os,const pair &p)
{
    os<<p.key<<"--"<<p.val;
    return os;
}

void increase_by_one(pair p)
{
  double val=p.getValue()+1;
  p.set_pair(val);
}

void decrease_by_one(pair *p)
{
    double val=p->getValue()+1;
    p->set_pair(val);
}

void increase_by_N(pair &p,double N)
{
    p.set_pair(p.getValue()+N);
}

void show_pairs(std::vector <pair> &pairs)
{
    for(auto &x:pairs)
    {
        double N=rand()%60;
        std::cout<<"Pair"<<x<<std::endl;
        increase_by_one(x);
        std::cout<<"Increase by one function:"<<x<<std::endl;
        decrease_by_one(&x);
        std::cout<<"decrease_by_one function:"<<x<<std::endl;
        increase_by_N(x,N);
        std::cout<<"increase by "<<N<<" function"<<x<<std::endl;
        std::cout<<"**************************************************************"<<std::endl<<std::endl;
        system("pause");
    }
}

int main(int argc,char **argv)
{
   std::vector <pair> pairs;
   std::mt19937 mt(time(nullptr));
   std::uniform_real_distribution <double> value(2,1600);
   std::uniform_int_distribution <int> len(4,9);
   std::uniform_int_distribution <int> lets(0,26);
   for(int i=0;i<size;i++)
   {
       std::string key="";
       int lngth=len(mt);
       for(int i=0;i<lngth;i++)
       {
           key+='A'+lets(mt);
       }
       pairs.push_back(pair{key,value(mt)});
   }
   show_pairs(pairs);
   return 0;
}