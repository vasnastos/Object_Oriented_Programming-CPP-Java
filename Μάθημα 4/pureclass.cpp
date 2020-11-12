#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>

#define colorssize 10
std::string colors[colorssize]{"Red","Green","Cyan","Blue","Yellow","Black","Purple","Pink","Brown","Magenta"};
int i=1;

class shape
{
    protected:
      std::string color;
      int id;
    public:
     shape(std::string s):color(s),id(i) {i++;}
     virtual ~shape() {}
     virtual double area()=0;
     virtual void show()=0;
     //abstract class
};

class square:public shape{
    private:
      double side;
    public:
      square(double sd,std::string s):side(sd),shape(s) {}
      ~square() {}
      double area()
      {
          return this->side * this->side;
      }
      void show()
      {
          std::cout<<"Color:"<<this->color<<"\tId:"<<this->id<<"\tSide:"<<this->side<<std::endl;
      }
};

class rectangle:public shape{
    private:
      double width;
      double height;
    public:
      rectangle(double w,double h,std::string c):width(w),height(h),shape(c) {}
      ~rectangle() {}
      void show()
      {
         std::cout<<"Color:"<<this->color<<"\tId:"<<this->id<<"\tWidth:"<<this->width<<"\tHeight:"<<this->height<<std::endl;
      }
      double area()
      {
          return this->width*this->height;
      }
};

void showShape(shape *s,int j)
{
  std::cout<<"**************** Shape "<<j<<" *************************"<<std::endl;
  std::cout<<" ->";
  s->show();
  std::cout<<"\t\t#Area:"<<s->area()<<std::endl;
  std::cout<<"****************************************************"<<std::endl<<std::endl;
}

int main()
{
  std::vector <shape*> randomshapes;
  std::mt19937 mt(time(nullptr));
  std::uniform_int_distribution <int> size(5,20);
  std::uniform_int_distribution <int> choice(1,2);
  std::uniform_int_distribution <int> color(0,9);
  std::uniform_real_distribution <double> input(3,30);
  const int length=size(mt);
  for(int i=0;i<length;i++)
  {
    switch(choice(mt))
    {
      case 1:
        randomshapes.push_back(new square(input(mt),colors[color(mt)]));
        break;
      case 2:
        randomshapes.push_back(new rectangle(input(mt),input(mt),colors[color(mt)]));
        break;
    }
  }
  std::sort(randomshapes.begin(),randomshapes.end(),[](shape *s1,shape *s2) {return s1->area()<s2->area();});
  std::cout.precision(4);
  int j=1;
  for(auto &x:randomshapes)
  {
      showShape(x,j);
      j++;   
  }
  for(auto &x:randomshapes)
  {
    std::cout<<"Memory freed:"<<x<<std::endl;
    delete x;
  }
  return 0;
}