#include "Surfer.hpp"
#include <string>

int main(int argc,char **argv)
{
    if(argc!=2)
    {
        std::cerr<<"Invallid amount of arguments"<<std::endl;
        std::cout<<"Provide:a.exe number_of_pages"<<std::endl;
        exit(-10);
    }
    std::cout<<std::endl;
    int argument=std::stoi(argv[1]);
    Surfer s(argument,argument);
    s.random_surfer();
    s.Page_rank();
    return 0;
}