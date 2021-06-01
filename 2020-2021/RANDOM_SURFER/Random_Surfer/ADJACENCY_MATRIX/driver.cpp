#include "matrix.hpp"

int main()
{
    //Κατασκευή ένος πίνακα γειτνίασης με τυχαίες τιμές.
    matrix m(6);
    std::vector <int> neibourghs;
    std::cout<<m<<std::endl;
    std::cout<<"\t\tNeibourghs List"<<std::endl;
    std::cout<<"------------------------------------------------------"<<std::endl;
    for(int i=0,t=m.size();i<t;i++)
    {
        std::cout<<"Vertex "<<i+1<<"::";
        neibourghs=m.getNeibourghs(i);
        for(auto &y:neibourghs)
        {
            std::cout<<y<<"\t";
        }
        std::cout<<std::endl;
    }
    return 0;
}