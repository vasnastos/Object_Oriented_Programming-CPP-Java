#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

class actor
{
   private:
      std::string name;
      int age;
      std::string birthdate;
      double salary;
    public:
     actor(std::string n,int a,std::string bd,double s):name(n),age(a),birthdate(bd),salary(s) {}
     ~actor() {}
     double getsalary() {return this->salary;}
     friend std::ostream &operator<<(std::ostream &os,const actor &ac)
     {
         return os<<ac.name<<"--"<<ac.age<<"--"<<ac.birthdate<<"--"<<ac.salary;
     }
};

double sum(actor &ac,double s)
{
    return s+ac.getsalary();
}

class movie
{
  std::string title;
  int year;
  std::vector <actor> actors;
  public:
   movie(std::string t,int y):title(t),year(y) {}
   ~movie() {}
   movie operator+=(const actor &ac)
   {
       this->actors.push_back(ac);
       return *this;
   }
   double getbudget()
   {
      //return std::accumulate(this->actors.begin(),this->actors.end(),0,sum)/this->actors.size();
      double sum=0.0;
      for(auto &x:this->actors)
      {
          sum+=x.getsalary();
      }
      return sum;
   }
   friend std::ostream &operator<<(std::ostream &os,movie &m)
   {
       os<<"********************************************************************************"<<std::endl;
       os<<"\tTitle:"<<m.title<<"\t"<<"Year:"<<m.year<<std::endl;
       for(std::vector <actor>::iterator itr=m.actors.begin();itr!=m.actors.end();itr++)
       {
           os<<"\t"<<(*itr)<<std::endl;
       }
       os<<std::endl<<"Total Budget:"<<m.getbudget()<<std::endl;
       os<<"********************************************************************************"<<std::endl;
       return os;
   }
};

void sort_and_show(std::vector <movie> movies)
{
    std::sort(movies.begin(),movies.end(),[](movie &m1,movie &m2) {return m1.getbudget()<m2.getbudget();});
    for(std::vector <movie>::iterator itr=movies.begin();itr!=movies.end();itr++)
    {
        std::cout<<*itr<<std::endl<<std::endl;
    }
}

void run()
{
    std::vector <movie> movies;
    movie mov("Title_1",2020);
    movie mov1("title_new",2017);
    movie mov2("Title_2",2005);
    actor ac1("actor_1",35,"02/10/1985",2000);
    actor ac2("actor_2",38,"09/02,1982",5000);
    actor ac3("actor_3",45,"05/12/1975",1900);
    actor ac4("actor_4",19,"15/07/2001",800);
    actor ac5("actor_5",61,"21/05/1959",10000);
    actor ac6("actor_6",43,"30/11/1977",5690.76);
    actor ac7("actor_7",42,"19/02/1978",9100);
    actor ac8("actor_8",33,"25/03/1987",3098.13);
    mov+=ac1;
    mov+=ac2;
    mov+=ac7;
    mov+=ac5;
    mov1+=ac2;
    mov1+=ac4;
    mov1+=ac8;
    mov2+=ac4;
    mov2+=ac3;
    mov2+=ac7;
    mov2+=ac6;
    mov+=ac6;
    movies.push_back(mov);
    movies.push_back(mov1);
    movies.push_back(mov2);
    sort_and_show(movies);
}

int main()
{
    run();
    return 0;
}