#include "surf.hpp"
#include <string>
#define DAMPING_FACTOR 0.85
long seed=std::chrono::high_resolution_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

Surfer::Surfer(int rows,int columns):matrix(rows,columns) {}

Surfer::~Surfer() {}

int Surfer::go_to(int r)
{
    const int rw=this->getrows();
    std::vector <int> neibourghs=this->getNeibourghs(r);
    std::vector <int> nn=this->nonNeibourghs(r);
    std::uniform_real_distribution <double> dist(0.0,1.0);
    std::uniform_int_distribution <int> neibourghmove(0,neibourghs.size()-1);
    std::uniform_int_distribution <int> nonneibourghmove(0,nn.size()-1);
    int move;
    if(neibourghs.empty())
    {
        std::uniform_int_distribution <int> moves(0,rw-1);
        move=moves(eng);
        while(move==r)
        {
            move=moves(eng);
        }
    }
    int randomfactor=dist(eng);
    if(randomfactor<=1-DAMPING_FACTOR)
    {
       move=nn[nonneibourghmove(eng)];
    }
    else
    {
        move=neibourghs[neibourghmove(eng)];
    }
    return move;
}

std::vector <navigate> Surfer::random_surfer(int visitors,int iterations)
{
   std::vector <navigate> accusation;
   this->random_fill();
   std::uniform_int_distribution <int> d(0,this->getrows()-1);
   int temp;
   int *startingpoint=new int[visitors];
   for(int i=0;i<visitors;i++)
   {
       temp=d(eng);
       startingpoint[i]=temp;
       this->add_visit(temp);
   }
   int nextpage;
   for(int i=0;i<iterations;i++)
   {
      for(int j=0;j<visitors;j++)
      {
          nextpage=go_to(startingpoint[j]);
          navigate n{j,"Page "+std::to_string(startingpoint[j]),"Page "+std::to_string(nextpage)};
          startingpoint[j]=nextpage;
          this->add_visit(nextpage);
          accusation.push_back(n);
      }
   }
   delete []startingpoint;
   return accusation;
}

void Surfer::Page_rank()
{
    std::cout<<"\t\tPage Ranking"<<std::endl;
   std::cout<<"####################################################"<<std::endl;
   this->find_rank();
   this->show_ranking();
   std::cout<<"####################################################"<<std::endl;
}