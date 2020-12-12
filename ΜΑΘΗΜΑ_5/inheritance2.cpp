#include <iostream>
#include <string>
#include <random>
#include <ctime>


class cloth
{
    protected:
      std::string id;
      int size;
      std::string type;
    public:
      cloth(std::string i,int s,std::string t):id(i),size(s),type(t) {}
      bool operator<(const cloth &c) {return this->size<c.size;}
      std::string to_String() {this->id+"--"+std::to_string(this->size)+"--"+this->type;}
      virtual void show()=0;
};

class tresours:public cloth
{
    private:
     int color;
    public:
      tresours(std::string i,int s,std::string t,int c):cloth(i,s,t),color(c) {}
      int getColor()const {return this->color;}
      std::string to_String() {return cloth::to_String()+"--"+std::to_string(this->color);}
      void show() {std::cout<<cloth::to_String()<<"--"<<this->color<<std::endl;}
};

class shoes:public cloth{
    int color;
    public:
      shoes(std::string i,int s,std::string t,int c):cloth(i,s,t),color(c) {}
      int getColor()const {return this->color;}
      void show()
      {
          std::cout<<cloth::to_String()<<"--"<<this->color<<std::endl;
      }
};

int main()
{
   cloth *c=new shoes("A1",45,"opened",1);
   //upcasting
   cloth *c1=new tresours("A2",34,"Athletic",3);

   std::vector <cloth *> clothes;
   std::mt19937 mt(time(nullptr));
   std::uniform_int_distribution <int> dist(0,1);
   std::uniform_int_distribution <int> size(30,50);
   std::uniform_int_distribution <int> color(1,20);
   for(int j=2;j<6;j++)
   {
       switch(dist(mt))
       {
           case 0:
             clothes.push_back(new tresours("A_"+std::to_string(i),size(mt),"C"+std::to_string(j),color(mt)));
             break;
           case 1:
             clothes.push_back(new shoes("A_"+std::to_string(i),size(mt),"C"+std::to_string(j),color(mt))));
             break;
       }
   }
   clothes.push_back(c);
   clothes.push_back(c1);
   for(auto &x:clothes)
   {
       x->show();
   }
   for(auto &x:clothes)
   {
       delete x;
   }
   delete c;
   delete c1;
   return 0;
}