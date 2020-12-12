/*
Δημιουργήστε μία κλάση point με τα εξής δεδομένα:
   •x,y ακέραιες μεταβλητές

Η παραμετοποιήση τον μεταβλητών να γίνεται στον κατασκευαστή
Η κλάση να έχει μία μέθοδο get_distance η οποία θα βρίσκει την απόσταση 
μεταξύ δύο σημείων η οποία προκύπτει από τον τύπο:
sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)).
Να πραγματοποιηθεί υπερφόρτωση του τελεστή <<,ώστε να εκτυπώνει τα σημεία σε
μορφή (x,y).

Στην κύρια συνάρτηση να κατασκευαστούν 10 τυχαία σημεία και να εκτυπωθεί σε αρχείο
το αποτέλεσμα των αποστάσεων κάθε σημείου από τα υπόλοιπα.
*/

#include <iostream>
#include <cmath>
#include <random>
#include <fstream>
#include <sstream>
#include <vector>
#define SIZE 10

int seed()
{
    std::string time=__TIME__;
    std::stringstream ss(time);
    std::string word;
    while(std::getline(ss,word,':')) {}
    return std::stoi(word);
}

class point
{
    int x,y;
    public:
      point(int k,int l):x(k),y(l) {}
      double get_distance(const point &p)
      {
         return sqrt(pow((this->x-p.x),2)+pow((this->y-p.y),2));
      }
      bool operator==(const point &p)const {return this->x==p.x && this->y==p.y;}
      friend std::ostream &operator<<(std::ostream &os,const point &p)
      {
          os<<"("<<p.x<<","<<p.y<<")";
          return os;
      }
};

int main()
{
  std::mt19937 mt(seed());
  std::uniform_int_distribution <int> pnts(0,200);
  std::vector <point> points;
  for(int i=0;i<SIZE;i++)
  {
      points.push_back(point(pnts(mt),pnts(mt)));
  }
  std::ofstream out;
  std::string fn;
  std::cout<<"Give filename:";
  std::cin>>fn;
  out.open(fn,std::ios::out);
  out.precision(4);
  for(auto &x:points)
  {
      out<<"*************** "<<x<<" *******************"<<std::endl;
      for(std::vector <point>::iterator itr=points.begin();itr!=points.end();itr++)
      {
          if(*itr==x) {continue;}
         out<<"-"<<*itr<<"->"<<x.get_distance(*itr)<<std::endl;
      }
      out<<"***************************************"<<std::endl<<std::endl;
  }
  out.close();
  return 0;
}