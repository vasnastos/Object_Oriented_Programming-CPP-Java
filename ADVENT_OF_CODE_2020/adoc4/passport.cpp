#include "passport.hpp"
passport::passport()
{
}

void passport::add_data(std::string id, std::string value)
{
    bool triggered=false;
    for(int i=0;i<8;i++)
    {
        if(id==codes[i]) 
        {
            triggered=true;
           break;
        }
    }
    if(!triggered) return;
    if(value.empty())
    {
        value="-";
    }
    this->checksums[id] = value;
}

bool passport::validance()
{
    if (this->checksums.size()<7)
    {
        return false;
    }
    if(this->checksums.find("cid")!=this->checksums.end() && this->checksums.size()==7)
    {
        return false;
    }
    for(auto &y:this->checksums)
    {
        if(y.second=="-"  && y.first!="cid") return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const passport &p)
{
    for (auto &x : p.checksums)
    {
        os << "Record[" << x.first << "]:" << x.second << std::endl;
    }
    return os;
}