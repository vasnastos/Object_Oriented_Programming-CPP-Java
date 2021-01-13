#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <vector>
//   1    2   3
//1  0    1
//2  1         1
//3

struct pagerank
{
   int page;
   double grade;
};


class matrix
{
   protected:
      int rows;
      int columns;
      int **p;
      int *visits;
      std::vector <pagerank> rank;
   public:
      matrix(int r,int c);
      ~matrix();
      void reset_visits();
      int nrows()const;
      int ncols()const;
      std::vector <int> neiborghs(int r);
      //Βαθμός των ιστοσελίδων
      std::string find_ranking();
};