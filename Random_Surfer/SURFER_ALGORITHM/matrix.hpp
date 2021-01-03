#include <iostream>
#include <random>
#include <chrono>
#include <vector>

class matrix
{
    protected:
       int rows;
       int cols;
       int **p;
    public:
      matrix(int number_of_rows_cols);
      ~matrix();
      int size();
      int* get(int r);
      std::vector <int> getNeibourghs(int r);
      friend std::ostream &operator<<(std::ostream &os,const matrix &m);
};