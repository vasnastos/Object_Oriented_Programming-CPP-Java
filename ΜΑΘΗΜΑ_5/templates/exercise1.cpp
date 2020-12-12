#include <iostream>
#include <vector>

class student
{
    std::string name;
    double grade;
    public:
     student(std::string n,double g):name(n),grade(g) {k++;}
     //>
     bool operator>(const student &s)const 
     {
         return this->grade>s.grade;
     }
     friend std::ostream &operator<<(std::ostream &os,const student &s)
     {
         return os<<s.name<<"\t"<<s.grade;
     }
};

template <class T>void max_elements(std::vector <T> &vec,T &max1,T &max2)
{
    max1=vec.at(0);//vec[i];
    max2=max1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>max1)
        {
            max1=vec[i];
        }
    }
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]>max2 && vec1[i]!=max1)
        {
            max2=vec[i];
        }
    }
}

int main()
{
    std::cout<<student::k;
    std::vector <int> integers{4,7,8,12,45,67,51,2,9};
    integers.push_back(7);
    std::vector <student> students{{"nikos",8},{"kostas",9},{"vasilis",7},{"Maria",5}};
    students.push_back(student("Dimitris",8));
   int max1,max2;
   max_elements(integers,max1,max2);
   std::cout<<"from vector integers max1="<<max1<<"\tmax2="<<max2<<std::endl;  
}