#include <iostream>
using namespace std;

class person
{
   string name;
   int age;
  public:
  //person();
    person() {
        name="";
        age=0;
    }
    person(string n):name(n),age(8) {}
    person(string n,int a):name(n),age(a) {}
    void show()
    {
        cout<<this->name<<"\t"<<this->age<<endl;
        cout<<this<<endl;
    }
};

//person::person():name(""),age(0) {}

int main()
{
    //person p1,p2,p3;
    person p1;
    person p2("vasilis");
    person p3("Nikos",56);
    p1.show();
    p2.show();
    p3.show();
}