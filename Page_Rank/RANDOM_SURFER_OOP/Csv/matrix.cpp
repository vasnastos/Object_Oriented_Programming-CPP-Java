#include "matrix.hpp"
#include <string>
#include <numeric>

matrix::matrix(int r,int c):rows(r),columns(c)
{
    std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> dist(0,1);
    p=new int*[r];
    this->visits=new int[r];
    for(int i=0;i<r;i++)
    {
        this->visits[i]=0;
        p[i]=new int[r];
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==j)
            {
                p[i][j]=0;
                continue;
            }
            p[i][j]=dist(mt);
        }
    }
}

matrix::~matrix()
{
   for(int i=0;i<this->rows;i++)
   {
       delete[] p[i];
   }
   delete[] p;
   p=0;   
}

void matrix::reset_visits()
{
    for(int i=0;i<this->rows;i++)
    {
        this->visits[i]=0;
    }
}

int matrix::nrows()const {return this->rows;}
int matrix::ncols()const {return this->columns;}

std::vector <int> matrix::neiborghs(int r)
{
    std::vector <int> n;
    for(int j=0;j<this->columns;j++)
    {
        if(this->p[r][j]!=0)
        {
            n.push_back(j);
        }
    }
    return n;
}

std::string matrix::find_ranking()
{
  std::string result="";
  this->rank.clear();
  const int sum=std::accumulate(this->visits,this->visits+this->rows,0);
  for(int i=0;i<this->rows;i++)
  {
      this->rank.push_back(pagerank{i,(double)this->visits[i]/sum});
  }
  std::sort(this->rank.begin(),this->rank.end(),[](const pagerank &p1,const pagerank &p2) {return p1.grade>p2.grade;});
  int counter=1;
  for(auto &x:this->rank)
  {
      std::cout<<counter<<".Web Page "<<x.page<<"-->"<<x.grade<<std::endl;
      result+=std::to_string(counter)+".Web Page "+std::to_string(x.page)+"-->"+std::to_string(x.grade)+"\n";
      counter++;
  }
  std::cout<<std::endl;
  return result;
}