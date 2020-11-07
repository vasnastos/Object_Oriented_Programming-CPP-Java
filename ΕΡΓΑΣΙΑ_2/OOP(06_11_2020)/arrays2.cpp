#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <random>

class player
{
    std::string name;
    size_t score;
    public:
    static int cnt;
      player(std::string n="",size_t s=0):name(n),score(s) {cnt++;}
      ~player() {}
      player &operator=(const player &p)
      {
          this->name=p.name;
          this->score=p.score;
          return *this;
      } 
      static int objects() {return player::cnt;}
      friend std::ostream &operator<<(std::ostream &os,const player &p)
      {
          return os<<"Name:"<<p.name<<"\t"<<"Score:"<<p.score<<std::endl;
      }
};

int player::cnt=0;

int count_file_size()
{
    std::string fn="names.txt";
    std::ifstream is;
    is.open(fn);
    int counter=0;
    std::string line;
    while(std::getline(is,line))
    {
        counter++;
    }
    is.close();
    return counter;
}

void read_data(player *players,int size)
{
    std::ifstream is;
    std::string filename="names.txt";
    is.open(filename,std::ios::in);
    std::string line;
    std::string name;
    size_t score;
    int i=0;
    while(std::getline(is,line))
    {
        name=line.substr(0,line.find(','));
        line.erase(0,line.find(',')+1);
        score=std::stoll(line);
        players[i]=player(name,score);
        i++;
    }
    is.close();
}

void show(player *players,int size)
{
    for(int i=0;i<size;i++)
    {
        std::cout<<players[i]<<std::endl;
    }
}

int main()
{
   player *players;
   const int size=count_file_size();
   players=new player[size];
   std::cout<<"Objects created:"<<player::cnt<<std::endl;
   read_data(players,size);
   show(players,size);
   delete[] players;
   return 0;
}