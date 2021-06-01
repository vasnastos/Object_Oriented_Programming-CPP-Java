#include <iostream>
#include <string>

size_t factorial(int number)
{
    if(number<=1)
    {
        return 1;
    }
    return number*factorial(number-1);
}

int main(int argc,char **argv)
{
   if(argc<2)
   {
       std::cerr<<"Invallid type of arguments"<<std::endl;
       return 0;
   }
   for(int i=1;i<argc;i++)
   {
       std::cout<<"Factorial("<<argv[i]<<"):"<<factorial(std::stoi(argv[i]))<<std::endl;
   }
   return 0;
}