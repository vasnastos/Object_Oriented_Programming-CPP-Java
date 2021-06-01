#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ostream>
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

class department
{
    private:
      int id;
      std::vector <employee> emps;
    public:
      department(int i):id(i) {}
      void add_employee(const employee &e)
      {
          this->emps.push_back(e);
      }
      int getId()const {return this->id;}
      void Print_Employees()
      {
         std::ostream_iterator <employee> out(std::cout,"\n");
         std::copy(this->emps.begin(),this->emps.end(),out);         
      }
};