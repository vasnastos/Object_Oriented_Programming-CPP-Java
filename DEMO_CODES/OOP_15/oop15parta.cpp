#include "oop15.cpp"
int main()
{
    std::vector <app> apps;
    read_apps(apps);
    for(auto itr=apps.begin();itr!=apps.end();itr++)
    {
        std::cout<<*itr<<std::endl;
    }
    return 0;
}