#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <random>

std::string types[]{"T1","T2"};

int get_flight_duration(std::string from, std::string to, std::string airplane_type)
{
    std::string data[5][4] = {
        {"A", "B", "T1", "200"},
        {"A", "B", "T2", "180"},
        {"A", "C", "T1", "150"},
        {"A", "C", "T2", "140"},
        {"A", "D", "T2", "240"},
    };
    for (int i = 0; i < 5; i++)
    {
        if (data[i][2] == airplane_type)
        {
            return std::stoi(data[i][3]);
        }
    }
    return -1;
}

class flight
{
private:
    int flight_number;
    std::string from;
    std::string to;
    int duration;

public:
    flight(int fn, std::string f, std::string t, std::string airplane_type) : flight_number(fn), from(f), 
    to(t),duration(get_flight_duration(f,t,airplane_type)) {}
    void delay_flight(int minutes) {this->duration+=minutes;}
    void display()
    {
        std::cout<<this->flight_number<<"--"<<this->from<<"--"<<this->to<<"--"<<this->duration<<std::endl;
    }
};

class plane
{
    std::string airplane_type;
    int max_speed;
    std::string tail_id;
    std::vector <flight> flights;
    public:
      plane(std::string type,int ms,std::string tid):airplane_type(type),max_speed(ms),tail_id(tid) {}
      void add_flight(flight aflight) {this->flights.push_back(aflight);}
      std::string getPlaneType()const {return this->airplane_type;}
      void diplay()
      {
          std::cout<<this->airplane_type<<"--"<<this->max_speed<<"--"<<this->tail_id<<std::endl;
          std::cout<<"----------------------------------------------------------------"<<std::endl;
          std::cout<<"\tFlights "<<std::endl;
          for(auto &x:flights)
          {
             x.display();
          }
          std::cout<<std::endl;
      }
};
size_t hash(int val)
{
   size_t t=0;
   t=val%120;
   t+=val+'A';
   t+=val%10;
   return t;
}
std::string towns[]={"Athens","London","Paris","Berlin","Turin","Brazilia","Miami","Boston"};

int main()
{
  std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
  std::vector <plane> lplanes;
  std::uniform_int_distribution <int> flights(3,12);
  std::uniform_int_distribution <int> planes(3,12);
  std::uniform_int_distribution <int> duration(30,450);
  std::uniform_int_distribution <int> speed(100,3000);
  std::uniform_int_distribution <int> t(0,sizeof(towns)/sizeof(towns[0])-1);
  std::uniform_int_distribution <int> atype(0,1);
  for(int j=1;j<=7;j++)
  {
     lplanes.push_back(plane(types[atype(mt)],speed(mt),"IDTP"+std::to_string(j)));
  }
  std::uniform_int_distribution <int> pos(0,lplanes.size()-1);
  int k;
  for(int j=1;j<=20;j++)
  {
      k=pos(mt);
      std::string fromtown=towns[t(mt)];
      std::string totown=towns[t(mt)];
      while(fromtown==totown)
      {
          totown=towns[t(mt)];
      }
     lplanes[k].add_flight(flight(hash(k*j),fromtown,totown,lplanes[k].getPlaneType()));
  }
  for(auto &x:lplanes)
  {
      x.diplay();
  }
  return 0;
}