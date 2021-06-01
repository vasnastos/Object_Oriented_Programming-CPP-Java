#include <iostream>
#include <vector>

void show(std::vector <int> &vec)
{
    for(int i=0;i<vec.size();i++)
    {
        std::cout<<vec[i]<<std::endl;
    }
}

int main()
{
    int a[2];
    std::vector <int> vec;//Δήλωση ενός αντικειμένου vector
    vec.push_back(2);//-->1a[0]==2
    std::cout<<"First:"<<vec.size()<<std::endl;
    vec.push_back(4);//a[1]==4//Εισαγωγή στοιχείου στο τέλος του vector
    std::cout<<"Second:"<<vec.size()<<std::endl;//vec.size()-->Επιστροφή του μεγέθους του vector.
    vec.push_back(8);
    std::cout<<vec[0]<<"-"<<vec[1]<<"-"<<vec.at(2)<<std::endl;
    show(vec);
    return 0;
}