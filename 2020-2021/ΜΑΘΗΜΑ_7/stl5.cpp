#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <numeric>

class student
{
    std::string id;
    std::vector <double> grades;
    public:
     student(std::string id):id(id)
     {
         std::cout<<"student "<<this<<" created"<<std::endl;
     }
     bool operator<(const student &s)const {return this->average()>s.average();}
     void failsafe()
     {
         std::remove_if(this->grades.begin(),this->grades.end(),[](double &g) {return g<0 || g>10;});
     }
     int size()const {return this->grades.size();}
     void add_Student(double gr)
     {
         this->grades.push_back(gr);
     }
     double average()const 
     {
        return (double)std::accumulate(this->grades.begin(),this->grades.end(),0.0)/this->grades.size();
     }
     std::string getId()const {return this->id;}
     double get(int i)const {return this->grades.at(i);}
    
     friend std::ostream &operator<<(std::ostream &os,const student &s)
     {
         os.precision(3);
         os<<s.id<<"\t";
         for(auto &x:s.grades)
         {
             os<<x<<"\t";
         }
         os<<s.average();
         return os;
     }
};

std::vector <std::string> split(std::string line)
{
    std::vector <std::string> data;
    std::string word;
    std::stringstream ss(line);
    while(std::getline(ss,word,','))
    {
      data.push_back(word);
    }
    return data;
}

void read_data(std::map <student,std::string> &total)
{
    std::fstream fs;
    fs.open("students.txt",std::ios::in);
    std::string line;
    std::vector <std::string> data;
    while(std::getline(fs,line))
    {
        data=split(line);
        if(data.empty()) continue;
        student s(data[0]);
        for(int i=1,t=data.size();i<t;i++)
        {
            s.add_Student(std::stod(data.at(i)));
        }
        total.insert(std::make_pair(s,std::to_string(s.average())+"/10.0"));
    }
    fs.close();
}



void show(std::map <student,std::string> &total,int size)
{
    for(std::map <student,std::string>::iterator i=total.begin();i!=total.end();i++)
    {
        std::cout<<i->first.getId()<<"\t";
        int j;
        int t;
        for(j=0,t=i->first.size();j<t;j++)
        {
            std::cout<<i->first.get(j)<<"\t";
        }
        while(j<size)
        {
            std::cout<<"-\t";
            j++;
        }
        std::cout<<i->second;
        std::cout<<std::endl;
    }
}

int find_max_grades(std::map <student,std::string> &tlt)
{
    int max=-1;
    for(auto &x:tlt)
    {
        if(x.first.size()>max)
        {
            max=x.first.size();
        }
    }
    return max;
}

void header(std::map <student,std::string> &total)
{
  std::cout<<"ID\t";
  const int maximum=find_max_grades(total);
  for(int i=0;i<maximum;i++)
  {
      std::cout<<"Grade "+std::to_string(i+1)+"\t";
  }
  std::cout<<"Total"<<std::endl;
  show(total,maximum);
}

int main()
{
  std::map <student,std::string> total;
  read_data(total);
  header(total);
  return 0;
}