#include "matrix.hpp"

matrix::matrix(int r, int c) : rows(r), columns(c)
{
    this->p = new int[r*c];
    this->visits=new int[r];
    for(int i=0;i<this->rows;i++)
    {
        this->visits[i]=0;
        for(int j=0;j<this->columns;j++)
        {
            this->p[i+j]=0;
        }
    }
}

void matrix::add_visit(int r)
{
    this->visits[r]++;
}

matrix::~matrix() {delete []this->p; this->p=0; delete []this->visits; this->visits=0;}

int matrix::getrows()const { return this->rows; }

int matrix::getcolumns()const { return this->columns; }

std::vector <int> matrix::getNeibourghs(int row)const
{
    std::vector <int> n;
    for(int i=0;i<this->columns;i++)
    {
        if(this->p[i+row]!=0)
        {
            n.push_back(i);
        }
    }
    return n;
}

void matrix::find_rank()
{
   const int size=this->rows*this->columns;
   for(int i=0;i<this->rows;i++)
   {
       grank g{i,(double)this->visits[i]/size};
       this->rank.push(g);
   }
}

void matrix::show_ranking()
{
   std::vector <grank> temporary;
   int i=1;
   while(!this->rank.empty())
   {
       grank temp=this->rank.top();
       temporary.push_back(temp);
       std::cout.precision(4);
       std::cout<<i<<"."<<"Page "<<temp.page<<"----"<<"Grade:"<<temp.grade<<std::endl;
       i++;
       this->rank.pop();
   }
   for(auto &x:temporary)
   {
       this->rank.push(x);
   }
}

void matrix::random_fill()
{
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> pr(0.0,1.0);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->columns;j++)
        {
            if(i==j) continue;
            this->p[i+j]=pr(mt);
        }
    }
}

std::vector <int> matrix::nonNeibourghs(int row)const
{
    std::vector <int> nn;
    for(int i=0;i<this->columns;i++)
    {
        if(this->p[i+row*this->rows]==0)
        {
            if(i==row) continue;
            nn.push_back(i);
        }
    }
    return nn;
}

std::ostream &operator<<(std::ostream &os, const matrix &m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            os << m.p[i*m.rows+j] << " ";
        }
        os << std::endl;
    }
    return os;
}

int* matrix::operator[](int r)
{
    return this->p+r * this->columns;
}