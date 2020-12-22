#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <random>
#include <ctime>
#include <thread>

struct grank
{
   int page;
   double grade;
   bool operator<(const grank &g)const {return this->grade<g.grade;}
};

class matrix
{
    protected:
       int rows;
       int columns;
       int *p;
       int *visits;
       std::priority_queue <grank> rank;
    public:
      matrix(int r,int c);
      ~matrix();
      int getrows()const;
      int getcolumns()const;
      void add_visit(int r);
      void random_fill();
      std::vector <int> getNeibourghs(int row)const;
      std::vector <int> nonNeibourghs(int row)const;
      void find_rank();
      int * operator[](int r);
      void show_ranking();
      friend std::ostream &operator<<(std::ostream &os,const matrix &m);
};