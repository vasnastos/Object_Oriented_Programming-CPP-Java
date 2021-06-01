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
    bool operator>(const person &p)const
    {
       if(this->age>p.age)
       {
           return true;
       }
       else
       {
           return false;
       }
       //return age>p.age;
    }
    
    bool operator==(const person &p)const
    {
        return this->age==p.age && this->name==p.name;
    }
    
    void show()
    {
        cout<<this->name<<"\t"<<this->age<<endl;
        cout<<this<<endl;
    }
    friend ostream& operator<<(ostream &os,const person &p)//int x;cout<<x;
    {
        return os<<p.name<<"\t"<<p.age;
    }
    void dec() {this->age--;}
    friend void increase(person &p);
};

void increase(person &p)
{
    p.age++;
}


void decrease(person &p)
{
  p.dec();
}

//person::person():name(""),age(0) {}

int main()
{
    person p1;
    person p2("vasilis");
    person p3("Nikos",56);
    person p4("Nikos",56);
    p1.show();
    p2.show();
    p3.show();
    increase(p3);
    cout<<p3<<endl;//Nikos   57
    cout<<"operator > overloaded!!!!"<<endl<<endl;
    if(3>5) 
    {
        p1.show();
    }
    else
    {
        p3.show();
    }
    if(p3==p4)
    {
        cout<<"Equal objects"<<endl;
        p3.show();
        p4.show();
    }
    cout<<p1<<endl;
    cout<<p2<<endl;
}