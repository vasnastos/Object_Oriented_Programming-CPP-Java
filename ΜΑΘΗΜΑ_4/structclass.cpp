#include <iostream>

struct A
{
    std::string id;
    int price;
    void show() {std::cout<<id<<"\t"<<price<<std::endl;}
};
class B
{
    private:
      std::string id;
      int price;
    public:
      B(std::string i,int p):id(i),price(p) {}
      void show() {std::cout<<this->id<<"\t"<<this->price<<std::endl;}
};
int main()
{
    A *a=new A{"A1",2};
    B *b=new B("A2",3);
    a->show();
    b->show();
    delete a;
    delete b;
}
