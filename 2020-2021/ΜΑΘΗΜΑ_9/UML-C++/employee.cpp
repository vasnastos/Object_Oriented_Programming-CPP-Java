#include <iostream>

class employee
{
    std::string name;
    int age;
    double salary;
    public:
      employee(std::string n,int a,double s):name(n),age(a),salary(s) 
      {}
      std::string getName()const {return this->name;}
      int getAge()const {return this->age;}
      double getSalary()const {return this->salary;}
      void info()
      {
         std::cout<<this->name<<"-"<<this->age<<"-"
          <<this->salary<<std::endl;
      }
      friend std::ostream &operator<<(std::ostream &os,const employee &e)
      {
          return os<<e.name<<"-"<<e.age<<"-"<<e.salary<<std::endl;
      }
};