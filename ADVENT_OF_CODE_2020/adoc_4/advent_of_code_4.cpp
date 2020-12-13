#include "readdata.hpp"

int main(int argc,char **argv)
{
    std::vector <passport> passports;
    read_data(passports);
    std::cout<<"Passport's loaded at the program!!!"<<std::endl;
    std::cout<<"================================================"<<std::endl;
    int i=1;
    int counter=0;
    bool valid;
    for(auto x:passports)
    {
        valid=x.validance();
        if(valid)
        {
            counter++;
        }
         std::cout<<std::boolalpha;
        std::cout<<"\tPassport "<<i<<" validates as:"<<valid<<std::endl;
        i++;
    }
    std::cout<<"================================================"<<std::endl;
    std::cout<<"Total passports validate:"<<passports.size()<<std::endl;
    std::cout<<"\tValidation complete---Total valid passports:"<<counter<<std::endl;
    return 0;
}
