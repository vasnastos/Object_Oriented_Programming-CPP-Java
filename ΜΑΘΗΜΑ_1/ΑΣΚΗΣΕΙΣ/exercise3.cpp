#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include <sstream>
#define SIZE 10
using namespace std;

int seed()
{
    string time=__TIME__;
    string word;
    stringstream ss(time);
    while(getline(ss,word,':')) {}
    return stoi(word);
}

class point
{
    private:
     int x,y;
    public:
      point(int val1,int val2):x(val1),y(val2) {}
      ~point() {}
      double get_distance(const point &p)
      {
          double diff=(pow(this->x,2)-pow(p.x,2))+(pow(this->y,2)-pow(p.y,2));
          if(diff<0)
          {
              diff=-diff;
              return -sqrt(diff);
          }
          return sqrt(diff);
      }
      bool operator<(point &p) {return this->x * this->y>p.x*p.y;}
      bool operator==(const point &p)const {return this->x==p.x && this->y==p.y;}
      friend ostream &operator<<(ostream &os,const point &p)
      {
          os<<"("<<p.x<<","<<p.y<<")";
          return os;
      }
};

void print_distances(std::vector <point> &points)
{
    ofstream os;
    os.open("distances.txt");
    for(auto &x:points)
    {
        os<<"************** Check point:"<<x<<" ******************"<<endl;
        for(auto &y:points)
        {
            if(x==y) {continue;}
            os<<"-->"<<y<<":"<<x.get_distance(y)<<endl;
        }
        os<<"***********************************************************"<<endl<<endl;
    }
    os.close();
}

int main()
{
    std::vector <point> points;
   mt19937 mt(seed());
   uniform_int_distribution <int> pnts(0,200);
   for(int i=0;i<SIZE;i++)
   {
      point p(pnts(mt),pnts(mt));
      points.push_back(p);
   }
   print_distances(points);
   return 0;
}