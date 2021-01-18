#include <iostream>
#define LIMIT 30
#define SIZE 10

class Base
{
    protected:
      int ob;
    public:
      Base(int x):ob(x) {};
      virtual int get_Value()
      {
          return this->ob;
      }
};

class DerivedA:public Base{
    private:
       int intA;
    public:
      DerivedA(int x,int y):Base(x),intA(y) {}
      int get_Value()
      {
          return this->ob+this->intA;
      }
};

class DerivedB:public Base{
    private:
      int intA;
      int intB;
    public:
      DerivedB(int x,int y1,int y2):Base(x),intA(y1),intB(y2) {}
      int get_Value()
      {
          return this->ob+this->intA+this->intB;
      }
};

int main()
{
    Base *a[SIZE];
    int op;
    for(int i=0;i<SIZE;i++)
    {
        op=rand()%3;
        switch(op)
        {
            case 0:
               a[i]=new Base(rand()%LIMIT);
               break;
            case 1:
               a[i]=new DerivedA(rand()%LIMIT,rand()%LIMIT);
               break;
            case 2:
                a[i]=new DerivedB(rand()%LIMIT,rand()%LIMIT,rand()%LIMIT);
                break;
        }
    }
    for(int i=0;i<10;i++)
    {
        std::cout<<"Data Summary:"<<a[i]->get_Value()<<std::endl;
        delete a[i];
    }
    return 0;
}