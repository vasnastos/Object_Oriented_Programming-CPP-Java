#include <iostream>
#include <vector>

class player
{
    int raks;
    std::string name;
    size_t points;
    public:
    player(int r,std::string n,size_t rks):raks(r),name(n),points(rks) {}
    size_t totalpoints()const {return this->points*this->raks*0.5;}
    bool operator<(const player &p)const {return this->totalpoints()<p.totalpoints();}
    friend std::ostream &operator<<(std::ostream &os,const player &p)
    {
        os<<p.name<<"--"<<p.raks<<"::"<<p.points;
       return os;
    }
};

template <typename T>T min_element(std::vector <T> &collection)
{
    T min=collection.at(0);
    for(int i=0;i<collection.size();i++)
    {
        if(collection.at(i)<min)
        {
            min=collection.at(i);
        }
    }
    return min;
}

int main()
{
    std::vector <int> integers{4,7,1,78,3,45,6,7,21};
    std::vector <double> floats{6.78,4.32,2.18,6.78,4.31,6.7,8.9};
    std::vector <player> players{player{10,"nikos",1000},player{4,"vasilis",2300},player{3,"Maria",1500},player{6,"XD21WE",7000},player{7,"KJL98i",5000}};
    std::cout<<min_element(integers)<<std::endl;
    std::cout<<min_element(floats)<<std::endl;
    std::cout<<min_element(players)<<std::endl;
    return 0;
}