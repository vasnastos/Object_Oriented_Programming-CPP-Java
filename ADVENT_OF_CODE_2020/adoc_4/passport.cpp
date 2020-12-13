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

bool passport::present()
{
    int security_level=0;
    if(!this->validance()) return false;
    if(this->checksums[codes[0]].length()==4)
    {
       if(std::stoi(this->checksums[codes[0]])>=1920 && std::stoi(this->checksums[codes[0]])<=2002)
       {
            security_level++;
       }
    }
    if(this->checksums[codes[1]].length()==4)
    {
        if(std::stoi(this->checksums[codes[1]])>=2010  && std::stoi(this->checksums[codes[1]])<=2020)
        {
            security_level++;
        }
    }
    if(this->checksums[codes[2]].length()==4)
    {
        if(std::stoi(this->checksums[codes[1]])>=2020  && std::stoi(this->checksums[codes[1]])<=2030)
        {
            security_level++;
        }
    }
    std::string bridge=this->checksums[codes[3]].substr(this->checksums[codes[3]].length()-2,this->checksums[codes[3]].length()); 
    if(bridge=="cm")
    {
        if(std::stoi(this->checksums[codes[3]])>=150)
        {
            security_level++;
        }
    }
    else if(bridge=="in")
    {
        if(std::stoi(this->checksums[codes[3]]))
        {
            security_level++;
        }
    }
    //hair color
    //eye color
    //passport id
    //country id
}

std::ostream &operator<<(std::ostream &os, const passport &p)
{
    for (auto &x : p.checksums)
    {
        os << "Record[" << x.first << "]:" << x.second << std::endl;
    }
    return os;
}