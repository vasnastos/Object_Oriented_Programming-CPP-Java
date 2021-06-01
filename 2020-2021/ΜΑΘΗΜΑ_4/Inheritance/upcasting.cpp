#include <iostream>
#include <ctime>

int i=0;

class A
{
    protected:
      int id;
      double price;
    public:
      A(int id,double p):id(id),price(p) {i++;}
      void show() {std::cout<<this->id<<"\t"<<this->price<<std::endl;}
};

class B:public A{
    private:
      double factor;
    public:
     B(int id,double p,double f):A(id,p),factor(f) {i++;}
     void calculate()
     {
         this->price*=this->factor;
     }
     void show()
     {
         this->calculate();
         std::cout<<this->id<<"\t"<<this->price<<"--"<<this->factor<<std::endl;
     }
};

int main()
{
    srand(time(nullptr));
    A *object1=new A(i,rand()%700);
    B *object2=new B(i,rand()%700,(double)rand()/RAND_MAX);
    A *object3=new B(i,rand()%700,rand()/RAND_MAX);
    object1->show();
    object2->show();
    object3->show();
    A *array[5];
    for(int j=0;j<5;j++)
    {
        if(j%2==0)
        {
            //upcasting
            array[j]=new B(i,rand()%700,rand()/RAND_MAX);
        }
        else
        {
            array[j]=new A(i,rand()%700);
        }
    }
    for(int j=0;j<5;j++)
    {
        array[j]->show();
    }
    for(int j=0;j<5;j++)
    {
        delete array[j];
    }
    delete object1;
    delete object2;
    delete object3;
    return 0;
}