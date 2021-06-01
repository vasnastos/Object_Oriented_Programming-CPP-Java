#include <iostream>
#define LIMIT 40

int main()
{
    auto spaces=[](int l,int u) {
        int summary=0;
        for(int i=l;i<=u;i++)
        {
            summary+=i;
        }
        return summary;
    };
    int j=0;
    int l,u;
    while(j<3)
    {
        l=rand()%LIMIT;
        u=rand()%LIMIT;
        if(l>u)
        {
            std::swap(l,u);
        }
        std::cout<<"Summary:"<<spaces(l,u)<<std::endl;
        j++;
    }
    return 0;
}