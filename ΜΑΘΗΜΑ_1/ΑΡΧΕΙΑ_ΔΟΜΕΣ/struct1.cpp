#include <iostream>
#include <vector>

using namespace std;

struct person
{
  string name;
  int age;
  char gender;
  void print()
  {
      cout<<this->name<<"-"<<this->gender<<"-"<<this->age<<endl;
  }
};

bool operator<(const person &p1,const person &p2)const
{
    return p1.name<p2.name;
}

void readdata(person *pers)
{
    ifstream is;
    string word,line;
    is.open("persons.txt");
    vector <string> data;
    int i=0;
    while(getline(is,line))
    {
        data.clear();
        stringstream ss(line);
        while(ss,word,',')
        {
            data.push_back(word);
        }
        pers[i].name=data[0];
        pers[i].age=stoi(data[1]);
        pers[i].gender=data[2].at(0);
        i++;
    }
    is.close();
}

void sort(person *start,person *end)
{
    for(auto itr=start;itr!=end;itr++)
    {
        for(auto temp=start;temp!end-1;temp++)
        {
            if(*temp<*(temp+1))
            {
                person p=*temp;
                *temp=*(temp+1);
                *(temp+1)=p;
            }
        }
    }
}

void printboard(person *pers,int size)
{
    for(int i=0;i<size;i++)
    {
        pers[i].print();
    }
}

int main()
{
    person persons[10];
    readdata(persons);
    printboard(persons);
    sort(persons,persons+10);
    cout<<"After Sort"<<endl;
    printboard(persons);
    return 0;
}