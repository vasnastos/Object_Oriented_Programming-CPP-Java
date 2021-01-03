#include "matrix.hpp"

std::priority_queue <grank> matrix::rank;

matrix::matrix(int r, int c) : rows(r), columns(c)
{
    if(r==0)
    {
        p=nullptr;
        visits=nullptr;
        return;
    }
    this->p = new int[r*c];
    this->visits=new int[r];
    for(int i=0;i<this->rows;i++)
    {
        this->visits[i]=0;
        for(int j=0;j<this->columns;j++)
        {
            this->p[i*r+j]=0;
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
        if(this->p[i+row*this->rows]!=0)
        {
            n.push_back(i);
        }
    }
    return n;
}

void matrix::find_rank()
{
    while(!matrix::rank.empty())
    {
        matrix::rank.pop();
    }
   const int size=this->rows*this->columns;
   for(int i=0;i<this->rows;i++)
   {
       grank g{i,(double)this->visits[i]/size};
       matrix::rank.push(g);
   }
}

void matrix::clear()
{
    while(!this->rank.empty())
    {
        this->rank.pop();
    }
    if(this->p!=nullptr && this->visits!=nullptr)
    {
         delete[] this->p;
         delete[] this->visits;
    }
}

void matrix::random_fill()
{
    std::mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> pr(0,1);
    for(int i=0;i<this->rows;i++)
    {
        for(int j=0;j<this->columns;j++)
        {
            if(i==j) continue;
            else
            this->p[i*this->rows+j]=pr(mt);
        }
    }
}

std::vector <int> matrix::nonNeibourghs(int row)const
{
    std::vector <int> nn;
    for(int i=0;i<this->columns;i++)
    {
        if(this->p[row*this->rows+i]==0)
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