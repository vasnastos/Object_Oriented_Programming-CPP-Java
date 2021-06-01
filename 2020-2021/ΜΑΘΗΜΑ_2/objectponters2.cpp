#include <iostream>
#include <vector>
#include <sstream>
#include <random>

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::vector <std::string> data;
    std::string word;
    while(std::getline(ss,word,':')) {data.push_back(word);}
    return std::stoi(data[0])*3600+std::stoi(data[1])*60+std::stoi(data[2]);
}

class object
{
   int x;
   int size;
   std::string *k=nullptr;
       void genarate_board()
      {
          std::mt19937 mt(seed());
          std::uniform_int_distribution <int> dist(4,10);
          std::uniform_int_distribution <int> lets(0,26);
          for(int i=0;i<this->size;i++)
          {
             k[i]="";
             int length=dist(mt);
             for(int j=0;j<length;j++)
             {
                 k[i]+='A'+lets(mt);
             }
          }
      }
   public:
      object(int a,int b):x(a),size(b),k(new std::string[b]) {this->genarate_board();}
      ~object() {delete[] k;}
      void print_stats()
      {
          std::cout<<"Number:"<<this->x<<std::endl;
          std::cout<<"Random Strings::"<<std::endl;
          for(int i=0;i<this->size;i++)
          {
              std::cout<<"String:"<<this->k[i]<<std::endl;
          }
          std::cout<<"********************************************************************************"<<std::endl<<std::endl;
      }
};

void free_mem(std::vector <object *> &objs)
{
    for(auto &x:objs)
    {
        delete x;
    }
}

int main(int argc,char **argv)
{
    std::vector <object*> objs;
   std::mt19937 machine(seed());
   std::uniform_int_distribution <int> nums(6,19);
   int total=nums(machine);
   for(int i=0;i<total;i++)
   {
       object *obj=new object(i+1,nums(machine));
       objs.push_back(obj);
   }
    for(auto &x:objs)
   {
       x->print_stats();
   }
    free_mem(objs);
    return 0;
}