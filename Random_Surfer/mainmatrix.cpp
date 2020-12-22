#include "matrix.hpp"
#define DAMPING_FACTOR 0.85

std::mt19937 enginee(time(nullptr));

int go_to(const matrix &m,int r)
{
    const int rw=m.getrows();
    std::vector <int> neibourghs=m.getNeibourghs(r);
    std::vector <int> nn=m.nonNeibourghs(r);
    std::uniform_real_distribution <double> dist(0.0,1.0);
    std::uniform_int_distribution <int> neibourghmove(0,neibourghs.size()-1);
    std::uniform_int_distribution <int> nonneibourghmove(0,nn.size()-1);
    int move;
    if(neibourghs.empty())
    {
        std::uniform_int_distribution <int> moves(0,r-1);
        move=moves(enginee);
        while(move==r)
        {
            move=moves(enginee);
        }
    }
    int randomfactor=dist(enginee);
    if(randomfactor<=1-DAMPING_FACTOR)
    {
       move=nn[nonneibourghmove(enginee)];
    }
    else
    {
        move=neibourghs[neibourghmove(enginee)];
    }
    return move;
} 

void random_surfer(matrix &m,int visitors,int N)
{
   m.random_fill();
   std::cout<<"\t\tBoard visualization"<<std::endl;
   std::cout<<"---------------------------------------------------"<<std::endl;
   std::cout<<m<<std::endl;
   std::cout<<"---------------------------------------------------"<<std::endl;
   std::uniform_int_distribution <int> d(0,m.getrows()-1);
   int temp;
   int *startingpoint=new int[visitors];
   for(int i=0;i<visitors;i++)
   {
       temp=d(enginee);
       startingpoint[i]=temp;
       m.add_visit(temp);
   }
   std::cout<<"Random Surfer Algorithm"<<std::endl;
   std::cout<<"-----------------------------------------------------------------"<<std::endl;
   int nextpage;
   for(int i=0;i<N;i++)
   {
      for(int j=0;j<visitors;j++)
      {
          nextpage=go_to(m,startingpoint[j]);
          std::cout<<"Visitor "<<j<<" goes from page "<<startingpoint[j]<<" to page "<<nextpage<<std::endl;
          startingpoint[j]=nextpage;
          m.add_visit(nextpage);
      }
      std::cout<<std::endl<<std::endl;
      std::this_thread::sleep_for(std::chrono::seconds(3));
   }
   std::cout<<"-----------------------------------------------------------------"<<std::endl;
   delete []startingpoint;
}

void Page_rank(matrix &m)
{
    std::cout<<"\t\tPage Ranking"<<std::endl;
    std::cout<<std::endl<<"***************************************************"<<std::endl;
    m.find_rank();
    m.show_ranking();
    std::cout<<"***************************************************"<<std::endl;
}

int main()
{
    int vs;
    int iterations;
    int number_of_pages;
    std::cout<<"Give number of visitors:";
    std::cin>>vs;
    std::cout<<"Give number of iterations:";
    std::cin>>iterations;
    std::cout<<"Number of pages:";
    std::cin>>number_of_pages;
    matrix m(number_of_pages,number_of_pages);
    random_surfer(m,vs,iterations);
    std::cout<<std::endl;
    Page_rank(m);
    return 0;
}