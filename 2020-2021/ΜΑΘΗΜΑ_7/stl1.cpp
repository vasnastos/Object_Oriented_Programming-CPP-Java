#include <iostream>
#include <vector>
#include <ctime>
#include <ostream>
#include <random>
#include <string>
#include <cmath>
#include <iterator>
#include <numeric>
#include <fstream>
#include <chrono>
#include <algorithm>

int globalcounter=1;

void fill_array(std::vector <int> &v)
{
    std::mt19937 mt(time(nullptr));
    std::uniform_int_distribution <int> dist(1,500);
    const int size=dist(mt);
    std::chrono::high_resolution_clock::time_point t1=std::chrono::high_resolution_clock::now();
    for(int i=0;i<size;i++)
    {
        v.push_back(dist(mt));
    }
    std::chrono::high_resolution_clock::time_point t2=std::chrono::high_resolution_clock::now();
    std::chrono::duration <double> dur=std::chrono::duration_cast<std::chrono::duration <double>>(t2-t1);
    std::cout<<"Data loaded after "<<dur.count()<<" ms"<<std::endl;
    globalcounter++;
}

void show(std::vector <int> &v)
{
    std::ostream_iterator <int> out(std::cout,"\n");
    std::cout<<"---------------------------------------------"<<std::endl;
    std::copy(v.begin(),v.end(),out);
    std::cout<<"---------------------------------------------"<<std::endl;
    std::fstream fs;
    fs.open("output_"+std::to_string(globalcounter)+".txt",std::ios::out);
    out=std::ostream_iterator <int>{fs,"\n"};
    std::copy(v.begin(),v.end(),out);
    fs.close();
}

int main()
{
    std::vector <int> vec;
    fill_array(vec);
    double average=(double)std::accumulate(vec.begin(),vec.end(),0)/vec.size();
    std::cout<<"Max element in board:"<<*std::max_element(vec.begin(),vec.end())<<std::endl;
    std::cout<<"Min element in board:"<<*std::min_element(vec.begin(),vec.end())<<std::endl;
    std::cout<<"sum of board:"<<std::accumulate(vec.begin(),vec.end(),0);
    std::cout<<"Average of board:"<<average<<std::endl;
    std::cout<<"Over average values:"<<std::count_if(vec.begin(),vec.end(),[average](const int &a) {return double(a)>average;});
    std::cout<<"Row Data"<<std::endl;
    show(vec);
    std::cout<<"After Sorting"<<std::endl;
    std::sort(vec.begin(),vec.end());
    show(vec);
    std::cout<<"======================================================"<<std::endl;
    std::cout<<"SQRT of the values"<<std::endl;
    std::for_each(vec.begin(),vec.end(),[](int a) {std::cout<<"SQRT(a):"<<sqrt(a)<<std::endl;});
    std::cout<<"======================================================"<<std::endl;
}