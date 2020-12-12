#include "oop15.cpp"

int main(int argc,char **argv)
{
    int ch;
    int eval;
    std::vector <app> apps;
    while(true)
    {
        std::cout<<"Insert new app(0/no,1/yes):";
        std::cin>>ch;
        if(ch==0)
        {
            return 0;
        }
        insertdata(apps);
        std::cout<<"Evaluate an App(0/no,1/yes):";
        std::cin>>eval;
        if(eval==0) {continue;}
        insert_evaluation(apps);
    }
    for(auto itr=apps.begin();itr!=apps.end();itr++)
    {
        std::cout<<*itr<<std::endl;
    }
    return 0;
}